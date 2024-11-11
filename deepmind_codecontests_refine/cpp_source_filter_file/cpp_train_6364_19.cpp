#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j;
  int n, a[1010];
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 99999999, t;
  for (i = 0; i < 102; ++i) {
    int cnt = 0;
    for (j = 0; j < n; ++j) {
      if (abs(a[j] - i) > 1) cnt += abs(a[j] - i) - 1;
    }
    if (cnt < ans) {
      ans = cnt;
      t = i;
    }
  }
  cout << t << " " << ans;
  return 0;
}
