#include <bits/stdc++.h>
using namespace std;
long long n, m, sum, mi, ma;
inline long long read() {
  long long ret = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    ret = ret * 10 + c - 48;
    c = getchar();
  }
  if (f) return -ret;
  return ret;
}
signed main() {
  n = read();
  m = read();
  if (m == 0) {
    cout << n << " " << n;
    return 0;
  }
  for (long long i = 1; i <= n; i++) {
    sum += i;
    if (sum >= m) {
      mi = i + 1;
      break;
    }
  }
  ma = max(0ll, n - m * 2);
  cout << ma << " " << n - mi;
}
