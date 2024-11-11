#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, x, y, ans = 0;
  cin >> n >> x >> y;
  if (x > y) {
    cout << n;
    return 0;
  }
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[i] <= x) ans = ans + 1;
  }
  ans = ans / 2;
  cout << ans;
  return 0;
}
