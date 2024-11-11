#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, n, m, t, d, temp, c1 = 0, c2 = 0, ans, cnt = 0;
  cin >> n >> t >> k >> d;
  if (k >= n) {
    cout << "NO" << endl;
    return 0;
  }
  m = (n / k) * t;
  if (n % k != 0) m += t;
  while (cnt < n) {
    c1++;
    if (c1 % t == 0) {
      cnt += k;
    }
    if (c1 >= n) {
      break;
    }
    if ((c1 - d) > 0 && (c1 - d) % t == 0) {
      cnt += k;
    }
    if (c1 >= n) {
      break;
    }
  }
  if (c1 < m)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
