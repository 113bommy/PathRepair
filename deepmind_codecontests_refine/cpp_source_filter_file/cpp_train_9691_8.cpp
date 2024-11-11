#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, a[100];
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 2;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] - a[i] >= 3 * d) {
      ans += 2;
    } else if (a[i + 1] - a[i] >= 2 * d) {
      ans += 1;
    }
  }
  cout << ans;
  return 0;
}
