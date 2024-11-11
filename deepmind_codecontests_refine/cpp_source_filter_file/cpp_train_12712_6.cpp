#include <bits/stdc++.h>
using namespace std;
int a[6000];
int sum[6000];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  for (int l = n; l >= 0; l--) {
    for (int bg = 1; bg + l <= n; bg++) {
      if (sum[bg + l] - sum[bg - 1] >= 100 * l) {
        ans = l;
        cout << ans;
        return 0;
      }
    }
  }
  cout << 0;
}
