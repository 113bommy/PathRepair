#include <bits/stdc++.h>
using namespace std;
long long i, m, n, sum, k;
int main() {
  cin >> n >> m >> k;
  if (k < n) {
    cout << k + 1 << " " << 1;
    return 0;
  }
  k -= n;
  long long x = (k) / (m - 1);
  long long y = (k) % (m - 1);
  x = n - x;
  if (x % 2 == 0)
    y += 2;
  else
    y = m - y;
  cout << x << " " << y;
}
