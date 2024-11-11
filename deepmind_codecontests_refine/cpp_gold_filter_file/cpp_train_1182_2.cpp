#include <bits/stdc++.h>
using namespace std;
const int inf = 0x20202020;
const int mod = 1000000007;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
template <class T>
inline void read(T& x, T& y, T& z, T& q) {
  read(x);
  read(y);
  read(z);
  read(q);
}
const int DX[] = {1, 0, -1, 0}, DY[] = {0, 1, 0, -1};
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 2111111, M = 111111;
int m, n, t, C, l[N], r[N], ini[N], num[N][10];
char s[N];
void del(int x) {
  r[l[x]] = r[x];
  l[r[x]] = l[x];
}
vector<int> vec[N];
int find(int x, int p) {
  int l = 0, r = ((int)(vec[x]).size()) - 1;
  while (l < r) {
    int mid = l + r >> 1;
    if (vec[x][mid] < p)
      l = mid + 1;
    else
      r = mid;
  }
  return vec[x][l];
}
int calc(int l, int r) {
  return min(find(ini[l], vec[l][0]), find(r + 1, vec[l][0]));
}
int main() {
  scanf("%d%d", &n, &C);
  scanf("%s", s + 1);
  for (int _tmp = n + 1, i = 0; i <= _tmp; ++i) l[i] = i - 1, r[i] = i + 1;
  int pt = 1, dir = 1, lst = 0, time = 0;
  for (int _tmp = n, i = 1; i <= _tmp; ++i) ini[i] = -1;
  while (1) {
    time++;
    for (int _tmp = 9, i = 0; i <= _tmp; ++i) num[time][i] = num[time - 1][i];
    if (ini[pt] == -1) ini[pt] = l[pt];
    vec[pt].push_back(time);
    if (pt == 0 || pt == n + 1) {
      pt = r[0], lst = 0, dir = 1;
      continue;
    }
    if (s[pt] >= '0' && s[pt] <= '9') {
      num[time][s[pt] - '0']++;
      s[pt]--;
      if (s[pt] == '0' - 1)
        del(pt);
      else
        lst = pt;
      if (dir)
        pt = r[pt];
      else
        pt = l[pt];
    } else {
      if (s[pt] == '<') dir = 0;
      if (s[pt] == '>') dir = 1;
      int tmp = lst;
      lst = pt;
      if (dir)
        pt = r[pt];
      else
        pt = l[pt];
      if (s[pt] == '<' || s[pt] == '>' || pt == 0 || pt == n + 1)
        del(lst), lst = tmp;
    }
    if (r[0] == n + 1 || l[n + 1] == 0) break;
  }
  vec[pt].push_back(++time);
  for (int _tmp = n + 1, i = 0; i <= _tmp; ++i) vec[i].push_back(inf);
  for (int _tmp = C, _ = 1; _ <= _tmp; ++_) {
    int x, y;
    scanf("%d%d", &x, &y);
    int tmp = calc(x, y) - 1;
    for (int _tmp = 8, i = 0; i <= _tmp; ++i)
      printf("%d ", num[tmp][i] - num[vec[x][0] - 1][i]);
    printf("%d\n", num[tmp][9] - num[vec[x][0] - 1][9]);
  }
  return 0;
}
