#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans = 0;
vector<int> v(100000);
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int l = m - 2, r = m;
  while (true) {
    if (l >= 0 && v[l] <= k && k) {
      ans = (m - l - 1) * 10;
      break;
    }
    if (r < n && v[r] <= k && k) {
      ans = (r - m + 1) * 10;
      break;
    }
    l--;
    r++;
  }
  cout << ans;
  return 0;
}
