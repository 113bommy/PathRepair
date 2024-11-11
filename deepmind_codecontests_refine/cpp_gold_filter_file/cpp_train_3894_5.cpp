#include <bits/stdc++.h>
using namespace std;
void judge() {}
int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
int main() {
  judge();
  int a, b, c;
  cin >> a >> b >> c;
  int mx = min(min(min(a, b), c) + 1, 3);
  int m = 0, ans = 0;
  while (m < mx) {
    int val = (a - m) / 3 + (b - m) / 3 + (c - m) / 3;
    if (val > 0) ans = max(m + val, ans);
    m++;
  }
  cout << ans;
}
