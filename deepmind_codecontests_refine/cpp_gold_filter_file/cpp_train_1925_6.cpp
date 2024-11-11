#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 20;
const long long inf = 1e10;
long long a[320], b[320];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    int ind = i;
    while (a[i] != b[ind]) ind++;
    for (int j = ind; j > i; j--)
      ans.push_back({j - 1, j}), swap(b[j], b[j - 1]);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
