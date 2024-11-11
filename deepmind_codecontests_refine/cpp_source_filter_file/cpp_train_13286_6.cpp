#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
inline void read(long long& x) {
  int f = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (f = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
inline void read(int& x) {
  long long t;
  read(t);
  x = t;
}
int main() {
  long long n, k;
  read(n);
  read(k);
  long long ans = 1;
  if (k >= 2) ans += n * (n - 1) / 2;
  if (k >= 3) ans += n * (n - 1) / 2 * (n - 2) / 3;
  if (k >= 4) ans += n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
  cout << ans;
  return 0;
}
