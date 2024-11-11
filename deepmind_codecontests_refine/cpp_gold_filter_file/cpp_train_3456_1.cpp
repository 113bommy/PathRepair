#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e9;
const long long base = 998244353;
long long mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, long long>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  int cur = n - 1;
  multiset<long long> s;
  long long ans = 0;
  for (int i = n; i >= 0; --i) {
    while (cur >= 0 && a[cur].first == i) {
      s.insert(a[cur].second);
      --cur;
    }
    while (s.size() > n - i) {
      ans += *s.begin();
      s.erase(s.begin());
    }
  }
  cout << ans << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  auto start = clock();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  std::cerr << double(clock() - start) / CLOCKS_PER_SEC << std::endl;
  return 0;
}
