#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3c3c3c3c;
const long long LINF = 1ll * INF * INF * 2;
const int MOD = 998244353;
const int N = 1010;
int n, m;
int x[N];
long long cnt[N][N];
long long ans[100100];
long long f(int k) {
  for (int i = 0; i < n; i++) cnt[i][1] = 1;
  for (int i = n - 2; i >= 0; i--)
    cnt[i][1] = (cnt[i][1] + cnt[i + 1][1]) % MOD;
  for (int t = 2; t <= m; t++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      while (cur <= i || (cur < n && x[cur] < x[i] + k)) cur++;
      cnt[i][t] = cnt[cur][t - 1];
    }
    for (int i = n - 2; i >= 0; i--)
      cnt[i][t] = (cnt[i][t] + cnt[i + 1][t]) % MOD;
  }
  return cnt[0][m];
}
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", x + i);
  sort(x, x + n);
  int M = 100000 / (m - 1);
  for (int k = 0; k <= M; k++) ans[k] = f(k);
  long long sum = 0;
  for (int k = 0; k <= M; k++) sum = (sum + k * (ans[k] - ans[k + 1])) % MOD;
  printf("%lld", (sum % MOD + MOD) % MOD);
}
