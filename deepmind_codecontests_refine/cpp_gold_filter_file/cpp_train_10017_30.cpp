#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0, n, a[1000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if ((sum - a[i]) % 2 == 0) ans++;
  }
  cout << ans;
  return 0;
}
