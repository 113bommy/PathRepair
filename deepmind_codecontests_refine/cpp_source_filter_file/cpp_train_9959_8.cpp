#include <bits/stdc++.h>
using namespace std;
long long a[1005], sum[1005];
int main() {
  int n;
  long long w;
  cin >> n >> w;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sum[0] = 0;
  long long big = 0, small = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
    if (sum[i] > 0) big = max(big, sum[i]);
    if (sum[i] < 0) small = min(small, sum[i]);
  }
  if (big > w || abs(small) > w)
    cout << "-1" << endl;
  else {
    long long l = abs(small), r = w - big;
    if (l > r)
      cout << "-1" << endl;
    else
      cout << r - l + 1 << endl;
  }
}
