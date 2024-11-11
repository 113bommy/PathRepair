#include <bits/stdc++.h>
using namespace std;
long long dd(long long x, long long y) { return x > y ? x : y; }
long long xx(long long x, long long y) { return x < y ? x : y; }
int main() {
  long long n, q, w;
  long long mks = 0, mii = 1000000001;
  cin >> n;
  int a, b, c, i, j;
  for (i = 1; i <= (int)sqrt(n) + 1; i++) {
    if (n % i == 0) {
      q = n / i;
      for (j = 1; j <= (int)sqrt(q) + 1; j++) {
        if (q % j == 0) {
          w = q / j;
          mks = dd(mks, (long long)(i + 1) * (j + 2) * (w + 2));
          mks = dd(mks, (long long)(i + 2) * (j + 1) * (w + 2));
          mks = dd(mks, (long long)(i + 2) * (j + 2) * (w + 1));
          mii = xx(mii, (long long)(i + 1) * (j + 2) * (w + 2));
          mii = xx(mii, (long long)(i + 2) * (j + 1) * (w + 2));
          mii = xx(mii, (long long)(i + 2) * (j + 2) * (w + 1));
        }
      }
    }
  }
  mks -= n;
  mii -= n;
  cout << mii << " " << mks;
}
