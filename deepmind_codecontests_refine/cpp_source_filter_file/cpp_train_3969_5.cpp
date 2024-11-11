#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int min_pref[2][MAXN][MAXN];
int sum[2][MAXN][MAXN];
int a[2][MAXN];
int heroes_hp[2][MAXN];
int heroes_id[2][MAXN];
vector<int> ans[2];
vector<int> tail;
bool solve(int arr, int idx) {
  ans[arr].clear();
  tail.clear();
  for (int i = idx; i >= 0; i--) {
    if (!heroes_id[arr][i]) continue;
    if (heroes_hp[arr][i] >= -min_pref[arr][i][idx]) {
      ans[arr].push_back(heroes_id[arr][i]);
      idx = i;
    } else {
      tail.push_back(heroes_id[arr][i]);
    }
  }
  for (int i = 0; i < idx; i++)
    if (heroes_id[arr][i]) return false;
  for (int i = 0; i < tail.size(); i++) ans[i].push_back(tail[i]);
  return true;
}
vector<int> super_tail;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int pos, h;
    cin >> pos >> h;
    pos--;
    if (h < heroes_hp[0][pos]) {
      super_tail.push_back(i);
    } else {
      if (heroes_id[0][pos]) {
        super_tail.push_back(heroes_id[0][pos]);
      }
      heroes_hp[0][pos] = h;
      heroes_id[0][pos] = i;
      heroes_hp[1][n - 1 - pos] = h;
      heroes_id[1][n - 1 - pos] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> a[0][i];
    a[1][i] = a[0][n - 1 - i];
  }
  for (int i = 0; i < n; i++) {
    sum[0][i][i] = a[0][i];
    for (int j = i + 1; j < n; j++) {
      sum[0][i][j] = sum[0][i][j - 1] + a[0][j];
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) sum[1][i][j] = sum[0][n - 1 - j][n - 1 - i];
  for (int i = 0; i < n; i++) {
    min_pref[0][i][i] = min(a[0][i], 0);
    min_pref[1][i][i] = min(a[1][i], 0);
    for (int j = i + 1; j < n; j++) {
      min_pref[0][i][j] = min(min_pref[0][i][j - 1], sum[0][i][j]);
      min_pref[1][i][j] = min(min_pref[1][i][j - 1], sum[1][i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (solve(0, i) && solve(1, n - 1 - (i + 1))) {
      int pos = i + 1;
      if (ans[0].size() == 0) pos++;
      cout << pos << endl;
      for (int i = 0; i < ans[0].size(); i++) cout << ans[0][i] << " ";
      for (int i = 0; i < ans[1].size(); i++) cout << ans[1][i] << " ";
      for (int i = 0; i < super_tail.size(); i++) cout << super_tail[i] << " ";
      return 0;
    }
  }
  cout << -1;
  return 0;
}
