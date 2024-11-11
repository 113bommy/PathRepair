#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    gcd(b, a % b);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int r, b, k;
    cin >> r >> b >> k;
    if (r < b) {
      long long w = gcd(b, r);
      r = r / w;
      b = b / w;
      long long tmp = r * (k - 1) + 1;
      if (tmp < b) {
        cout << "REBEL" << endl;
      } else
        cout << "OBEY" << endl;
    } else {
      long long w = gcd(r, b);
      r = r / w;
      b = b / w;
      long long tmp = b * (k - 1) + 1;
      if (tmp < r)
        cout << "REBEL" << endl;
      else
        cout << "OBEY" << endl;
    }
  }
  return 0;
}
