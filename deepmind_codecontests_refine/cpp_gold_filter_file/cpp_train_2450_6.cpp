#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 9;
const int L = 22;
const int MOD = 1000000007;
int n, tot, vout, pri[N], vis[N], sur[N], cnt[N][L];
int POW[N], REV[N], sum[N], pre1[N], pre2[N];
inline int read() {
  char c = getchar();
  int f = 1, ret = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return ret * f;
}
inline int C(int a, int b) {
  if (a > b || a < 0 || b < 0)
    return 0;
  else
    return ((long long)POW[b] * REV[a] % MOD) * REV[b - a] % MOD;
}
inline int pre_sum(int l, int r) {
  if (l > r) return 0;
  return (sum[r] - (l ? sum[l - 1] : 0)) % MOD;
}
inline int Pow(int w, int t) {
  int ret = 1;
  while (t) {
    if (t & 1) ret = (long long)ret * w % MOD;
    w = (long long)w * w % MOD;
    t >>= 1;
  }
  return ret;
}
inline void prework() {
  n = read();
  sur[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) pri[++tot] = i, sur[i] = tot;
    for (int j = 1; j <= tot && pri[j] * i < N; j++) {
      vis[i * pri[j]] = 1;
      sur[i * pri[j]] = j;
      if (i % pri[j] == 0) break;
    }
  }
  for (int i = 1; i <= tot; i++) cnt[i][0] = n;
  POW[0] = REV[0] = 1;
  for (int i = 1; i < N; i++) POW[i] = (long long)POW[i - 1] * i % MOD;
  REV[N - 1] = Pow(POW[N - 1], MOD - 2);
  for (int i = N - 2; i; i--) REV[i] = (long long)REV[i + 1] * (i + 1) % MOD;
  sum[0] = 1;
  for (int i = 1; i < N; i++) sum[i] = (sum[i - 1] + C(i, n - 1)) % MOD;
  for (int i = 1; i <= n; i++)
    pre1[i] = (pre_sum(n - i + 1, n - 1) - pre_sum(0, n - i - 1)) % MOD;
  for (int i = 1; i <= n; i++) pre2[i] = (pre2[i - 1] + pre1[i]) % MOD;
}
int main() {
  prework();
  for (int i = 1, w; i <= n; i++) {
    w = read();
    for (int j = sur[w], tmp; w > 1; j = sur[w]) {
      for (tmp = 0; w % pri[j] == 0; tmp++, w /= pri[j])
        ;
      cnt[j][tmp]++;
      cnt[j][0]--;
    }
  }
  for (int i = 1; i <= tot; i++) {
    if (cnt[i][0] < n) {
      for (int j = 0, l = 0, r = 0; j < L; j++) {
        if (cnt[i][j]) {
          r += cnt[i][j];
          (vout += (long long)(pre2[r] - pre2[l]) * j % MOD) %= MOD;
          l = r;
        }
      }
    }
  }
  printf("%d\n", (vout + MOD) % MOD);
  return 0;
}
