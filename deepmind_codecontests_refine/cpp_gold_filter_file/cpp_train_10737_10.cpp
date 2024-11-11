#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v) cin >> i;
  int ans = 0;
  {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] == 1) {
        if (i && v[i - 1] == 2) cnt1 = 0;
        cnt1++;
      } else {
        if (i && v[i - 1] == 1) cnt2 = 0;
        cnt2++;
        ans = max(ans, min(cnt1, cnt2) * 2);
      }
    }
  }
  {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] == 2) {
        if (i && v[i - 1] == 1) cnt2 = 0;
        cnt2++;
      } else {
        if (i && v[i - 1] == 2) cnt1 = 0;
        cnt1++;
        ans = max(ans, min(cnt1, cnt2) * 2);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
