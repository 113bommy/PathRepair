#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (k >= n)
    cout << "0 0 " << n;
  else {
    long long x = floor(n / (2 * (k + 1)));
    long long y = n / 2 - x;
    long long z = n - x - y;
    cout << x << " " << y << " " << z;
  }
}
