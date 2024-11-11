#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, i, j, k, t, r, p;
  cin >> t;
  for (long long j = 0; j < t; j++) {
    cin >> n;
    r = 10 + 6 + 14;
    p = n - r;
    k = 0;
    if (p == 10 || p == 6 || p == 14) {
      r++;
      k = 1;
      p--;
    }
    if (n <= r) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      if (k == 1) {
        cout << "10 6 15"
             << " " << p << endl;
      } else {
        cout << "10 6 14"
             << " " << p << endl;
      }
    }
  }
  return 0;
}
