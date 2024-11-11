#include <bits/stdc++.h>
using namespace std;
int a[2006], ans, d, n;
int main() {
  cin >> d >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i < n - 1) ans += (d - a[i]);
  }
  cout << ans;
  return 0;
}
