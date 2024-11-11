#include <bits/stdc++.h>
using namespace std;
long long check(long long a) {
  long long x = 1;
  while (x * x < a) {
    x++;
  }
  return x;
}
int main() {
  long long n, a;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    long long k = check(a);
    if (a >= (k * k - k + 1))
      cout << k << " " << k - (a - (k * k - k + 1)) << endl;
    else
      cout << k - ((k * k - k + 1) - a) << " " << k << endl;
  }
  return 0;
}
