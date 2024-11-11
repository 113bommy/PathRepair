#include <bits/stdc++.h>
using namespace std;
int a[2000000];
int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long l = 0, r = 0;
  long long ans = 0;
  for (; l < n; l++) {
    for (; r < n - 1; r++)
      if (a[r] - a[l] > d) break;
    while (a[r] - a[l] > d) r--;
    if (a[r] - a[l] <= d && r - l + 1 >= 3) ans += (r - l) * (r - l - 1) / 2;
  }
  cout << ans;
  return 0;
}
