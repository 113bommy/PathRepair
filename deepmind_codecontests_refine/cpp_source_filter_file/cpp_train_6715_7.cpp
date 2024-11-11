#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6;
const long long M = 20;
const long long SQRT = 350;
const long long INF = 1e16;
const long long MOD = 1e9 + 7;
long long n, l, k, a[N], c[N], tmp[N], p[N], dp[N];
vector<long long> b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b.push_back(a[i]);
    tmp[i] = a[i];
  }
  sort(a, a + n);
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  int s = b.size();
  for (int i = 0; i < s; i++)
    c[i] = upper_bound(a, a + n, b[i]) - lower_bound(a, a + n, b[i]);
  for (int i = 0; i < s; i++) dp[i] = c[i];
  long long ans = l % MOD;
  for (int i = 2; i <= min(k, l / n + 1); i++) {
    p[0] = dp[0];
    for (int j = 1; j < s; j++) {
      p[j] = (p[j - 1] + dp[j]) % MOD;
    }
    for (int j = 0; j < s; j++) {
      dp[j] = p[j] * c[j] % MOD;
    }
    for (int j = 0; j < l % n; j++) {
      long long pos = lower_bound(b.begin(), b.end(), tmp[j]) - b.begin();
      ans = (ans + dp[pos]) % MOD;
    }
    for (int j = 0; j < s; j++)
      ans = (ans + dp[j] * ((l / n - (i - 1)) % MOD) % MOD) % MOD;
  }
  cout << ans << endl;
  return 0;
}
