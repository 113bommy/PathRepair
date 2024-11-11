#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  int n, u;
  double ans = 0.0;
  cin >> n >> u;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = 2e9;
  for (int i = 1; i <= n - 3; i++) {
    int j = upper_bound(a + 1, a + n + 2, a[i] + u) - a;
    j--;
    if (j == i + 1) continue;
    int k = j;
    if (((double)a[k] - (double)a[i + 1]) / ((double)a[k] - (double)a[i]) > ans)
      ans = ((double)a[k] - (double)a[i + 1]) / ((double)a[k] - (double)a[i]);
  }
  if (abs(ans) < 1e-9)
    printf("-1\n");
  else
    cout << setprecision(9) << ans << endl;
  return 0;
}
