#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100100], x, y, z, k, r, w, t;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  t = 0;
  k = 0;
  for (int i = 0; i < m; i++) {
    cin >> x;
    while (x > k + a[t]) {
      k += a[t];
      t++;
    }
    cout << t + 1 << ' ' << x - k << endl;
  }
  return 0;
}
