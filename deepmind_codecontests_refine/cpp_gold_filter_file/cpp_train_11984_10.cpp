#include <bits/stdc++.h>
using namespace std;
const int N = 301;
string s[N][N];
vector<pair<pair<int, int>, pair<int, int> > > f(int n, int k) {
  vector<pair<pair<int, int>, pair<int, int> > > ans;
  pair<int, int> f0 = {1, 0}, f1 = {0, 1};
  int i, j, l;
  for (i = 0; i < s[0][0].size(); ++i)
    if (s[0][0][i] == '0')
      ans.push_back({{0, 0}, f0});
    else
      ans.push_back({{0, 0}, f1});
  for (i = 1; i < k; ++i)
    for (l = 0; l < s[0][i].size(); ++l) {
      ans.push_back({{0, i}, {0, 0}});
      if (s[0][i][l] == '0')
        ans.push_back({{0, 0}, f0});
      else
        ans.push_back({{0, 0}, f1});
    }
  for (i = 1; i < n; ++i)
    for (l = 0; l < s[i][0].size(); ++l) {
      ans.push_back({{i, 0}, {0, 0}});
      if (s[i][0][l] == '0')
        ans.push_back({{0, 0}, f0});
      else
        ans.push_back({{0, 0}, f1});
    }
  for (i = 1; i < n; ++i)
    for (j = 1; j < k; ++j)
      for (l = 0; l < s[i][j].size(); ++l)
        if (s[i][j][l] == '0') {
          ans.push_back({{i, j}, {i, 0}});
          if (i != 1) ans.push_back({{i, 0}, f0});
        } else {
          ans.push_back({{i, j}, {0, j}});
          if (j != 1) ans.push_back({{0, j}, f1});
        }
  return ans;
}
int main() {
  int i, j, k, n, p, l;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (i = 0; i < n; ++i)
    for (j = 0; j < k; ++j) {
      cin >> s[i][j];
      for (l = 0; l < s[i][j].size() / 2; ++l)
        swap(s[i][j][l], s[i][j][s[i][j].size() - l - 1]);
    }
  vector<pair<pair<int, int>, pair<int, int> > > ans1, ans2;
  ans1 = f(n, k);
  for (i = 0; i < n; ++i)
    for (j = 0; j < k; ++j) cin >> s[i][j];
  ans2 = f(n, k);
  cout << ans1.size() + ans2.size() << endl;
  for (i = 0; i < ans1.size(); ++i)
    cout << ans1[i].first.first + 1 << ' ' << ans1[i].first.second + 1 << ' '
         << ans1[i].second.first + 1 << ' ' << ans1[i].second.second + 1
         << "\n";
  for (i = ans2.size() - 1; i >= 0; --i)
    cout << ans2[i].second.first + 1 << ' ' << ans2[i].second.second + 1 << ' '
         << ans2[i].first.first + 1 << ' ' << ans2[i].first.second + 1 << "\n";
}
