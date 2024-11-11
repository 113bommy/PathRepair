#include <bits/stdc++.h>
using namespace std;
long long prec(long long a, long long b, long long l) {
  long long x = min(a - b, l);
  return a < b ? 0 : ((x + 1) * (x + 2) / 2);
}
int main() {
  long long a, b, c, l, ans, p = 0;
  cin >> a >> b >> c >> l;
  ans = (l + 1) * (l + 2) * (l + 3) / 6;
  while (l + 1) {
    ans -=
        (prec(a + p, b + c, l) + prec(b + p, a + c, l) + prec(c + p, a + b, l));
    p++;
    l--;
  }
  cout << ans;
}
