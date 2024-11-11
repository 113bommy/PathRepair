#include <bits/stdc++.h>
using namespace std;
const int sz = 51;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    ;
    int x[n], p1 = 0, p2 = n - 1, ans = 0;
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    sort(x, x + n);
    vector<int> sums;
    int f[105];
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (!f[x[i] + x[j]]) {
          f[x[i] + x[j]] = 1;
          sums.push_back(x[i] + x[j]);
        }
      }
    }
    int caseid = 0;
    int vis[sz];
    memset(vis, -1, sizeof vis);
    for (int k = 0; k < sums.size(); k++) {
      int temp = 0, sum = sums[k];
      for (int i = 0; i < n; i++) {
        if (vis[i] == caseid) continue;
        for (int j = 0; j < n; j++) {
          if (vis[j] == caseid) continue;
          if (x[i] + x[j] == sum && i != j) {
            vis[i] = vis[j] = caseid;
            temp++;
            break;
          }
        }
      }
      caseid++;
      ans = max(ans, temp);
    }
    cout << ans << endl;
  }
}
