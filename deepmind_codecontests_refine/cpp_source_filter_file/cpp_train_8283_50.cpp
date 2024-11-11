#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, a1, a2, a3, a4, b1, b2, ans;
int main() {
  cin >> a, b, c, d;
  a1 = a ^ b;
  a2 = c | d;
  a3 = c & b;
  a4 = d ^ a;
  b1 = a1 & a2;
  b2 = a3 | a4;
  ans = b1 ^ b2;
  cout << ans;
}
