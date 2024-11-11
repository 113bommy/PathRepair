#include <bits/stdc++.h>
using namespace std;
int helper(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
int solve() {
  int a, b;
  cin >> a >> b;
  if (a == 1) {
    if (b == 0) return 1;
    if (b == 1)
      return 3;
    else
      return 2;
  } else {
    int na = a - 1;
    int d = helper(a - 1);
    if (d == b)
      return a;
    else if (d ^ b == a)
      return a + 2;
    else if (a == b)
      return a + 2;
    else if (d == 0) {
      if (b == 0)
        return a;
      else
        return a + 1;
    } else if (d == 1) {
      if (b == 1)
        return a;
      else
        return a + 1;
    } else
      return a + 1;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
