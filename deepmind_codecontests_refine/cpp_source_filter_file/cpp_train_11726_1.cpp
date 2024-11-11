#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  n++;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<int> ans1;
  vector<vector<int> > lvl1(maxn);
  int curv = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < a[i]; ++j) {
      if (lvl1[i - 1].empty())
        ans1.push_back(0);
      else {
        ans1.push_back(lvl1[i - 1].back());
        if (lvl1[i - 1].size() > 1) lvl1[i - 1].pop_back();
      }
      lvl1[i].push_back(curv);
      curv++;
    }
  }
  vector<int> ans2;
  vector<vector<int> > lvl2(maxn);
  curv = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < a[i]; ++j) {
      if (lvl2[i - 1].empty())
        ans2.push_back(0);
      else {
        ans2.push_back(lvl2[i - 1][0]);
      }
      lvl2[i].push_back(curv);
      curv++;
    }
  }
  if (ans1 == ans2) {
    cout << "perfect";
  } else {
    cout << "ambiguous" << '\n';
    for (int i : ans1) cout << i << ' ';
    cout << '\n';
    for (int i : ans2) cout << i << ' ';
  }
  return 0;
}
