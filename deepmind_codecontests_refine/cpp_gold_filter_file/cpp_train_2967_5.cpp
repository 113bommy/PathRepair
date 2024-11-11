#include <bits/stdc++.h>
using namespace std;
bool cs(int n) {
  if (n == 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
bool ch(int n) {
  int n1 = 0, t = n;
  while (t != 0) {
    n1 = n1 * 10 + t % 10;
    t /= 10;
  }
  if (n1 == n) {
    return true;
  }
  return false;
}
int main() {
  int p, q;
  cin >> p >> q;
  int ss = 0, sh = 0;
  int ans = 0;
  for (int i = 1; i <= 2123456; i++) {
    if (cs(i)) {
      ss++;
    }
    if (ch(i)) {
      sh++;
    }
    if (ss * q <= sh * p) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
