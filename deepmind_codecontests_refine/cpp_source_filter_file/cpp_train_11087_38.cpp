#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> h, ans;
  int n, t = 0;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  h.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> h[i];
  ans.push_back(0);
  t = h[n];
  for (int i = n - 1; i > 0; i--) {
    if (h[n] > t)
      ans.push_back(0);
    else
      ans.push_back(t - h[i] + 1);
    t = max(t, h[i]);
  }
  for (int i = n - 1; i >= 0; i--) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
