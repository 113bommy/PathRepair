#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> m(n), c(k);
  for (int i = 0; i < n; i++) cin >> m[i];
  for (int i = 0; i < k; i++) cin >> c[i];
  sort(m.rbegin(), m.rend());
  vector<vector<int>> groups;
  for (int i = 0; i < n; i++) {
    int x = m[i] - 1;
    int left = 0, right = groups.size() + 1;
    while (right - left > 1) {
      int mid = right + left >> 1;
      if (groups[mid - 1].size() + 1 > c[x]) {
        left = mid;
      } else {
        right = mid;
      }
    }
    if (left == groups.size()) {
      vector<int> want;
      want.push_back(x);
      groups.push_back(want);
    } else {
      groups[left].push_back(x);
    }
  }
  cout << (int)groups.size() << '\n';
  for (int i = 0; i < (int)groups.size(); i++) {
    cout << groups[i].size() << ' ';
    for (auto u : groups[i]) {
      cout << u + 1 << ' ';
    }
    cout << '\n';
  }
}
