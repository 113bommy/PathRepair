#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, i, s = 0, j;
  cin >> n >> k;
  vector<int> ans;
  if (k == 0) {
    for (i = 1; i <= n; i++) ans.push_back(i);
  } else if (n <= k)
    ans.push_back(n);
  else {
    for (i = k + 1; i > 0; i--) {
      ans.clear();
      for (j = i; j <= n; j += 2 * k + 1) {
        ans.push_back(j);
      }
      if (n - ans[ans.size() - 1] - k > k) break;
    }
  }
  cout << ans.size() << "\n";
  for (auto x : ans) cout << x << " ";
  cout << "\n";
  return 0;
}
