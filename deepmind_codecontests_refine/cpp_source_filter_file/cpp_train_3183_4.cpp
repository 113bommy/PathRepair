#include <bits/stdc++.h>
using namespace std;
template <typename T>
void r1(T& x) {
  x = 0;
  char c(getchar());
  int f(1);
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = (x * 10) + (c ^ 48);
  x *= f;
}
template <typename T, typename... Args>
inline void r1(T& t, Args&... args) {
  r1(t);
  r1(args...);
}
const int maxn = 1e3 + 5;
const int maxm = (1 << 8) + 5;
vector<int> p[10];
int n, a[maxn];
int f[maxn][maxm], hd[10];
int check(int x) {
  memset(f, -1, sizeof(f));
  memset(hd, 0, sizeof(hd));
  f[0][0] = 0;
  int z(1 << 8);
  --z;
  for (int i = 0; i < n; ++i) {
    for (int S = 0; S <= z; ++S)
      if (f[i][S] != -1) {
        for (int k = 1; k <= 8; ++k)
          if (!((S >> (k - 1)) & 1)) {
            int c = hd[k] + x - 1;
            if ((unsigned)c >= p[k].size()) continue;
            f[p[k][c]][S | (1 << (k - 1))] =
                max(f[p[k][c]][S | (1 << (k - 1))], f[i][S]);
            ++c;
            if ((unsigned)c >= p[k].size()) continue;
            f[p[k][c]][S | (1 << (k - 1))] =
                max(f[p[k][c]][S | (1 << (k - 1))], f[i][S] + 1);
          }
      }
    ++hd[a[i]];
  }
  int res(-1);
  for (int i = 0; i < n; ++i) res = max(res, f[i][z]);
  if (res == -1) return -1;
  return res * (x + 1) + (8 - res) * x;
}
signed main() {
  int i, j;
  r1(n);
  for (i = 0; i < n; ++i) {
    r1(a[i]);
    p[a[i]].push_back(i);
  }
  int l(1), r(n / 8), mid;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  int ans = max(check(l), check(r));
  if (ans == -1) {
    ans = 0;
    for (i = 1; i <= 8; ++i)
      if (p[i].size()) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
