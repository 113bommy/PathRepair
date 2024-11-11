#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool f = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ '0');
    c = getchar();
  }
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
string s;
long long a[11] = {2, 7, 2, 3, 3, 3, 2, 5, 1, 2};
signed main() {
  ios::sync_with_stdio(0);
  cin >> s;
  cout << a[s[0] - '0'] * a[s[1] - '0'];
  return 0;
}
