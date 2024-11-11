#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0, in; i < n; i++) {
    scanf("%d", &in);
    v[in].push_back(i);
  }
  int ans = 1;
  for (int i = 1; i <= m; i++) {
    int mid, l, r;
    if (v[i].size()) {
      mid = 1;
      l = 0;
      r = 0;
    }
    int ct = 0;
    for (int j = 0;
         j + 1 < v[i].size() && l < v[i].size() && r < v[i].size();) {
      if (ct + v[i][j + 1] - v[i][j] - 1 <= k) {
        ct += v[i][j + 1] - v[i][j] - 1;
        r++;
        j++;
      } else {
        mid = std::max(mid, r - l + 1);
        if (ct > 0) {
          ct -= v[i][l + 1] - v[i][l] - 1;
        } else if (r == l) {
          r++;
          j++;
        }
        l++;
      }
    }
    if (v[i].size()) {
      mid = std::max(mid, r - l + 1);
      ans = std::max(ans, mid);
    }
  }
  cout << ans;
  return 0;
}
