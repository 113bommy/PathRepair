#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k, x, mx = LLONG_MIN;
  cin >> n >> k;
  vector<long long int> v;
  k--;
  for (long long int i = 0; i < (long long int)n; i++) {
    cin >> x;
    v.push_back(x);
    mx = max(mx, x);
  }
  for (auto &k : v) k = mx - k;
  mx = *max_element(v.begin(), v.end());
  if (k & 1) {
    for (auto &k : v) k = mx - k;
  }
  for (auto g : v) cout << g << " ";
  cout << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int tests = 1;
  cin >> tests;
  for (long long int test_case = 1; test_case <= tests; test_case++) {
    solve();
  }
  cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << endl;
  return 0;
}
