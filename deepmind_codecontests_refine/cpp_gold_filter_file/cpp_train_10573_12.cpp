#include <bits/stdc++.h>
using namespace std;
int minimum(int a, int b, int c) {
  int x;
  if (a <= b && a <= c) {
    x = a;
  } else if (b <= a && b <= c) {
    x = b;
  } else {
    x = c;
  }
  return x;
}
int main() {
  int k2, k3, k5, k6;
  cin >> k2 >> k3 >> k5 >> k6;
  int min1 = minimum(k2, k5, k6);
  int min2 = min((k2 - min1), k3);
  int ans = 32 * min2 + 256 * min1;
  cout << ans;
  return 0;
}
