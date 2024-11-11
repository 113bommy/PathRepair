#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
const int maxn = 1e5 + 5, maxs = 320;
int N, M, K, B, W, T, L[maxn], R[maxn];
vector<int> G[maxn];
long long d[maxn];
double slp(int x, int y) { return (1.0 * d[x] - d[y]) / (y - x); }
struct Block {
  int q[maxs], l, r, coef;
  void build(int x) {
    l = 0, r = -1;
    for (int i = L[x]; i <= R[x]; ++i) {
      while (r - l > 0 && slp(q[r - 1], q[r]) > slp(q[r], i)) --r;
      q[++r] = i;
    }
  }
  long long Get() {
    if (l > r) return 0;
    while (r - l > 0 && slp(q[l], q[l + 1]) < coef) ++l;
    return d[q[l]] + 1LL * q[l] * coef;
  }
} s[maxs];
int main() {
  N = read(), W = read();
  for (int i = 1, a, b; i <= N; ++i) {
    a = read(), b = read();
    G[b].push_back(a);
    K = max(K, b + 1);
    M = max(M, a);
  }
  B = sqrt(M);
  T = (M - 1) / B + 1;
  for (int i = 1; i <= T; ++i) L[i] = (i - 1) * B + 1, R[i] = min(i * B, M);
  for (int i = 1; i <= T; ++i) s[i].build(i);
  for (int k = 0; k <= K; ++k) {
    if (k)
      for (int i = 0, p; i < G[k - 1].size(); ++i) {
        --N;
        p = G[k - 1][i];
        for (int j = 1; j <= p / B; ++j) ++s[j].coef;
        for (int j = p / B * B + 1; j <= p; ++j) d[j] += j;
        s[p / B + 1].build(p / B + 1);
      }
    int ret = 1;
    for (int i = 1; i <= T; ++i)
      if (s[ret].Get() < s[i].Get()) ret = i;
    printf("%lld %d\n", 1LL * k * N * W + s[ret].Get(), s[ret].q[s[ret].l]);
  }
  return 0;
}
