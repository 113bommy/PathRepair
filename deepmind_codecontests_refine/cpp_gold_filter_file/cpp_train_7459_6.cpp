#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
const int H = 37;
const int P = 1000000007;
int k, n, m;
int pos;
int f[N], g[N];
int hs[N], ht[N], p[N];
int x, y, lst, fst;
char s[N], t[N];
bool Check(int l, int r, int L, int R) {
  int t = (hs[r] - 1ll * hs[l - 1] * p[r - l + 1]) % P;
  t = (t + P) % P;
  int T = (ht[R] - 1ll * ht[L - 1] * p[R - L + 1]) % P;
  T = (T + P) % P;
  return t == T;
}
bool Solve() {
  pos = 1;
  for (int i = 1; i <= m; i++) {
    while (pos < i) ++pos;
    while (pos <= n) {
      if (Check(pos - i + 1, pos, 1, i)) break;
      ++pos;
    }
  }
  if (max(pos, k) + k <= n) {
    printf("Yes\n%d %d\n", max(1, pos - k + 1), max(pos, k) + 1);
    return 1;
  }
  pos = n;
  for (int i = m; i; i--) {
    while (pos + m - i > n) --pos;
    while (pos) {
      if (Check(pos, pos + m - i, i, m)) break;
      --pos;
    }
  }
  if (n - max(n - pos + 1, k) - k > 0) {
    printf("Yes\n%d %d\n", n - max(n - pos + 1, k) - k,
           n - max(n - pos + 1, k) + 1);
    return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s + 1, t + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = 1ll * p[i - 1] * H % P;
  for (int i = 1; i <= n; i++) hs[i] = (1ll * hs[i - 1] * H + s[i] - 'a') % P;
  for (int i = 1; i <= m; i++) ht[i] = (1ll * ht[i - 1] * H + t[i] - 'a') % P;
  if (m <= k && Solve()) return 0;
  pos = k;
  lst = fst = 1;
  for (int i = 1; i <= m && i <= k; i++)
    if (Check(k - i + 1, k, 1, i)) {
      lst = i;
      if (fst != 1) fst = i;
      f[i] = k;
    }
  for (int i = 1; i < fst; i++) {
    while (pos < i) ++pos;
    while (pos <= n) {
      if (Check(pos - i + 1, pos, 1, i)) break;
      ++pos;
    }
    f[i] = pos <= n ? pos : 0;
  }
  pos = k;
  for (int i = lst + 1; i <= m && i <= k; i++) {
    while (pos < i) ++pos;
    while (pos <= n) {
      if (Check(pos - i + 1, pos, 1, i)) break;
      ++pos;
    }
    f[i] = pos <= n ? pos : 0;
  }
  pos = n - k + 1;
  lst = fst = m;
  for (int i = m; i && i >= m - k + 1; i--)
    if (Check(n - k + 1, n - k + 1 + m - i, i, m)) {
      lst = i;
      if (fst != m) fst = i;
      g[i] = n - k + 1;
    }
  for (int i = m; i > fst; i--) {
    while (pos + m - i > n) --pos;
    while (pos) {
      if (Check(pos, pos + m - i, i, m)) break;
      --pos;
    }
    g[i] = pos;
  }
  pos = n - k + 1;
  for (int i = lst - 1; i && i >= m - k + 1; i--) {
    while (pos + m - i > n) --pos;
    while (pos) {
      if (Check(pos, pos + m - i, i, m)) break;
      --pos;
    }
    g[i] = pos;
  }
  for (int i = 1; i < m; i++)
    if (f[i] && g[i + 1] && f[i] < g[i + 1]) {
      x = f[i] - k + 1;
      y = g[i + 1];
      break;
    }
  if (x)
    printf("Yes\n%d %d\n", x, y);
  else
    puts("No");
  return 0;
}
