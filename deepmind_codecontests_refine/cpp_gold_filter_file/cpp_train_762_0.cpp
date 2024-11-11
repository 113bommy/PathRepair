#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int f[1000009], g[1000009], par[1000009], pw[1000009], X[1000009];
char s[1000009];
int mod(long long x) {
  x %= 1000000007;
  if (x < 0) x += 1000000007;
  return x;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) par[i] = par[i - 1] + (s[i] == 'W');
  f[0] = g[n + 1] = g[n + 2] = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B') {
      f[i] = f[i - 1];
      if (i == k)
        f[i] = mod(f[i] - (par[i] == par[i - k]));
      else if (i - k - 1 >= 0 and s[i - k] != 'B')
        f[i] = mod(f[i] - mod(f[i - k - 1] * 1LL * (par[i] == par[i - k])));
    } else if (s[i] == 'W')
      f[i] = f[i - 1];
    else {
      f[i] = mod(2LL * f[i - 1]);
      if (i == k)
        f[i] = mod(f[i] - (par[i] == par[i - k]));
      else if (i - k - 1 >= 0 and s[i - k] != 'B')
        f[i] = mod(f[i] - mod(f[i - k - 1] * 1LL * (par[i] == par[i - k])));
    }
  }
  for (int i = n; i >= 1; i--) par[i] = par[i + 1] + (s[i] == 'B');
  for (int i = n; i >= 1; i--) {
    if (s[i] == 'W') {
      g[i] = g[i + 1];
      if (n - i + 1 == k)
        g[i] = mod(g[i] - (par[i] == par[i + k]));
      else if (i + k <= n and s[i + k] != 'W')
        g[i] = mod(g[i] - mod(g[i + k + 1] * 1LL * (par[i] == par[i + k])));
    } else if (s[i] == 'B')
      g[i] = g[i + 1];
    else {
      g[i] = mod(g[i + 1] + g[i + 1]);
      if (n - i + 1 == k)
        g[i] = mod(g[i] - (par[i] == par[i + k]));
      else if (i + k <= n and s[i + k] != 'W')
        g[i] = mod(g[i] - mod(g[i + k + 1] * 1LL * (par[i] == par[i + k])));
    }
  }
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = mod(pw[i - 1] + pw[i - 1]);
  int ans = 0;
  for (int i = 1; i <= n; i++) X[i] = X[i - 1] + (s[i] == 'X');
  for (int i = k; i <= n; i++)
    if (i + k <= n and par[i + k + 1] == par[i + 1] and s[i + k + 1] != 'W')
      ans = mod(ans + mod(mod(pw[X[i]] - f[i]) * 1LL * g[i + k + 2]));
  printf("%d\n", ans);
  return 0;
}
