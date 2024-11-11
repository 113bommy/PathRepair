#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(3, vector<int>(n));
  for (int(i) = 0; (i) < (n - 1); (i)++) cin >> a[0][i];
  for (int(i) = 0; (i) < (n - 1); (i)++) cin >> a[1][i];
  for (int(i) = 0; (i) < (n); (i)++) cin >> a[2][i];
  int ans = 1 << 29;
  for (int(i) = 0; (i) < (n); (i)++)
    for (int(j) = (i + 1); (j) < (n); (j)++) {
      int w = a[2][i] + a[2][j];
      for (int(k) = 0; (k) < (i); (k)++) w += a[0][k];
      for (int(k) = 0; (k) < (j); (k)++) w += a[0][k];
      for (int(k) = (j); (k) < (n); (k)++) w += a[1][k];
      for (int(k) = (i); (k) < (n); (k)++) w += a[1][k];
      ans = min(ans, w);
    }
  cout << ans << endl;
  return 0;
}
