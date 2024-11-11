#include <bits/stdc++.h>
using namespace std;
long long int d_sum(long long int a) {
  long long int res = 0;
  while (a) {
    res += a % 10;
    a /= 10;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int r, g, b, w;
    cin >> r >> g >> b >> w;
    int a = min(r, min(g, b));
    w += a;
    r -= a;
    g -= a;
    b -= a;
    if ((r % 2 + w % 2 + g % 2 + b % 2 > 1) &&
        ((w - (a > 0)) % 2 + (r + a > 0) % 2 + (g + a > 0) % 2 +
             (b + a > 0) % 2 >
         1))
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
}
