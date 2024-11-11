#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, big, f, sum;
  cin >> n >> k;
  int a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  if ((b[0] > k))
    sum = a[0] - (b[0] - k);
  else if (b[0] < k)
    sum = a[0];
  for (i = n - 1; i > 0; i--) {
    if ((a[i] - (b[i] - k) > sum && b[i] > k))
      sum = a[i] - (b[i] - k);
    else if (b[i] <= k && a[i] > sum)
      sum = a[i];
  }
  cout << sum;
}
