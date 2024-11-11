#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[100];
  int a, b, c, d, e, x, y;
  int ind = 0;
  int maxi = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> x >> y >> a >> b >> c >> d >> e;
    if (x * 100 - y * 50 + a + b + c + d + e > maxi) {
      maxi = x * 100 - y * 50 + a + b + c + d + e;
      ind = i;
    }
  }
  cout << s[ind];
  return 0;
}
