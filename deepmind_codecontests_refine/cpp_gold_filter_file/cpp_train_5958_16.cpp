#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, g, b;
    cin >> n >> g >> b;
    long long int need = n / 2;
    if (n % 2) need++;
    if (need <= g) {
      cout << n << endl;
    } else {
      long long int div = need / g;
      long long int res;
      if (need % g) {
        res = div * (g + b);
        res += (need % g);
      } else {
        res = div * (g + b);
        res -= b;
      }
      cout << max(n, res) << endl;
    }
  }
  return 0;
}
