#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int i, j;
  for (i = 0; i < n; i++) cin >> a[i];
  int mm = 0;
  for (i = 0; i < n; i++) mm = max(mm, a[i]);
  int val = *min_element(a.begin(), a.end());
  int l = val, h = mm + m;
  int mid, ans = l;
  while (l <= h) {
    mid = (l + h) / 2;
    int cc = 0;
    for (i = 0; i < n; i++) {
      cc += (mid - a[i]);
    }
    if (cc >= m) {
      h = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << " " << mm + m << '\n';
  return 0;
}
