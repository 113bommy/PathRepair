#include <bits/stdc++.h>
using namespace std;
long long a[] = {0, 1, 2, 9, 64, 625, 7776, 117649, 2097152};
const long long M = 1000000009ll;
int main(void) {
  std::ios::sync_with_stdio(false);
  long long k, n, m, t;
  while (cin >> n >> m) {
    n -= m;
    t = 1;
    k = n;
    while (k) {
      if (k & 1) t = t * n % M;
      n = n * n % M;
      k >>= 1;
    }
    cout << a[m] * t % M << endl;
  }
  return 0;
}
