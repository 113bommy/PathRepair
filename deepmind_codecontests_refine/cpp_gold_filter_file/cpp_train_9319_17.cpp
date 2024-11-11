#include <bits/stdc++.h>
using namespace std;
int a[1111], b[1111];
int main() {
  int n;
  cin >> n;
  for (int i = int(1); i <= int(n); i++) cin >> a[i];
  for (int i = int(1); i <= int(n); i++) cin >> b[i];
  int ans = 0;
  for (int l = int(1); l <= int(n); l++) {
    for (int r = int(l); r <= int(n); r++) {
      int x = 0, y = 0;
      for (int i = int(l); i <= int(r); i++) x |= a[i], y |= b[i];
      ans = max(ans, x + y);
    }
  }
  cout << ans;
}
