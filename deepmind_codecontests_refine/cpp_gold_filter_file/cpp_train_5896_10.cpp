#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int P = 1e9 + 7;
const int inf = 1e9;
const long long Inf = 1e15;
inline int IN() {
  char ch = getchar();
  int x = 0, f = 0;
  while (ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - 48;
    ch = getchar();
  }
  return f ? (-x) : x;
}
inline int Pow(int x, int y, int p) {
  int an = 1;
  for (; y; y >>= 1, x = (long long)x * x % p)
    if (y & 1) an = (long long)an * x % p;
  return an;
}
void renew(int &x, int y) {
  x += y;
  if (x < 0)
    x += P;
  else if (x >= P)
    x -= P;
}
void setIO(string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}
template <typename T>
inline void chkmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <typename T>
inline void chkmax(T &a, const T &b) {
  if (a < b) a = b;
}
int n, fa[N], tg[N];
int main() {
  scanf("%d", &n);
  for (int i = (int)1; i <= (int)n; i++) scanf("%d", fa + i);
  int ans = 0;
  for (int i = (int)n; i >= (int)1; i--)
    if (!tg[i]) {
      ans++;
      for (int x = i; x; x = fa[x]) tg[x] = 1;
    }
  printf("%d\n", ans);
  return 0;
}
