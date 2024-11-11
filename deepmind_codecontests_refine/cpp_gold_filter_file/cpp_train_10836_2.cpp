#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000010;
const long long MOD = 998244353;
long long N;
long long a[MAXN] = {0};
long long sum = 0;
long long ans = 0;
long long tmp = {0};
long long two[MAXN] = {0};
void prepare() {
  cin >> N;
  for (long long i = 1; i <= N; i++) scanf("%I64d", &a[i]);
  two[0] = 1;
  for (long long i = 1; i <= N; i++) two[i] = (two[i - 1] * 2) % MOD;
  for (long long i = 1; i <= N; i++) {
    tmp = sum + a[i];
    ans += tmp * two[N - i];
    ans %= MOD;
    sum *= 2;
    sum += a[i];
    sum %= MOD;
  }
  cout << ans;
}
void solve() {}
signed main() {
  prepare();
  solve();
  return 0;
}
