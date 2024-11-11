#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, l, m, n, ans = 0, sum = 0, a[100005] = {0},
                                  b[100005] = {0}, x, y, z;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    if (i == 1) {
      ans = x + y;
    } else {
      ans = max(x + y, ans);
    }
  }
  cout << ans;
  return 0;
}
