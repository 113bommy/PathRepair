#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;
  long long co = 0;
  long long ans = 0;
  co = 0;
  char prev = '1';
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && prev != s[i]) {
      co++;
    }
    prev = s[i];
  }
  if (co == 0) {
    cout << 0 << "\n";
    return 0;
  }
  if (co == 1) {
    cout << min(y, co * y + x) << "\n";
    return 0;
  }
  ans = min(co * y, (co - 1) * x + y);
  cout << ans << "\n";
}
