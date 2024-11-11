#include <bits/stdc++.h>
using namespace std;
int a[2000009];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, r;
    cin >> n >> r;
    int nn = pow(2, n);
    unsigned long long sum = 0;
    for (int i = 1; i <= pow(2, n); i++) {
      cin >> a[i];
      sum += a[i];
    }
    cout << setprecision(10);
    cout << (double)sum / (double)nn << endl;
    while (r--) {
      int x, y;
      cin >> x >> y;
      sum -= a[x + 1];
      a[x + 1] = y;
      sum += a[x + 1];
      cout << setprecision(10);
      cout << (double)sum / (double)nn << endl;
    }
  }
  return 0;
}
