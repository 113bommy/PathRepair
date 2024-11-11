#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int stars, pac, n, nxtPac[maxn], x, pre[maxn];
char s[maxn];
bool f[maxn];
inline void solve1() {
  int a = 0, b = 0, c = 0, d = 0;
  for (int i = x - 1; i >= 1; --i)
    if (s[i] == '*') ++a, b = x - i;
  for (int i = x + 1; i <= n; ++i)
    if (s[i] == '*') ++c, d = i - x;
  if (a > c)
    cout << a << " " << b;
  else if (c > a)
    cout << c << " " << d;
  else if (b < d)
    cout << a << " " << b;
  else
    cout << c << " " << d;
}
inline bool check(int m) {
  memset(f, 0, sizeof f);
  f[1] = true;
  for (int i = 1; i <= n; ++i)
    if (f[i]) {
      if (s[i] == '.')
        f[i + 1] = true;
      else if (s[i] == 'P')
        f[min(i + m + 1, nxtPac[i + 1])] = true;
      else {
        int x = nxtPac[i], y = nxtPac[x + 1];
        if (y != n + 1) {
          if (pre[y] - pre[x] > 0) {
            if (i + m >= y) {
              f[min(x + m + 1, nxtPac[y + 1])] = true;
              f[x + 1] = true;
              continue;
            }
          }
        }
        if (x == n + 1 || i + m < x) continue;
        f[x + 1] = true;
      }
    }
  return f[n + 1];
}
inline void solve2() {
  int l = 12, r = 12, res = maxn;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (check(m)) {
      res = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  cout << stars << " " << res;
}
int main() {
  scanf("%d%s", &n, s + 1);
  nxtPac[n + 1] = n + 1;
  for (int i = n; i >= 1; --i) {
    if (s[i] == '*')
      ++stars;
    else if (s[i] == 'P')
      ++pac, x = i;
    nxtPac[i] = (s[i] == 'P') ? i : nxtPac[i + 1];
  }
  for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + (s[i] == '*');
  if (pac == 1)
    solve1();
  else
    solve2();
  return 0;
}
