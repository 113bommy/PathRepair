#include <bits/stdc++.h>
using namespace std;
long long getlen(long long n, long long k) {
  long long temp = 1;
  k--;
  long long len = 1;
  while (temp < n && k >= 4 * len - 1) {
    k -= 4 * len - 1;
    temp++;
    len *= 2;
  }
  return n - temp;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    if (n == 3 && k == 3) {
      cout << "NO" << endl;
      continue;
    }
    long long _n = n, _k = k;
    if (n <= 60) {
      long long temp = 1;
      while (_n--) {
        _k -= temp;
        temp *= 4;
      }
      if (_k > 0)
        cout << "NO" << endl;
      else
        cout << "YES"
             << " " << getlen(n, k) << endl;
    } else
      cout << "YES"
           << " " << getlen(n, k) << endl;
  }
  return 0;
}
