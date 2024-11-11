#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const double PI = 3.141592653589793238463;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int x;
  cin >> x;
  int y[x + 1], a[x + 1];
  vector<pair<int, int>> ans;
  for (int i = 1; i <= x; i++) {
    cin >> y[i];
  }
  for (int i = 1; i <= x; i++) cin >> a[i];
  for (int i = 1; i <= x; i++) {
    for (int j = i; j <= x; j++) {
      if (y[i] == a[j]) {
        int k = j;
        while (k > i) {
          swap(a[k - 1], a[k]);
          ans.push_back({k - 1, k});
          k--;
        }
        break;
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << '\n';
  return 0;
}
