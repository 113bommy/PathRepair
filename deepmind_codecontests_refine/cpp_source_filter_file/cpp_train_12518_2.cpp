#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 3;
const long long MOD = 1e9 + 7;
long long k[MAX], a[MAX];
long long n, p;
long long bigmod(long long x, long long p) {
  long long ret = 1LL;
  while (p) {
    if (p & 1) ret = (ret * x) % MOD;
    x = (x * x) % MOD;
    p >>= 1;
  }
  return ret;
}
long long Get(int strt) {
  if (strt > n) return 0;
  long long sum1 = a[strt], sum2 = 0;
  if (strt == n) return sum1;
  if (k[strt] == k[strt + 1]) return Get(strt + 2);
  long long cur = 1, lagbe = 1;
  for (int i = strt + 1; i <= n; i++) {
    sum2 = (sum2 + a[i]) % MOD;
    if (k[i] != k[i - 1]) {
      long long dif = k[i - 1] - k[i];
      for (int j = 0; j < dif; j++) {
        if (lagbe > n) break;
        lagbe *= p;
      }
      if (lagbe > n) {
        for (int j = i + 1; j <= n; j++) sum2 = (sum2 + a[i]) % MOD;
        break;
      }
    }
    lagbe--;
    if (!lagbe) return Get(i + 1);
  }
  return (sum1 - sum2 + MOD) % MOD;
}
void solve() {
  cin >> n >> p;
  for (int i = 1; i <= n; i++) cin >> k[i];
  if (p == 1) {
    cout << n % 2 << "\n";
    return;
  }
  sort(k + 1, k + n + 1, greater<long long>());
  for (int i = 1; i <= n; i++) {
    a[i] = bigmod(p, k[i]);
  }
  cout << Get(1) << "\n";
  for (int i = 1; i <= n; i++) k[i] = a[i] = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
