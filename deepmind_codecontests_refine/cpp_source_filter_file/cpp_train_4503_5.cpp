#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  long long res = 0;
  for (int r = c; r <= d; ++r) {
    int l = r - b + 1, t1, t2;
    if (l > c) break;
    l = max(l, a);
    if (l <= b) {
      res += (long long)(b - l + 1) * (c - b + 1);
      t1 = c - b;
      t2 = l - a;
    } else {
      res += c - l + 1;
      t1 = c - l;
      t2 = b - a;
    }
    int len, s;
    if (t1 >= t2) {
      len = t2;
      s = t1 - t2;
    } else {
      len = t1;
      s = t2 - t1;
    }
    res += (long long)(s)*len + (long long)(len) * (len + 1) / 2;
  }
  cout << res << endl;
  return 0;
}
