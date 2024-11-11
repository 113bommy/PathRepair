#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mx = -2501;
  cin >> n;
  string h;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    int a, b, c, d, e, s, u;
    cin >> s >> u >> a >> b >> c >> d >> e;
    int sum = 0;
    sum = a + b + c + d + e + 100 * s - 50 * u;
    if (sum > mx) {
      mx = sum;
      h = t;
    }
  }
  cout << h;
  return 0;
}
