#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ndigits = 0;
  int d = 1;
  long long f = 1;
  while (n >= f * 10 - 1) {
    long long cnt = f * 9;
    ndigits += d * cnt;
    ++d;
    f *= 10;
  }
  ndigits += d * (n - f + 1);
  cout << ndigits << endl;
}
