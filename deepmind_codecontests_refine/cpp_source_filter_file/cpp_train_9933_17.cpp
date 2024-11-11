#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  int ans, fin = 1000000000;
  for (int i = 0; i < n; i++) cin >> a[i];
  int sum = 0;
  for (int i = 0; i <= n - k; i++) {
    ;
    if (i == 0) {
      for (int j = i; j < i + k; j++) sum += a[j];
    } else
      sum = sum - a[i] + a[i + k - 1];
    if (sum < fin) {
      fin = sum;
      ans = i + 1;
    }
  }
  cout << ans;
  return 0;
}
