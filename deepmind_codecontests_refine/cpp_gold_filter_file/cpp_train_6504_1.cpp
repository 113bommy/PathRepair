#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n = pow(2, t + 1) - 2;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = n; i >= 2; i = i - 2) {
    if (a[i] < a[i - 1]) {
      swap(a[i], a[i - 1]);
    }
    ans = ans + a[i] - a[i - 1];
    a[i / 2 - 1] = a[i / 2 - 1] + a[i];
  }
  cout << ans;
  return 0;
}
