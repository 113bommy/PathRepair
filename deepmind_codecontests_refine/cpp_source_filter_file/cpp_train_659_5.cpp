#include <bits/stdc++.h>
using namespace std;
int main() {
  long long(y);
  scanf("%lld", &(y));
  long long(k), (n);
  scanf("%lld%lld", &(k), &(n));
  int x = y % k;
  x = k - x;
  if (x + y < n)
    while (x + y < n) {
      cout << x << " ";
      x += k;
    }
  else
    cout << "-1";
  return 0;
}
