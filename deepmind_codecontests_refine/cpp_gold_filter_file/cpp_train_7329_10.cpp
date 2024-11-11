#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  string s;
  cin >> s;
  int ans = 0, p = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum -= a[i];
    if (s[i] == '1') {
      ans = max(ans, sum + p);
      p += a[i];
    }
  }
  ans = max(ans, p);
  cout << ans << endl;
}
