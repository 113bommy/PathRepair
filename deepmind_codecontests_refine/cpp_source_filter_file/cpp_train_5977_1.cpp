#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b > a)
    return gcd(b, a);
  else if (a % b == 0)
    return b;
  else
    return gcd(b, b % a);
}
int main() {
  int n, i, j, common, large = -2147483647;
  cin >> n >> common;
  large = common;
  for (i = 1; i < n; i++) {
    cin >> j;
    if (j > large) large = j;
    common = gcd(j, common);
  }
  j = large / common - n;
  cout << (j % 2 ? "Alice" : "Bob") << endl;
  return 0;
}
