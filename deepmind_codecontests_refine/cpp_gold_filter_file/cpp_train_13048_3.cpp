#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 6;
bool check[nax] = {0};
int main() {
  long long n, d, m, l;
  cin >> n >> d >> m >> l;
  long long res = 0, cnt = 0;
  check[0] = true;
  while (res % m <= l && res / m < n) {
    res += d;
    if (!check[res % m])
      check[res % m] = true;
    else {
      if (d == 1)
        cout << (n - 1) * m + l + 1;
      else
        cout << (((n - 1) * m + l) / d * d + d);
      return 0;
    }
  }
  cout << res;
}
