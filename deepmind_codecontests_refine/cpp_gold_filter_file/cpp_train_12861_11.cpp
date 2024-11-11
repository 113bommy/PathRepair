#include <bits/stdc++.h>
using namespace std;
long long m;
long long f(long long a) {
  long long res = 0;
  for (long long k = 2;; k++) {
    long long k3 = k * k * k;
    if (k3 > a) break;
    if (res > m - a / k3) return -1;
    res += a / k3;
  }
  return res;
}
int main() {
  cin >> m;
  long long l = 1, r = 9000000000000000000LL;
  while (l < r) {
    long long mid = (l + r) >> 1;
    long long rr = f(mid);
    if (rr >= m || rr == -1)
      r = mid;
    else
      l = mid + 1;
  }
  while (f(l - 1) == m) l--;
  cout << (f(l) == m ? l : -1) << endl;
  return 0;
}
