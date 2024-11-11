#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 2034567891;
const long long LL_INF = 1234567890123456789ll;
long long fact[2050];
bool chk[2050];
long long comb[2050][2050];
int main() {
  int N, i, j, t, cnt1 = 0, cnt2 = 0;
  comb[0][0] = 1;
  for (i = 1; i <= 2000; i++) {
    comb[i][0] = comb[i][i] = 1;
    for (j = 1; j < i; j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
  }
  fact[0] = 1;
  for (i = 1; i <= 2000; i++) fact[i] = (fact[i - 1] * i) % MOD;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%d", &t);
    if (t == -1)
      cnt1++;
    else {
      chk[i] = true;
      chk[t] = true;
    }
  }
  for (i = 1; i <= N; i++)
    if (!chk[i]) cnt2++;
  long long ans = 0, tmp;
  for (i = 0; i < N; i++) {
    tmp = (fact[cnt1 - i] * comb[cnt2][i]) % MOD;
    if (i % 2 == 0)
      ans += tmp;
    else
      ans += MOD - tmp;
    ans %= MOD;
  }
  printf("%I64d", ans);
  return 0;
}
