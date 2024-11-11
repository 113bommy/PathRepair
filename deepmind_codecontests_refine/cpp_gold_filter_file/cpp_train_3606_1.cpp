#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = -INT_MIN;
  for (int i = 0; i < n; i++) {
    int b = sqrt(a[i]);
    if (b * b != a[i]) {
      if (ans < a[i]) {
        ans = a[i];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
