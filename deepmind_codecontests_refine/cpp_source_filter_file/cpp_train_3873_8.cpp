#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<char> v1(n), v2(n);
  vector<int> cnt(26);
  for (int i = 0; i < n; i++) {
    cin >> v1[i];
    cnt[v1[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    cin >> v2[i];
    cnt[v2[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    if (cnt[i] % 2) {
      cout << "No\n";
      return;
    }
  }
  vector<pair<int, int>> sol;
  for (int i = 0; i < n; i++) {
    if (v1[i] == v2[i]) continue;
    for (int j = i + 1; j < n; j++) {
      if (v1[j] == v2[j]) continue;
      if (v1[j] == v1[i]) {
        sol.push_back({j, i});
        swap(v2[i], v1[j]);
        break;
      } else if (v2[j] == v1[i]) {
        sol.push_back({j, j});
        sol.push_back({j, i});
        swap(v1[j], v2[j]);
        swap(v2[i], v1[j]);
        break;
      }
    }
  }
  if (sol.size() == 0) sol.push_back({0, 0});
  cout << "Yes\n";
  cout << sol.size() << "\n";
  for (auto e : sol) cout << e.first + 1 << " " << e.second + 1 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
