#include <bits/stdc++.h>
using namespace std;
int t, n, m, ans;
vector<vector<int> > p;
bool check(int x) {
  vector<bool> flag(n);
  bool pair = false;
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (p[i][j] >= x) {
        flag[j] = true;
        cnt++;
      }
    }
    if (cnt > 1) pair = true;
  }
  if (!pair) return false;
  ans = true;
  for (bool x : flag) {
    ans = ans && x;
  }
  return ans;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> m >> n;
    p.assign(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) cin >> p[i][j];
    }
    long long l = 1, r = 1e9;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << ans << endl;
  }
  return 0;
}
