#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> d;
    if (b >= a)
      printf("%lld\n", b);
    else if (c > d)
      printf("%lld\n", b + c * (long long)ceil(1.0 * (a - b) / (c - d)));
    else
      printf("-1");
  }
  return 0;
}
