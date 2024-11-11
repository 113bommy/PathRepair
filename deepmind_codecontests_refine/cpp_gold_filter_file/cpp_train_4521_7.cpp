#include <bits/stdc++.h>
using namespace std;
long double t[5000005], h[5000005];
int main() {
  int n, m;
  cin >> n >> m;
  int nn = 1000000 / m;
  for (int i = 1; i <= n; i++) {
    cin >> t[0];
    long double ans = 0.0;
    for (int j = 1; j <= m; j++) {
      cin >> t[j];
      long double hh = (t[j] - t[j - 1]) / nn;
      for (int k = 1; k <= nn; k++) {
        long double x = t[j - 1] + hh * k;
        if (x > h[(j - 1) * nn + k]) {
          ans += x - h[(j - 1) * nn + k];
          h[(j - 1) * nn + k] = x;
        }
      }
    }
    cout << ans / nn << endl;
  }
  return 0;
}
