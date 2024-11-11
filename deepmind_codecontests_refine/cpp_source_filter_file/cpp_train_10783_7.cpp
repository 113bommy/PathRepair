#include <bits/stdc++.h>
using namespace std;
int bis(long long x) {
  long long be = 0;
  long long ed = 1e9;
  long long mid;
  long long res = 1e9;
  while (be <= ed) {
    mid = (be + ed) / 2;
    if (mid * (mid + 1) / 2 >= x) {
      res = mid;
      ed = mid - 1;
    } else {
      be = mid + 1;
    }
  }
  return res;
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << n;
    return 0;
  }
  cout << m + bis(n - m);
}
