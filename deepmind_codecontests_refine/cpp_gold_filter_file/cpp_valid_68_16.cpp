#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l = 1, r = 1e5;
    while (l < r) {
      int mid = (l + r) / 2;
      long long p = (long long)mid * mid;
      if (p >= n)
        r = mid;
      else
        l = mid + 1;
    }
    int p = l * l;
    if (n > p - l)
      cout << l << " " << p - n + 1 << endl;
    else
      cout << l - ((p - l + 1) - n) << " " << l << endl;
  }
  return 0;
}
