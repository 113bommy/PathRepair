#include <bits/stdc++.h>
using namespace std;
long long sum[500000 + 10];
int data[500000 + 10];
int main() {
  int n, l, r, ql, qr;
  scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &data[i]);
    sum[i] += (sum[i - 1] + data[i] * r);
  }
  long long ans = 100000000000000;
  long long tem = 0;
  for (int i = 0; i <= n; ++i) {
    tem += data[i] * l;
    if (0 == i)
      ans = min(ans, sum[n] + (n - 1) * qr);
    else if (n == i)
      ans = min(ans, tem + (n - 1) * ql);
    else if (i == (n - i)) {
      ans = min(ans, tem + sum[n] - sum[i]);
    } else if (i < (n - i))
      ans = min(ans, tem + sum[n] - sum[i] + (n - i - i - 1) * qr);
    else
      ans = min(ans, tem + sum[n] - sum[i] + (2 * i - n - 1));
  }
  cout << ans << endl;
  return 0;
}
