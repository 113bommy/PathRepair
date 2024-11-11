#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  long long x[n];
  x[n - 1] = a[n - 1];
  ans += a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (x[i + 1] == 1) {
      break;
    }
    if (a[i] < x[i + 1]) {
      x[i] = a[i];
      ans += x[i];
    } else {
      x[i] = x[i + 1] - 1;
      ans += x[i];
    }
  }
  cout << ans;
  return 0;
}
