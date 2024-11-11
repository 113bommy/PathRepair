#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long n;
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
  long long T = read();
  while (T--) {
    long long a = read(), b = read(), c = read(), d = read(), k = read();
    long long x = a / c + ((a % c) > 0);
    long long y = k - x;
    if (d * y > b) {
      cout << x << " " << y << endl;
    } else
      puts("-1");
  }
}
