#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  vector<long long> cur(n);
  for (long long i = 0; i < n; i++) {
    cur[i] = a[i] * (i + 1) * (n - i);
  }
  sort(cur.begin(), cur.end());
  sort(b.rbegin(), b.rend());
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    res = (res + (b[i] * (cur[i] % MOD))) % MOD;
  }
  cout << res % MOD << endl;
  return 0;
}
