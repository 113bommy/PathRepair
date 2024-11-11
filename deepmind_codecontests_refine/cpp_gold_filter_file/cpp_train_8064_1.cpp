#include <bits/stdc++.h>
using namespace std;
int n;
int lft[607], rgt[607];
bool dp[607][607], vis[607][607];
bool solve(int l, int r) {
  if (l > r) return true;
  if (vis[l][r]) return dp[l][r];
  vis[l][r] = true;
  bool &ret = dp[l][r];
  ret = false;
  for (int pos = lft[l]; pos <= rgt[l]; pos++) {
    if (pos % 2 == 0) continue;
    int k = (pos - 1) / 2;
    if ((r - l + 1) <= k) break;
    ret = solve(l + 1, l + k) & solve(l + k + 1, r);
    if (ret == true) break;
  }
  return ret;
}
void show(int l, int r) {
  if (l > r) return;
  for (int pos = lft[l]; pos <= rgt[l]; pos++) {
    if (pos % 2 == 0) continue;
    int k = (pos - 1) / 2;
    if ((r - l + 1) <= k) break;
    bool tmp = solve(l + 1, l + k) & solve(l + k + 1, r);
    if (tmp == true) {
      printf("(");
      show(l + 1, l + k);
      printf(")");
      show(l + k + 1, r);
      return;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> lft[i] >> rgt[i];
  }
  if (solve(1, n)) {
    show(1, n);
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
