#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int> > input(n);
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    input[i].first = x;
  }
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    input[i].second = x;
  }
  sort(input.begin(), input.end());
  for (long long int i = n - 2; i >= 0; i--) {
    input[i].second += input[i + 1].second;
  }
  long long int ans = 1e12;
  for (long long int i = 0; i < n - 1; i++) {
    ans = min(ans, max(input[i].first, input[i + 1].second));
  }
  cout << min(ans, min(input[n - 1].first, input[0].second)) << endl;
}
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
