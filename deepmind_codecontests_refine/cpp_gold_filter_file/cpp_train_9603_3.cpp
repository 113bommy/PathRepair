#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int res;
    a = a - b;
    if (a <= 0) {
      cout << b << "\n";
      continue;
    }
    if (c - d <= 0) {
      cout << "-1\n";
      continue;
    }
    res = (a + c - d - 1) / (c - d);
    res = (long long int)c * res;
    res = b + res;
    cout << res << "\n";
  }
  return 0;
}
