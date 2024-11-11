#include <bits/stdc++.h>
using namespace std;
long long f(long long n, long long k) {
  bool flag = 1;
  long long count = 0;
  if (k >= n) {
    return 1;
  }
  if (((((k - 1) * k) / 2) + 1) == n) {
    return k - 1;
  }
  while (flag) {
    n = n - k + 1;
    k--;
    count++;
    if (k >= n) {
      count++;
      flag = 0;
    } else if (((((k - 1) * k) / 2) + 1) == n) {
      count += k - 1;
      flag = 0;
    }
  }
  return count;
}
int main() {
  bool flag = 1;
  long long int S = 0, n, k, p, count = 0;
  cin >> n >> k;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (((((k - 1) * k) / 2) + 1) < n) {
    cout << -1 << endl;
    return 0;
  }
  if (k >= n) {
    cout << 1 << endl;
    return 0;
  }
  if (((((k - 1) * k) / 2) + 1) == n) {
    cout << k - 1 << endl;
    return 0;
  }
  long long l = 2, m, r = k, L, R;
  while (l < r) {
    m = (l + r) / 2;
    p = k - m + 1;
    if (p == 2)
      S = k - 1 + m;
    else
      S = m + (((p - 1) * (m + k - 1)) / 2);
    L = l;
    R = r;
    if (S == n) {
      cout << k - m + 1 << endl;
      return 0;
    } else if (S < n)
      r = m - 1;
    else
      l = m + 1;
  }
  m = (L + R) / 2;
  for (int i = 1; i < 5; i++) {
    if (m < n - 2) m++;
  }
  p = k - m + 1;
  if (p == 2)
    S = k - 1 + m;
  else
    S = m + (((p - 1) * (m + k - 1)) / 2);
  count = p;
  count += f(n - S, m - 1);
  cout << count << endl;
  return 0;
}
