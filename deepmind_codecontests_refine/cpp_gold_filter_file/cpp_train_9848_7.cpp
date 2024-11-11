#include <bits/stdc++.h>
using namespace std;
int k, n;
int a[2201];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += a[i];
  }
  cout << ans;
  return 0;
}
