#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-7;
const long long int MOD = 1000000007;
long long int div_floor(const long long int &a, const long long int &b) {
  return a / b - (((a ^ b) < 0) and a % b);
}
long long int div_ceil(const long long int &a, const long long int &b) {
  return a / b + (((a ^ b) >= 0) and a % b);
}
void solve() {
  int n, m;
  cin >> n >> m;
  if (n < m) swap(n, m);
  if (m == 1 && n < 4)
    cout << "YES\n";
  else if (m == 2 && n < 3)
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
