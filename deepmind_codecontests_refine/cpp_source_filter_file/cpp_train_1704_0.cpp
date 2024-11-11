#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
inline string IntToString(int a) {
  char x[100];
  sprintf(x, "%d", a);
  string s = x;
  return s;
}
inline int StringToInt(string a) {
  char x[100];
  int res;
  strcpy(x, a.c_str());
  sscanf(x, "%d", &res);
  return res;
}
inline string GetString(void) {
  char x[1000005];
  scanf("%s", x);
  string s = x;
  return s;
}
inline string uppercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
inline string lowercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
inline void OPEN(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
long long jum[1000005];
int bit[1000005][35];
int prop[1000005];
int data[100005];
int n, q, a, b, c, d;
void build(int ix, int x, int y) {
  if (x == y) {
    jum[ix] = data[x];
    for (int(i) = (0); (i) < (30); ++(i))
      bit[ix][i] = ((data[x] & (1 << i)) ? 1 : 0);
    return;
  }
  int m = (x + y) >> 1;
  build(ix * 2 + 1, x, m);
  build(ix * 2 + 2, m + 1, y);
  jum[ix] = jum[ix * 2 + 1] + jum[ix * 2 + 2];
  for (int(i) = (0); (i) < (30); ++(i))
    bit[ix][i] = bit[ix * 2 + 1][i] + bit[ix * 2 + 2][i];
  return;
}
void update(int ix, int x, int y, int L, int R, int k) {
  if (x >= L && y <= R) {
    prop[ix] ^= k;
  }
  int len = y - x + 1;
  for (int(i) = (0); (i) < (30); ++(i)) {
    if (prop[ix] & (1 << i)) {
      jum[ix] -= ((long long)bit[ix][i] * (long long)(1 << i));
      jum[ix] += ((long long)(len - bit[ix][i]) * (long long)(1 << i));
      bit[ix][i] = len - bit[ix][i];
    }
  }
  int m = (x + y) >> 1;
  prop[ix * 2 + 1] ^= prop[ix];
  prop[ix * 2 + 2] ^= prop[ix];
  prop[ix] = 0;
  if (y < L || x > R) return;
  if (x >= L && y <= R) return;
  update(ix * 2 + 1, x, m, L, R, k);
  update(ix * 2 + 2, m + 1, y, L, R, k);
  jum[ix] = jum[ix * 2 + 1] + jum[ix * 2 + 2];
  for (int(i) = (0); (i) < (30); ++(i))
    bit[ix][i] = bit[ix * 2 + 1][i] + bit[ix * 2 + 2][i];
}
long long query(int ix, int x, int y, int L, int R) {
  int len = y - x + 1;
  for (int(i) = (0); (i) < (30); ++(i)) {
    if (prop[ix] & (1 << i)) {
      jum[ix] -= ((long long)bit[ix][i] * (long long)(1 << i));
      jum[ix] += ((long long)(len - bit[ix][i]) * (long long)(1 << i));
      bit[ix][i] = len - bit[ix][i];
    }
  }
  prop[ix * 2 + 1] ^= prop[ix];
  prop[ix * 2 + 2] ^= prop[ix];
  prop[ix] = 0;
  if (y < L || x > R) return 0;
  if (x >= L && y <= R) return jum[ix];
  int m = (x + y) >> 1;
  long long res =
      query(ix * 2 + 1, x, m, L, R) + query(ix * 2 + 2, m + 1, y, L, R);
  jum[ix] = jum[ix * 2 + 1] + jum[ix * 2 + 2];
  for (int(i) = (0); (i) < (30); ++(i))
    bit[ix][i] = bit[ix * 2 + 1][i] + bit[ix * 2 + 2][i];
  prop[ix] = 0;
  return res;
}
int main() {
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); ++(i)) scanf("%d", &data[i]);
  scanf("%d", &q);
  build(0, 0, n - 1);
  while (q--) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d %d", &b, &c);
      long long risan = query(0, 0, n - 1, b - 1, c - 1);
      printf("%lld\n", risan);
    } else {
      scanf("%d %d %d", &b, &c, &d);
      update(0, 0, n - 1, b - 1, c - 1, d);
    }
  }
  return 0;
}
