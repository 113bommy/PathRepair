#include <bits/stdc++.h>
using namespace std;
long long k, a, b;
int main() {
  long long n, l, r, QL, QR;
  cin >> n >> l >> r >> QL >> QR;
  long long a[100000 + 10] = {};
  long long sum[100000 + 10] = {};
  long long SUM = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    SUM += a[i];
  }
  for (long long i = 0; i <= n; i++) sum[i + 1] = sum[i] + a[i];
  long long ans = INT_MAX;
  for (long long i = 0; i < n; i++) {
    long long tl, tr;
    tl = i;
    tr = n - i;
    long long cost = 0;
    if (tl < tr) {
      cost += QR * (tr - tl - 1);
    } else if (tl > tr)
      cost += QL * (tl - tr - 1);
    long long sum_l = sum[i];
    long long sum_r = SUM - sum_l;
    long long tt = sum_l * l + sum_r * r + cost;
    ans = min(ans, tt);
  }
  cout << ans << endl;
  return 0;
}
