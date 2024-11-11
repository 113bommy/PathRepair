#include <bits/stdc++.h>
using namespace std;
const int MAXn = 10 + 2;
bool am[MAXn][MAXn];
int p3[MAXn];
int ans[(int)6e4];
int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  int sum = 0;
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    am[v1][v2] = am[v2][v1] = true;
  }
  p3[0] = 1;
  for (int i = 1; i <= n; i++) p3[i] = p3[i - 1] * 3;
  for (int i = 0; i < p3[n]; i++) {
    vector<int> leaf, other;
    leaf.clear();
    other.clear();
    int t = i;
    for (int j = 0; j < n; j++) {
      if (t % 3 == 2)
        other.push_back(j);
      else if (t % 3 == 1)
        leaf.push_back(j);
      t /= 3;
    }
    if (other.empty() && leaf.empty())
      ans[i] = 0;
    else if (other.empty()) {
      if ((int)leaf.size() == 1)
        ans[i] = 1;
      else if ((int)leaf.size() == 2) {
        if (am[leaf[0]][leaf[1]])
          ans[i] = 1;
        else
          ans[i] = 0;
      } else
        ans[i] = 0;
    } else if ((int)leaf.size() < 2)
      ans[i] = 0;
    else {
      int ni = i - p3[leaf[0]];
      ans[i] = 0;
      for (int j = 0; j < (int)other.size(); j++)
        if (am[leaf[0]][other[j]]) ans[i] = ans[ni];
      for (int j = 0; j < (int)other.size(); j++)
        if (am[leaf[0]][other[j]]) ans[i] += ans[ni - p3[other[j]]];
    }
    if (other.size() + leaf.size() == n && leaf.size() == k) sum += ans[i];
  }
  cout << sum << endl;
  {
    int _;
    cin >> _;
  }
  return 0;
}
