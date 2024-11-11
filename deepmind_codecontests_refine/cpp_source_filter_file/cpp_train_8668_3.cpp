#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long digitSum(long long a) {
  long long ret = 0;
  while (a) {
    ret += a % 10;
    a /= 10;
  }
  return ret;
}
bool is7(long long x) {
  if (x % 7 == 0) {
    return true;
  }
  while (x) {
    if (x % 10 == 7) {
      return true;
    }
    x /= 10;
  }
  return false;
}
signed main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long x, y, k;
    cin >> x >> y >> k;
    cout << ((((k * y + k) - 1) / (x - 1)) +
             ((((k * y + k) - 1) % (x - 1)) != 0))
         << endl;
  }
  return 0;
}
