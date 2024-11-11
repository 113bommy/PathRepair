#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
inline long long read() {
  int X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
inline void write(long long x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long n, m, k;
bool check(long long x) {
  if (k == 1 || k == n) {
    long long res = 0;
    if (x > n)
      res = ((x - n + 1) + x) * n / 2;
    else
      res = ((1 + x) * x / 2);
    return res <= m;
  } else {
    long long res1 = 0, res2 = 0;
    if (x > k)
      res1 = ((x - k + 1) + x) * k / 2;
    else
      res1 = (1 + x) * x / 2;
    if (x > n - k + 1)
      res2 = ((x - (n - k + 1) + 1) + x) * (n - k + 1) / 2;
    else
      res2 = (1 + x) * x / 2;
    return res1 + res2 - x <= m;
  }
}
int main() {
  cin >> n >> m >> k;
  m -= n;
  if (m == 0)
    cout << 1 << endl;
  else {
    long long l = 0, r = m;
    long long ans = 0;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (check(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    cout << ans << endl;
  }
  return 0;
}
