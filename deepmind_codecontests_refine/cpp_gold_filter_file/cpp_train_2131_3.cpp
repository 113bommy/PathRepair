#include <bits/stdc++.h>
using namespace std;
long long i, j, x, y, z, ans, d, m, k, c, n, low, high, s, f, w;
string s1, s2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  z = n;
  for (i = 1; i <= 50; ++i) {
    n++;
    k = abs(n);
    while (k) {
      if (k % 10 == 8) {
        cout << abs(n - z);
        return 0;
      }
      k /= 10;
    }
  }
}
