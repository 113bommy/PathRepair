#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  string ans = "";
  ans += a[0];
  int n = a.size();
  for (int i = 1; i < n; i++) {
    if (a[i] <= b[0]) {
      ans += a[i];
    } else {
      ans += b[0];
      break;
    }
    if (i + 1 == n) ans += b[0];
  }
  if (ans.size() == 1) ans += b[0];
  cout << ans;
}
