#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 2 * k) {
      while (a[i] > 2 * k) {
        k *= 2;
        ans++;
      }
      k = 2 * a[i];
    } else if (a[i] > k) {
      k = 2 * a[i];
    }
  }
  cout << ans;
  return 0;
}
