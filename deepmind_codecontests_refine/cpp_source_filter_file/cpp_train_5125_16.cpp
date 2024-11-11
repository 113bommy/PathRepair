#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  int ans[t];
  for (int i = 0; i < t; i++) {
    int n, d;
    cin >> n >> d;
    int a[n];
    for (int j = 0; j < n; j++) cin >> a[j];
    int j = 1;
    while (d > 0 && j < n) {
      if (a[j] * j > d) {
        a[0] += d / j;
        j = n;
      } else {
        d -= a[j] * j;
        a[0] += a[j] * j;
      }
      j++;
    }
    ans[i] = a[0];
  }
  for (int i = 0; i < t; i++) cout << ans[i] << " ";
  return 0;
}
