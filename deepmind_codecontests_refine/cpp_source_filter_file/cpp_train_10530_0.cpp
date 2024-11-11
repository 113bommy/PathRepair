#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, K, S, cnt[1 << 4];
struct Mat {
  int s[225][225];
  Mat() { memset(s, 0, sizeof s); }
  Mat operator*(const Mat &B) {
    Mat ret;
    for (int k = S * (K + 1) - 1; k >= 0; k--)
      for (int i = S * (K + 1) - 1; i >= 0; i--)
        if (s[i][k])
          for (int j = S * (K + 1) - 1; j >= 0; j--)
            if (B.s[k][j])
              ret.s[i][j] = (ret.s[i][j] + 1ll * s[i][k] * B.s[k][j]) % mod;
    return ret;
  }
} f, g;
int main() {
  scanf("%d%d%d", &n, &K, &m), S = (1 << m);
  f.s[0][0] = 1;
  for (int i = 0; i < S; i++) cnt[i] = cnt[i >> 1] + (i & 1);
  for (int i = 0; i <= K; i++)
    for (int j = 0; j < S; j++) {
      g.s[i * S + j][i * S + ((j << 1) & (S - 1))]++;
      if (i < K)
        g.s[i * S + j][(i + 1) * S + ((j << 1 | 1) & (S - 1))] += cnt[j] + 1;
    }
  for (; n; n >>= 1, g = g * g)
    if (n & 1) f = f * g;
  int ans = 0;
  for (int i = 0; i < S; i++) ans = (ans + f.s[0][K * S + i]);
  printf("%d\n", ans);
}
