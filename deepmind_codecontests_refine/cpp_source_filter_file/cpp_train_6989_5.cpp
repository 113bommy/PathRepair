#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
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
long long die = 0;
const double eps = 1e-8;
const long long mod = 1e9 + 7;
const long long N1 = 1e6 + 5;
const long long N2 = 1e5 + 5;
long long k;
void sol1() {
  long long x = k + 2000;
  cout << 2000 << endl;
  cout << -1 << " ";
  for (long long i = (1); i <= (1998); i++)
    if (x > 1e6) {
      cout << 1e6 << " ";
      x -= 1e6;
    } else {
      cout << 0 << " ";
    }
  cout << x;
}
void rd() {
  k = read();
  sol1();
}
signed main() { rd(); }
