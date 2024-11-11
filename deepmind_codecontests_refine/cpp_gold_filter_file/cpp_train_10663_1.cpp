#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i, j, k, x, s = 1000000, p;
  cin >> n;
  vector<bool> inset(s + 1, false);
  for (i = 0; i < n; i++) {
    cin >> x;
    inset[x] = true;
  }
  vector<int> v, ans;
  for (i = 1; i <= s / 2; i++) {
    if (!inset[i] && !inset[s + 1 - i]) v.push_back(i);
  }
  p = 0;
  for (i = 1; i <= s; i++) {
    if (inset[i] && !inset[s + 1 - i])
      ans.push_back(s + 1 - i);
    else if (inset[i] && inset[s + 1 - i] && (i <= s / 2)) {
      ans.push_back(v[p]);
      ans.push_back(s + 1 - v[p]);
      p++;
    }
  }
  cout << ans.size() << "\n";
  for (auto p : ans) cout << p << " ";
  cout << "\n";
  return 0;
}
