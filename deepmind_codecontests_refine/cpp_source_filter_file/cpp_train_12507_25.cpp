#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  int a[n][2];
  for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];
  cin >> k;
  for (int i = 0; i < n; ++i) {
    if (a[i][0] <= k && k <= a[i][1]) {
      cout << n - i - 1;
      return 0;
    }
  }
}
