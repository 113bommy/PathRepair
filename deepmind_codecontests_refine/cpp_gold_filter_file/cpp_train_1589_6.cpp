#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, y, n;
    cin >> x >> y >> n;
    if (x > n) {
      cout << y << endl;
    } else {
      long long int m = n / x;
      if ((m * x + y) <= n)
        cout << m * x + y << endl;
      else
        cout << (m - 1) * x + y << endl;
    }
  }
}
