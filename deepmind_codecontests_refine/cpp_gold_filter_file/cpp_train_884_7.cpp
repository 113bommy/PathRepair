#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  while (cin >> n) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long d = b - c;
    if (n < a && n < b)
      cout << 0 << endl;
    else if (a <= d || n < b)
      cout << n / a << endl;
    else {
      long long ans = (n - b + d) / d;
      n -= ans * d;
      cout << ans + n / a << endl;
    }
  }
  return 0;
}
