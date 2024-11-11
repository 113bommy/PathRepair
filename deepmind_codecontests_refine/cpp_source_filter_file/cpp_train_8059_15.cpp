#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w, k;
  cin >> n >> k >> w;
  int a[n + 1];
  int sum[n + 1];
  sum[0] = 0;
  int sumk[n + 1];
  sumk[0] = 0;
  char x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[i] = x - int('0');
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    sumk[i] = sumk[max(0, i - k)] + a[i];
  }
  for (int i = 1; i <= n; i++) {
  }
  int l, r;
  for (int i = 1; i <= w; i++) {
    cin >> l >> r;
    int ss = sum[r] - sum[l - 1];
    int sk = sumk[r] - sumk[l];
    int d = (r - (l - 1)) / k - sk;
    ss += d;
    cout << max(0, ss - ((r - (l - 1)) / k) + d) << endl;
  }
  return 0;
}
