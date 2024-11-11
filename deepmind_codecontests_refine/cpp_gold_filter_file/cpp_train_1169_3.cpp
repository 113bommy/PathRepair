#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
const int mod = 998244353;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int dec(int a, int b) {
  if ((a -= b) < 0) a += mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
inline int power(int a, int b) {
  int out = 1;
  while (b) {
    if (b & 1) out = mult(out, a);
    a = mult(a, a);
    b >>= 1;
  }
  return out;
}
int n, m;
long long a[200010];
class linear_base {
 public:
  long long dat[40];
  int id[40], S[40];
  vector<int> pos;
  int insert(long long x) {
    for (int i = m - 1; i >= 0; i--) {
      if ((x >> i) & 1) {
        if (!dat[i]) {
          dat[i] = x;
          pos.push_back(i);
          return 1;
        }
        x ^= dat[i];
      }
    }
    return 0;
  }
  void regulate() {
    for (int i = m - 1; i >= 0; i--) {
      for (int j = i - 1; j >= 0; j--) {
        if (dat[j] && ((dat[i] >> j) & 1)) dat[i] ^= dat[j];
      }
    }
    int idcnt = 0;
    for (int i = 0; i < m; i++)
      if (!dat[i]) id[i] = idcnt++;
    for (int i = m - 1; i >= 0; i--) {
      if (dat[i])
        for (int j = i - 1; j >= 0; j--)
          if (!dat[j] && ((dat[i] >> j) & 1)) S[i] |= (1 << id[j]);
    }
  }
} L;
int b[200010], cnt[50], dp[40][40][32768];
int main() {
  scanf("%d%d", &n, &m);
  int K = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) K += (b[i] = L.insert(a[i]));
  if (K <= 19) {
    int ans = 0;
    for (int i = 0; i < (1 << K); i++) {
      long long cur = 0;
      for (int j = 0; j < K; j++)
        if ((i >> j) & 1) cur ^= L.dat[L.pos[j]];
      cnt[__builtin_popcountll(cur)]++;
    }
  } else {
    L.regulate();
    dp[0][0][0] = 1;
    for (int i = 1; i <= L.pos.size(); i++) {
      int vl = L.pos[i - 1];
      for (int j = 0; j < i; j++) {
        for (int k = 0; k < (1 << (m - K)); k++) {
          dp[i][j][k] = add(dp[i][j][k], dp[i - 1][j][k]);
          dp[i][j + 1][k ^ L.S[vl]] =
              add(dp[i][j + 1][k ^ L.S[vl]], dp[i - 1][j][k]);
        }
      }
    }
    for (int i = 0; i < (1 << (m - K)); i++) {
      int c = __builtin_popcount(i);
      for (int j = 0; j <= K; j++) {
        cnt[c + j] = add(cnt[c + j], dp[L.pos.size()][j][i]);
      }
    }
  }
  for (int i = 0; i <= m; i++) printf("%d ", mult(cnt[i], power(2, n - K)));
  return 0;
}
