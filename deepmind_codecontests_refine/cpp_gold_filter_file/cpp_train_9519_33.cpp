#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int c, d, n, m, k, i, j, j1, j2, k1, ans = INT_MAX;
  cin >> c >> d;
  cin >> n >> m;
  cin >> k;
  if (k >= n * m) {
    cout << "0";
    return 0;
  }
  i = n * m - k;
  j = d * i;
  if (i % n == 0)
    j1 = (i / n) * c;
  else
    j1 = ((i / n) + 1) * c;
  k1 = i % n;
  if (k1 != 0) {
    int d1 = i - k1;
    j2 = k1 * d + (i / n) * c;
    ans = min(ans, j2);
    ans = min(ans, j1);
    ans = min(ans, j);
    cout << ans;
  } else {
    ans = min(j, j1);
    cout << ans;
  }
}
