#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  int n, u;
  cin >> n >> u;
  for (int i = 1; i <= n; i++) cin >> a[i];
  double ans = -100000;
  for (int i = 1; i <= n - 2; i++) {
    int j = i + 1;
    int l = i + 2, r = n;
    int key;
    if (a[l] - a[i] > u) continue;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[mid] - a[i] > u)
        r = mid - 1;
      else {
        key = mid;
        l = mid + 1;
      }
    }
    int k = key;
    ans = max(ans, 1.0 * (a[k] - a[j]) / (a[k] - a[i]));
  }
  if (ans != -100000)
    printf(".10f\n", ans);
  else
    cout << -1 << endl;
}
