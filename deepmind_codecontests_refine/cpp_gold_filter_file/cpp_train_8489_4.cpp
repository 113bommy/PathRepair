#include <bits/stdc++.h>
using namespace std;
int n, k, t, b, sum;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout << boolalpha << setprecision(6) << fixed;
  clog.copyfmt(cout);
  cin >> n >> k >> t;
  double d = n * k, p = t / 100.0;
  for (int i = 0; i < n; ++i) {
    if (i) cout << " ";
    if (b)
      cout << 0;
    else {
      if ((sum + k) / d <= p + 1e-8) {
        cout << k;
        sum += k;
      } else {
        for (b = 1; (sum + b) / d <= p; ++b)
          ;
        cout << b - 1;
      }
    }
  }
  cout << endl;
  return 0;
}
