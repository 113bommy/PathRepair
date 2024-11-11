#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double eps = 1e-9;
const int mod = inf + 7;
int n, m;
vector<pair<int, int> > ans;
int main() {
  cin >> n >> m;
  if (m == 3) {
    if (n <= 4) {
      ans.push_back(make_pair(100, 0));
      ans.push_back(make_pair(-100, 0));
      ans.push_back(make_pair(0, 100));
      if (n == 4) ans.push_back(make_pair(0, 50));
    } else {
      puts("-1");
      return 0;
    }
  } else {
    for (int i = 1; i <= m; i++) ans.push_back(make_pair(i, i * i));
    for (int i = 1; i <= n - m; i++)
      ans.push_back(make_pair(i, -10000 - i * i));
  }
  for (int i = 0; i < n; i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
  return 0;
}
