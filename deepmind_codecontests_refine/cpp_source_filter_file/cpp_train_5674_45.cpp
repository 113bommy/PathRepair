#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1);
  for (int i = 0; i < m; ++i) {
    int mx = 0, mxi = 0;
    for (int j = 0; j < n; ++j) {
      int a;
      cin >> a;
      if (a > mx) {
        mx = a;
        mxi = j + 1;
      }
    }
    v[mxi]++;
  }
  int mx = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (v[i] > mx) {
      mx = v[i];
      ans = i;
    }
  }
  cout << ans;
  return 0;
}
