#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 200 + 2;
const int maxn = 1e5 + 2;
const int maxS = 1e6 + 2;
const int INF = 0x3f3f3f3f;
long long qmod(long long a, long long b) {
  long long res = 1;
  if (a >= MOD) a %= MOD;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
long long invmod[50];
long long C(long long n, long long m) {
  if (n < m) return 0;
  long long ans = 1;
  for (int i = 1; i <= m; ++i)
    ans = (n - i + 1) % MOD * ans % MOD * invmod[i] % MOD;
  return ans;
}
long long f[30], n, s;
long long ans;
void Calc(int cur, long long sum, int flag) {
  if (sum > s) return;
  if (cur == n) {
    ans += flag * C(s - sum + n - 1, n - 1);
    ans %= MOD;
    return;
  }
  Calc(cur + 1, sum, flag);
  Calc(cur + 1, sum + f[cur] + 1, -flag);
}
void Read_INP() {
  scanf("%d%lld", &n, &s);
  for (int i = 1; i <= 20; ++i) invmod[i] = qmod(i, MOD - 2);
  for (int i = (1); i <= (n); ++i) scanf("%lld", &f[i]);
  ans = 0;
  Calc(1, 0, 1);
  cout << (ans % MOD + MOD) % MOD << endl;
}
int main() {
  Read_INP();
  return 0;
}
