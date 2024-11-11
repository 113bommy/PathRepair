#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, s, f, t, l, l1, k;
  cin >> n;
  cin >> m;
  vector<long long> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> s;
    cin >> f;
    cin >> t;
    k = 0;
    if (s == f) {
      a[i] = t;
    } else {
      l = t / (2 * m - 2);
      l1 = t - l * (2 * m - 2);
      k = k + l * (2 * m - 2);
      if (s < f) {
        if (l1 > s - 1) {
          k = k + 2 * m - 2;
          k = k + f - 1;
        } else {
          k = k + f - 1 - l1;
        }
      } else {
        if (l1 > m - 1 + m - s) {
          k = k + 2 * m - 2;
        }
        k = k + m - 1;
        k = k + m - f;
      }
      a[i] = k;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
}
