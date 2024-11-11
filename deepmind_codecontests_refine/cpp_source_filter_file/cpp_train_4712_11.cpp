#include <bits/stdc++.h>
const long long mod = 1000000007;
using namespace std;
long long MOD = 998244353;
void solve() {
  long long n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), greater<long long>());
  long long curr = 1, ans = 0;
  for (long long i = 0; i < n; i++) {
    if (curr * a[i] >= x) {
      ans++;
      curr = 0;
    } else {
      curr++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
