#include <bits/stdc++.h>
using namespace std;
long long b, d, s;
int main() {
  cin >> b >> d >> s;
  long long ma = max(max(b, d), s);
  if (b == d && b == s) {
    cout << "0" << endl;
    return 0;
  }
  int ans = 0;
  if (ma != b) {
    ans += ma - b - 1;
  }
  if (ma != d) {
    ans += ma - d - 1;
  }
  if (ma != s) {
    ans += ma - s - 1;
  }
  cout << ans << endl;
  return 0;
}
