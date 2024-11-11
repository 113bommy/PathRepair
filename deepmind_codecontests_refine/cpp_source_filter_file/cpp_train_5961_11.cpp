#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > ans;
  for (long long i = 0; i < (long long)2 * n + 1; ++i) ans.push_back({i, 0});
  for (long long i = 1; i < 2 * n + 1; ++ ++i) {
    ans.push_back({i, 1});
    ans.push_back({i, -1});
  }
  if (n % 2) {
    ans.push_back({0, 1});
    ans.push_back({2 * n, -1});
    for (long long i = 1; i < 2 * n - 1; i += 4) {
      ans.push_back({i, -2});
      ans.push_back({i + 1, -2});
      ans.push_back({i + 2, -2});
    }
    for (long long i = 3; i < 2 * n + 1; i += 4) {
      ans.push_back({i, 2});
      ans.push_back({i + 1, 2});
      ans.push_back({i + 2, -2});
    }
  } else {
    ans.push_back({0, 1});
    ans.push_back({2 * n, 1});
    for (long long i = 1; i < 2 * n + 1; i += 4) {
      ans.push_back({i, -2});
      ans.push_back({i + 1, -2});
      ans.push_back({i + 2, -2});
    }
    for (long long i = 1; i < 2 * n - 1; i += 4) {
      ans.push_back({i, 2});
      ans.push_back({i + 1, 2});
      ans.push_back({i + 2, 2});
    }
  }
  cout << ans.size() << "\n";
  for (pair<long long, long long> p : ans)
    cout << p.first << " " << p.second << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
