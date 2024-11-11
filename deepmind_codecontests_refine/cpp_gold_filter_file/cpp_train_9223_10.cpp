#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long x, y;
  while (n--) {
    scanf("%I64d%I64d", &x, &y);
    long long bla = x * y;
    long long bb = ceil(cbrt(bla * 1.0));
    bool k = 1;
    if (bb * bb * bb != bla)
      cout << "No\n";
    else if ((x % bb == 0) && (y % bb == 0))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
