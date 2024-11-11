#include <bits/stdc++.h>
using namespace std;
long n, a;
int main() {
  long mi = 1000000000;
  long ma = 0;
  cin >> n;
  for (long i = 0; i < n; i++) {
    cin >> a;
    if (a < mi) {
      mi = a;
    }
    if (a > ma) {
      ma = a;
    }
  }
  cout << ma - mi - n + 1;
  return 0;
}
