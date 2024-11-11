#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
const long long MOD = 1000000007;
int N, K;
long long f[MAXN], g[MAXN], P[MAXN], sum, cnt, ans;
char ch[MAXN];
int main() {
  scanf("%d%d", &N, &K);
  scanf("%s", ch + 1);
  memset(f, 0, sizeof(f));
  sum = 1;
  cnt = 0;
  P[N + 1] = 1;
  f[0] = 1;
  for (int i = N; i >= 1; i--) P[i] = (1 + (ch[i] == 'X')) * P[i + 1] % MOD;
  for (int i = 1; i <= N; i++) {
    if (ch[i] == 'B') cnt++;
    if (ch[i] == 'W') {
      cnt = 0;
      f[i] = sum % MOD;
    }
    if (ch[i] == 'X') {
      cnt++;
      f[i] = sum % MOD;
      sum = sum * 2 % MOD;
    }
    if (cnt == K) {
      g[i] = f[i - K];
      sum = (sum - f[i - K]) % MOD;
      cnt--;
    }
  }
  memset(f, 0, sizeof(f));
  sum = 0;
  cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (ch[i] == 'W') cnt++;
    if (ch[i] == 'B') {
      cnt = 0;
      f[i] = sum % MOD;
    }
    if (ch[i] == 'X') {
      cnt++;
      f[i] = sum % MOD;
      sum = sum * 2 % MOD;
    }
    if (cnt == K) {
      ans = (ans + f[i - K] * P[i + 1] % MOD) % MOD;
      sum = (sum - f[i - K]) % MOD;
      cnt--;
    }
    f[i] = (f[i] + g[i]) % MOD;
    sum = (sum + g[i]) % MOD;
  }
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
  return 0;
}
