#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200000];
int c[200001];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) cin >> c[i + 1];
  sort(a, a + n, greater<int>());
  int ans = 0;
  for (int i = k, g = 0; i >= 1; --i) {
    while (g < n && a[g] == i) ++g;
    ans = max(ans, (g + c[i] - 1) / c[i]);
  }
  vector<vector<int>> res(ans);
  for (int i = 0; i < n; i++) res[i % ans].push_back(a[i]);
  cout << ans << "\n";
  for (auto vec : res) {
    cout << vec.size() << " ";
    for (auto x : vec) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
