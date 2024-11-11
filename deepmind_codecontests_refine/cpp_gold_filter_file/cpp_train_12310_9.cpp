#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void manupulate(string &str) {
  for (long long int i = 0; i < str.size(); ++i) str[i] -= 48;
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  for (long long int i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}
long long int expo(long long int a, long long int n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  long long int tmp = expo(a, n / 2);
  tmp = (tmp * tmp) % (long)(1e9 + 7);
  if (n & 1) tmp = (tmp * a) % (long)(1e9 + 7);
  return tmp;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    ;
    long long int k;
    cin >> k;
    ;
    long long int ar[n], br[n];
    for (long long int i = 0; i < n; ++i) cin >> ar[i];
    ;
    for (long long int i = 0; i < n; ++i) cin >> br[i];
    ;
    sort(ar, ar + n);
    sort(br, br + n, greater<long long int>());
    long long int ans = 0;
    long long int x = 0;
    for (long long int i = 0; i < k; ++i) {
      if (br[i] > ar[i]) {
        ans += br[i];
        ++x;
      }
    }
    for (long long int i = x; i < n; ++i) ans += ar[i];
    cout << ans << "\n";
  }
  return 0;
}
