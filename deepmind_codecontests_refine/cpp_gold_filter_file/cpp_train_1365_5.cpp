#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, k, f, g, v, t, y, z, j, d, x, m;
  cin >> n;
  cin >> d;
  vector<long long> a(n), b(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  x = a[d - 1] + b[0];
  k = 0;
  m = n - 1;
  for (i = 0; i < d - 1; i++) {
    if (a[i] + b[m] <= x) {
      m--;
      k++;
    }
  }
  cout << d - k << endl;
  return 0;
}
