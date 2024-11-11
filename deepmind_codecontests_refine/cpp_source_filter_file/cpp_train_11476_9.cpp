#include <bits/stdc++.h>
using namespace std;
int read() {
  int out = 0, sgn = 1;
  char jp = getchar();
  while (jp != '-' && (jp < '0' || jp > '9')) jp = getchar();
  if (jp == '-') sgn = -1, jp = getchar();
  while (jp >= '0' && jp <= '9') out = out * 10 + jp - '0', jp = getchar();
  return out * sgn;
}
const int N = 2e5 + 10;
int n, m, t[N], a[N], b[N], cnt;
int main() {
  n = read(), m = read();
  if (n > m)
    puts("0");
  else {
    for (int i = 1; i <= n; ++i) a[i] = read() % m;
    long long ans = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j < i; ++j) ans = 1LL * ans * abs(a[i] - a[j]), ans %= m;
    cout << ans % m << endl;
  }
  return 0;
}
