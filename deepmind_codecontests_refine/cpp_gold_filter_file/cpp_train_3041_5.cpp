#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1e3;
long long n, a, b, w, res;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a == 0) {
      res += min(b, w);
      b = 0;
      w = 0;
    } else if (a % 2 == 0) {
      b += a / 2;
      w += a / 2;
    } else {
      if (i % 2 == 1) {
        b += a / 2 + 1;
        w += a / 2;
      } else {
        b += a / 2;
        w += a / 2 + 1;
      }
    }
  }
  res += min(b, w);
  cout << res << endl;
}
