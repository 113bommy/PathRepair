#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) cnt++;
  }
  if (cnt > 0)
    cout << n - cnt << endl;
  else {
    int ans = 1e9;
    int ff = 0;
    for (int i = 0; i < n; i++) {
      int g = a[i];
      int f = 0;
      int pos = i;
      for (int j = i + 1; j < n; j++) {
        g = gcd(g, a[j]);
        if (g == 1) {
          f = 1;
          pos = j;
          break;
        }
      }
      if (f) {
        ans = min(ans, pos - i + n - 1);
        ff = 1;
      }
    }
    if (ff)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
}
