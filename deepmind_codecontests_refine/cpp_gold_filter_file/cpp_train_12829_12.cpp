#include <bits/stdc++.h>
using namespace std;
int n, t, v[200005], suff[200005][201], ans;
vector<int> pos[205];
int query(int l, int r, int num) {
  int res = 0, tmp;
  for (int i = 0; i <= 200; i++) {
    if (i != num) {
      tmp = suff[r][i];
      if (l > 0) tmp -= suff[l - 1][i];
      res = max(res, tmp);
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    for (int i = 0; i <= 200; i++) {
      pos[i].clear();
    }
    for (int i = 0; i <= 200; i++)
      for (int j = 0; j < n; j++) suff[j][i] = 0;
    ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      pos[v[i]].push_back(i);
    }
    for (int i = 0; i <= 200; i++) {
      for (int j = 0; j < n; j++) {
        if (v[j] == i) suff[j][i] = 1;
        if (j) suff[j][i] += suff[j - 1][i];
      }
    }
    ans = query(0, n - 1, -1);
    for (int i = 0; i <= 200; i++) {
      for (int j = 0; (j + 1) * 2 <= pos[i].size(); j++) {
        ans = max(ans, (j + 1) * 2 +
                           query(pos[i][j], pos[i][pos[i].size() - 1 - j], i));
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
