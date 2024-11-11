#include <bits/stdc++.h>
using namespace std;
int main() {
  long i, k, n, mlt;
  while (cin >> n) {
    long long d;
    mlt = 1;
    if (n < 3) {
      cout << "-1" << endl;
      continue;
    }
    while (n % 2 == 0) {
      n = n / 2;
      mlt = mlt * 2;
    }
    if (n == 1)
      cout << 3 * (mlt / 4) << " " << 5 * (mlt / 4) << endl;
    else {
      d = (n * n - 1) / 2;
      cout << d * mlt << " " << (d + 1) * mlt << endl;
    }
  }
  return 0;
}
