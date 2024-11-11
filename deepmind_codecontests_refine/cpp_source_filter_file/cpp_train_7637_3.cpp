#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int ans = 0;
  ans += n - 1;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ans += a[0];
  for (long long int i = 0; i < n - 1; i++) {
    ans += abs(a[i] - a[i + 1]);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
