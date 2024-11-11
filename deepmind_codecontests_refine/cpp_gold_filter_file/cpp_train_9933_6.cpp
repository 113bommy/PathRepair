#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int i = 0;
  int a[n];
  long long csum = 0;
  while (i < n) {
    cin >> a[i];
    if (i < k) {
      csum += a[i];
    }
    i++;
  }
  long long min = csum;
  int ans = 0;
  for (int i = 1; i < n - k + 1; i++) {
    csum += a[i + k - 1] - a[i - 1];
    if (csum < min) {
      min = csum;
      ans = i;
    }
  }
  cout << ans + 1 << '\n';
}
