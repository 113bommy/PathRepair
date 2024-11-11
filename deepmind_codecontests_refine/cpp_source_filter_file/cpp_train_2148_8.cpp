#include <bits/stdc++.h>
using namespace std;
int a[200050], last[200050], ans, mn, n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    last[a[i]] = i;
  }
  mn = 1e9;
  for (int i = 1; i <= (int)2e5; i++) {
    if (last[i] && last[i] < mn) {
      mn = last[i];
      ans = i;
    }
  }
  cout << ans;
  return 0;
}
