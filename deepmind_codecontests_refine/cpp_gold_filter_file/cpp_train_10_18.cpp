#include <bits/stdc++.h>
using namespace std;
void Solve() {
  long long int l, r, d;
  scanf("%lld %lld %lld", &l, &r, &d);
  if (l <= d) {
    if (r % d == 0)
      r /= d;
    else
      r /= d;
    r++;
    d *= r;
    printf("%lld\n", d);
  } else
    printf("%lld\n", d);
}
int main() {
  long long int t;
  scanf("%lld", &t);
  while (t) {
    t--;
    Solve();
  }
  return 0;
}
