#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[10], n, max = -1, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > max) max = a[i];
  }
  ans = max ^ a[n];
  cout << ans << endl;
  return 0;
}
