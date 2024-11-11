#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int sum[n];
  sum[0] = a[0];
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int ans;
    if (l != 0)
      ans = sum[r] - sum[l - 1];
    else
      ans = sum[r];
    cout << ans / 10 << endl;
  }
}
