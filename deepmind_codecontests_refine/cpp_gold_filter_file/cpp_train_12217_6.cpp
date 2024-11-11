#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long N = 1e5 + 10;
const long long mod = 1e9 + 7;
long long l, r;
int main() {
  scanf("%I64d %I64d", &l, &r);
  long long L = 0, R = 0;
  l--;
  if (l < 10)
    L = l;
  else {
    long long t = l / 10 + 9;
    long long y = l % 10;
    while (l > 9) l /= 10;
    if (l > y) t--;
    L = t;
  }
  if (r < 10)
    R = r;
  else {
    long long t = r / 10 + 9;
    long long y = r % 10;
    while (r > 9) r /= 10;
    if (r > y) t--;
    R = t;
  }
  cout << R - L;
  return 0;
}
