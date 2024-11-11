#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << n << endl;
    return 0;
  }
  n -= m;
  long long s = 1L, e = 1000000001L;
  while (s < e) {
    long long mid = (s + e) / 2;
    if (mid * (mid + 1) / 2 >= n) {
      e = mid;
    } else {
      s = mid + 1;
    }
  }
  cout << s + m << endl;
  return 0;
}
