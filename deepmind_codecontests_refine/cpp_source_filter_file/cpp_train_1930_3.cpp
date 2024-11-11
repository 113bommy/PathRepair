#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-10;
inline int read() {
  static char ch;
  bool sgn = false;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') sgn = true;
  int res = ch - 48;
  while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
  return sgn ? -res : res;
}
const int N = 1e6 + 5;
long long ans, f[N], h[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) h[i] = read();
  h[0] = h[n + 1] = 1;
  for (int i = 1; i <= n; i++) {
    if (h[i] < h[i + 1]) {
      if (h[i] < h[i - 1]) {
        f[i] = f[i - 1] * (h[i] - 1) + h[i] - 1;
        f[i] %= 1000000007;
        ans += f[i];
        ans %= 1000000007;
      } else {
        f[i] = f[i - 1] * (h[i - 1] - 1) + h[i] - 1;
        f[i] %= 1000000007;
        ans += f[i];
        ans %= 1000000007;
      }
    } else {
      if (h[i] < h[i - 1]) {
        ans += f[i - 1] * (h[i] - 1) + h[i] - 1;
        ans %= 1000000007;
        f[i] = f[i - 1] * (h[i - 1] - 1) + h[i + 1] - 1;
        f[i] %= 1000000007;
      } else {
        ans += f[i - 1] * (h[i - 1] - 1) + h[i] - 1;
        ans %= 1000000007;
        f[i] = f[i - 1] * ((h[i - 1] - 1) > (h[i + 1] - 1) ? (h[i + 1] - 1)
                                                           : (h[i - 1] - 1)) +
               h[i + 1] - 1;
        f[i] %= 1000000007;
      }
    }
  }
  cout << ans;
}
