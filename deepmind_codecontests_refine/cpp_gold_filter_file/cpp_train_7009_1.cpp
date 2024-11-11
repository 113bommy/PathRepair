#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long bsearch(long long b, long long y, long long l, long long r) {
  if (l == r) {
    if (y * l <= b)
      return l;
    else
      return -1;
  } else {
    long long mid = l + (r - l + 1) / 2;
    if (y * mid <= b)
      return bsearch(b, y, mid, r);
    else
      return bsearch(b, y, l, mid - 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt = 1;
  while (tt--) {
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long g = gcd(x, y);
    x = x / g;
    y = y / g;
    long long ans = bsearch(b, y, 0, a / x);
    cout << (ans * x) << " " << (ans * y) << endl;
  }
  return 0;
}
