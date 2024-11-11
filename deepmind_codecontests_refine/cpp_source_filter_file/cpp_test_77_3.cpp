#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e3;
int n, m, mp[mxN][mxN] = {0};
bool vis[mxN][mxN] = {0};
bool e(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m && vis[i][j]; }
int search(int i, int j) {
  bool toS[4] = {0, 0, 0, 0};
  int ans = 0;
  if (!(mp[i][j] & 8) && e(i - 1, j)) {
    vis[i - 1][j] = false;
    toS[0] = 1;
    ans++;
  }
  if (!(mp[i][j] & 4) && e(i, j + 1)) {
    vis[i][j + 1] = false;
    toS[1] = 1;
    ans++;
  }
  if (!(mp[i][j] & 2) && e(i + 1, j)) {
    vis[i + 1][j] = false;
    toS[2] = 1;
    ans++;
  }
  if (!(mp[i][j] & 1) && e(i, j - 1)) {
    vis[i][j - 1] = false;
    toS[3] = 1;
    ans++;
  }
  if (toS[0]) ans += search(i - 1, j);
  if (toS[1]) ans += search(i, j + 1);
  if (toS[2]) ans += search(i + 1, j);
  if (toS[3]) ans += search(i, j - 1);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  vector<int> res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mp[i][j];
      vis[i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (e(i, j)) {
        vis[i][j] = 0;
        int temp = search(i, j);
        res.push_back(1 + temp);
      }
    }
  }
  sort(res.begin(), res.end());
  for (int j = res.size(); j >= 0; j--) {
    cout << res[j] << " ";
  }
  return 0;
}
