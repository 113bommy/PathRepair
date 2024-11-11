#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0, mark = 1;
  int t = getchar();
  while (t < '0' || t > '9') {
    if (t == '-') mark = -1;
    t = getchar();
  }
  while (t <= '9' && t >= '0') {
    ans = (ans << 3) + (ans << 1) + t - '0';
    t = getchar();
  }
  return ans * mark;
}
int qmi(int a, int b, int p) {
  int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 5, p = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int(Loop_var) = read();
  while (Loop_var--)
    for (int _ = 1; _ <= (9); _++)
      for (int __ = 1; __ <= (10); __++) {
        char t = getchar();
        if (t == '9')
          putchar('1');
        else
          putchar(t);
      }
  return 0;
}
