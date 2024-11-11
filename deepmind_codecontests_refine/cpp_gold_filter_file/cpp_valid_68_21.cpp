#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  cin >> tc;
  while (tc-- > 0) {
    long long n;
    cin >> n;
    long long s = sqrt(n);
    long long t = (s * (s + 1)) + 1;
    long long r, c, check;
    if (s * s == n) {
      r = s;
      c = 1;
    } else {
      if (n == t) {
        r = s + 1;
        c = s + 1;
      } else if (n > t) {
        check = n - t;
        r = s + 1;
        c = s + 1 - check;
      } else if (n < t) {
        check = t - n;
        r = s + 1 - check;
        c = s + 1;
      }
    }
    cout << r << " " << c << endl;
  }
  return 0;
}
