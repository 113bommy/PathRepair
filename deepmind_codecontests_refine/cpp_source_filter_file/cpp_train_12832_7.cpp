#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
long long ceils(long long x, long long y) { return x / y + ((x % y) != 0); }
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void solve() {
  long long n;
  cin >> n;
  long long a[50] = {};
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[x - 1]++;
  }
  long long ans = 0;
  for (long long j = 0; j < 50; j++) {
    long long c = 0;
    for (long long i = 0; i < j + 1; i++) {
      c += min(a[i], a[j - i]);
      ans = max(ans, c / 2);
    }
  }
  cout << ans;
}
