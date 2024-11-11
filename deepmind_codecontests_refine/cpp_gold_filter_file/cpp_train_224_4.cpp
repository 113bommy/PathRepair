#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int left = 1e9 + 1, right = -1;
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first >> v[i].second;
      left = min(left, v[i].second);
      right = max(right, v[i].first);
    }
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    int ans = right - left;
    cout << max(0, ans) << '\n';
  }
  return 0;
}
