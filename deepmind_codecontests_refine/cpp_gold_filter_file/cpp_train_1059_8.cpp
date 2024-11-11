#include <bits/stdc++.h>
using namespace std;
long long k;
double f(long long x) {
  double res = 0;
  long long num = 0, q, p = 1;
  for (p = 1; p * 10 - 1 <= x; p = p * 10) {
    num++;
    q = p * 10 - 1;
    res += 1.0 * num * (x - p + 1 + x - q + 1) * (q - p + 1) / 2;
  }
  q = x;
  res += 1.0 * (num + 1) * (x - p + 1 + x - q + 1) * (q - p + 1) / 2;
  return res;
}
double ff(long long x) {
  double res = 0;
  long long num = 0, q, p = 1;
  for (p = 1; p * 10 - 1 <= x; p = p * 10) {
    num++;
    q = p * 10 - 1;
    res += 1.0 * num * (q - p + 1);
  }
  q = x;
  res += 1.0 * (num + 1) * (q - p + 1);
  return res;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    cin >> k;
    if (k == 1) {
      puts("1");
      continue;
    }
    long long L = 0, R = 1e10, mid, x;
    while (L <= R) {
      mid = L + R >> 1;
      if (f(mid) < k)
        x = mid, L = mid + 1;
      else
        R = mid - 1;
    }
    k -= (long long)f(x);
    L = 0, R = x + 1;
    long long y;
    while (L <= R) {
      mid = L + R >> 1;
      if (ff(mid) < k)
        y = mid, L = mid + 1;
      else
        R = mid - 1;
    }
    k -= (long long)ff(y);
    y++;
    int tmp = y, len = 0;
    while (tmp) tmp /= 10, len++;
    int ans;
    k = len - k + 1;
    while (k) {
      ans = y % 10;
      y /= 10;
      k--;
    }
    cout << ans << '\n';
  }
}
