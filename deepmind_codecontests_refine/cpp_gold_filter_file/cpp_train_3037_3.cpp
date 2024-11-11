#include <bits/stdc++.h>
using namespace std;
const int LEN = (int)1e5;
int n, q;
int a[LEN];
int sum[LEN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sum[0] = a[0];
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << (sum[r] - (l > 0 ? sum[l - 1] : 0)) / 10 << "\n";
  }
  return 0;
}
