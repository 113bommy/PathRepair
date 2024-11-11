#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
pair<long long int, long long int> Ext_Gcd(long long int a, long long int b) {
  if (b == 0) return make_pair(1, 0);
  pair<long long int, long long int> result = Ext_Gcd(b, a % b);
  return make_pair(result.second, result.first - (a / b) * result.second);
}
long long int a1, b1, a2, b2, L, R;
int main() {
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &a1, &b1, &a2, &b2, &L, &R);
  L = max(L, max(b1, b2));
  long long int x = b2 - b1;
  long long int y = gcd(a1, a2);
  if (x % y != 0) {
    puts("0");
    return 0;
  }
  a1 /= y;
  a2 /= y;
  pair<long long int, long long int> res = Ext_Gcd(a1, a2);
  res.first *= x;
  res.second *= x;
  res.first %= a2;
  long long int where = res.first * a1 + b1;
  long long int diff = a1 * a2 * y;
  where = where + ((L - where) / diff) * diff;
  if (where < L) where += diff;
  long long int r = 1;
  if (where > R) {
    puts("0");
    return 0;
  }
  r += (R - where) / diff;
  printf("%I64d\n", r);
  return 0;
}
