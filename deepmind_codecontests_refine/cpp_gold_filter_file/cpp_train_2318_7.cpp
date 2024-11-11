#include <bits/stdc++.h>
const int maxn = 1E+6 + 5;
const int maxk = 20;
const int INF = 0x3f3f3f3f;
int n, m, k, S1, S2;
int tim1[1 << maxk], tim2[1 << maxk];
int a[maxn], b[maxn], p[maxn][maxk];
inline void SWAP(int &S, int a, int b) {
  int x = S >> a & 1, y = S >> b & 1;
  if (x == y) return;
  S ^= (1 << a) | (1 << b);
}
inline void FMT(int *a, int N, const int &f(const int &, const int &)) {
  for (int i = 1; i < N; i <<= 1)
    for (int j = 0; j < N; ++j)
      if (j & i) a[j - i] = f(a[j - i], a[j]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int A = 0, B = 0;
  for (int i = 0, x; i < k; ++i) scanf("%1d", &x), S1 ^= x << i, A += x;
  for (int i = 0, x; i < k; ++i) scanf("%1d", &x), S2 ^= x << i, B += x;
  std::fill(tim1, tim1 + (1 << k), INF);
  std::fill(tim2, tim2 + (1 << k), -INF);
  tim1[S1] = n + 1, tim2[S2] = n + 1;
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]), --a[i], --b[i];
  for (int i = 0; i < k; ++i) p[n + 1][i] = i;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < k; ++j) {
      if (a[i] == j || b[i] == j)
        p[i][j] = p[i + 1][j ^ a[i] ^ b[i]];
      else
        p[i][j] = p[i + 1][j];
    }
    int cur = 0;
    for (int j = 0; j < k; ++j) cur ^= (S1 >> j & 1) << p[i][j];
    tim1[cur] = std::min(tim1[cur], i);
    cur = 0;
    for (int j = 0; j < k; ++j) cur ^= (S2 >> j & 1) << p[i][j];
    tim2[cur] = std::max(tim2[cur], i);
  }
  FMT(tim1, 1 << k, std::min<int>);
  FMT(tim2, 1 << k, std::max<int>);
  auto cnt = [](const int &x) -> int { return __builtin_popcount(x); };
  int ans = 0, ans1 = 1, ans2 = 1;
  for (int S = 0; S < (1 << k); ++S) {
    if (tim2[S] - tim1[S] >= m) {
      int res = 2 * cnt(S) - A - B + k;
      if (res > ans) ans = res, ans1 = tim1[S], ans2 = tim2[S] - 1;
    }
  }
  printf("%d\n%d %d\n", ans, ans1, ans2);
}
