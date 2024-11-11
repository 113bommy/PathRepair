#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  vector<pair<long long, long long>> res;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long idx = -1;
  for (long long i = 1; i < n; i++) {
    if (arr[0] != arr[i]) {
      idx = i;
      res.push_back({1, i + 1});
    }
  }
  if (idx == -1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (long long i = 1; i < n; i++) {
    if (arr[i] == arr[0]) {
      res.push_back({idx + 1, i + 1});
    }
  }
  for (auto [x, y] : res) cout << x << " " << y << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
