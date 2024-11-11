#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), prefmax(n);
  vector<vector<int> > pos(x + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i)
      prefmax[i] = max(prefmax[i - 1], a[i]);
    else
      prefmax[i] = a[i];
    pos[a[i]].push_back(i);
  }
  int lst = n + 1;
  int left;
  for (int i = x; i >= 1; i--) {
    if (pos[i].empty()) {
      left = i;
      continue;
    }
    if (pos[i].back() > lst) break;
    left = i;
    lst = pos[i][0];
  }
  lst = -1;
  int ans = 0;
  for (int l = 1; l <= x; l++) {
    int r = max(l, left - 1);
    if (lst != -1) {
      r = max(r, prefmax[lst]);
    }
    ans += x - r + 1;
    if (!pos[l].empty()) {
      if (pos[l][0] < lst) break;
      lst = pos[l].back();
    }
  }
  cout << ans << endl;
}
