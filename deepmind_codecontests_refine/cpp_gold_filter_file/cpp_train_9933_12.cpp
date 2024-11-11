#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e5 + 10;
int h[SIZE], cum[SIZE], n, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> h[i];
  for (int i = 1; i <= n; i++) cum[i] = cum[i - 1] + h[i];
  int mn = 1e9, ans = 0;
  for (int i = n; i >= k; i--)
    if (cum[i] - cum[i - k] < mn) mn = cum[i] - cum[i - k], ans = i - k + 1;
  cout << ans << endl;
  return 0;
}
