#include <bits/stdc++.h>
using namespace std;
long long fact[1000005], inv[1000005], fiv[1000005], pri[1000005], two[1000005],
    mark[1000005] = {0};
int cnt;
const long long MOD = 1e9 + 7;
void init() {
  fact[0] = fact[1] = 1;
  fiv[0] = fiv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < 1000004; ++i) {
    fact[i] = (1LL * fact[i - 1] * i) % MOD;
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    fiv[i] = (1LL * inv[i] * fiv[i - 1]) % MOD;
  }
  cnt = 0;
  mark[0] = mark[1] = 1;
  for (int i = 2; i < 1005; i++) {
    if (!mark[i]) pri[cnt++] = mark[i] = i;
    for (int j = 0; pri[j] * i < 1000004; j++) {
      mark[i * pri[j]] = pri[j];
      if (i % pri[j] == 0) break;
    }
  }
  two[0] = 1;
  for (int i = 1; i < 1000004; i++) two[i] = (2LL * two[i - 1]) % MOD;
}
int main() {
  ios::sync_with_stdio(false);
  init();
  int q, n, m;
  cin >> q;
  while (q--) {
    cin >> n >> m;
    vector<int> num;
    long long ans = 1;
    for (int i = 0; i < cnt; i++) {
      if (n == 1) break;
      if (n % pri[i] == 0)
        num.push_back(0);
      else
        continue;
      while (n % pri[i] == 0) {
        n /= pri[i];
        num[num.size() - 1]++;
      }
    }
    if (n != 1) num.push_back(1);
    int s = num.size();
    for (int i = 0; i < s; i++) {
      ans = (ans * ((fiv[m - 1] * fiv[num[i]]) % MOD)) % MOD;
      ans = (ans * fact[num[i] + m - 1]) % MOD;
    }
    ans = (ans * two[m - 1]) % MOD;
    cout << ans << endl;
  }
  return 0;
}
