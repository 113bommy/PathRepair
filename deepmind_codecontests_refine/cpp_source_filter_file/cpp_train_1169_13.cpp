#include <bits/stdc++.h>
using std::cerr;
using std::endl;
const int N = 60, P = 998244353;
inline long long fpow(long long x, int y) {
  if (y < 0) return fpow(fpow(x, -y), P - 2);
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % P)
    if (y & 1) ret = ret * x % P;
  return ret;
}
int n, m, rank;
long long C[N][N];
long long lb[N], nlb[N];
long long p[N];
inline void insert(long long x) {
  for (int i = m; ~i; --i) {
    if (x & (1 << i)) {
      if (!lb[i]) {
        lb[i] = x;
        break;
      } else
        x ^= lb[i];
    }
  }
}
void dfs(long long s, int pos) {
  if (pos == rank)
    ++p[__builtin_popcountll(s)];
  else {
    dfs(s, pos + 1);
    dfs(s ^ lb[pos], pos + 1);
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    long long x;
    std::cin >> x;
    insert(x);
  }
  for (int i = 0; i < m; ++i) {
    if (!lb[i]) continue;
    for (int j = 0; j < i; ++j)
      if (lb[i] & (1 << j)) lb[i] ^= lb[j];
    for (int j = 0; j < m; ++j)
      if (!lb[j]) nlb[rank] = (nlb[rank] << 1) | ((lb[i] >> j) & 1);
    nlb[rank] |= 1ll << (m - rank - 1);
    ++rank;
  }
  for (int i = 0; i < rank; ++i) lb[i] = nlb[i], nlb[i] = 0;
  for (int i = rank; i < N; ++i) lb[i] = 0, nlb[i] = 0;
  if (rank <= 26) {
    dfs(0, 0);
    for (int i = 0; i <= m; ++i) {
      long long ans = p[i] * fpow(2, n - rank) % P;
      std::cout << ans << " ";
    }
  } else {
    rank = m - rank;
    for (int i = 0; i < rank; ++i) {
      for (int j = 0; j < m - rank; ++j)
        if (lb[j] & (1 << i)) nlb[i] |= 1ll << j;
      nlb[i] |= 1ll << (m - i - 1);
    }
    std::swap(lb, nlb);
    dfs(0, 0);
    for (int i = C[0][0] = C[1][0] = 1; i + 1 < N; ++i, C[i][0] = 1)
      for (int j = 1; j <= i; ++j)
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    for (int i = 0; i <= m; ++i) {
      long long ans = 0;
      for (int j = 0; j <= m; ++j) {
        long long tmp = 0;
        for (int k = 0; k <= i; ++k)
          tmp = (tmp + (k & 1 ? P - 1 : 1) * C[j][k] % P * C[m - j][i - k]) % P;
        ans = (ans + tmp * p[j]) % P;
      }
      ans = ans * fpow(2, n - m) % P;
      std::cout << ans << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}
