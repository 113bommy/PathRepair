#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long s, a, b, c;
    cin >> s >> a >> b >> c;
    long long f = s / (a * c);
    long long ans = (f * (a + b)) + ((s - (f * a * c)) / c);
    cout << ans << '\n';
  }
  return 0;
}
