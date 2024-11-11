#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  n *= 6;
  bool flag = false;
  if (a > b) {
    swap(a, b);
    flag = true;
  }
  long long ans = (long long)9e18;
  long long ax = -1, ay = -1;
  for (long long xx = 1; xx <= n; xx++) {
    long long x = xx;
    long long y = (n + x - 1) / x;
    if (y < x) {
      break;
    }
    if (x < a) x = a;
    if (y < b) y = b;
    if (x * y <= ans) {
      ans = x * y;
      ax = x;
      ay = y;
    }
  }
  if (flag) {
    swap(ax, ay);
  }
  cout << ans << endl;
  cout << ax << " " << ay << endl;
  return 0;
}
