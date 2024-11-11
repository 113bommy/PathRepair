#include <bits/stdc++.h>
using namespace std;
long long a[1435893];
long long pre[1435893];
inline long long read();
signed main() {
  long long n;
  n = read();
  for (register long long i = 1; i <= n; i++) a[i] = read();
  long long tot = 0;
  for (register long long i = 1; i <= n; i++) pre[i] = i;
  for (register long long i = 1; i <= n; i++)
    tot += (a[i] - a[1] - (pre[i] - pre[1]));
  long long now = tot / n, sum = tot % n;
  for (register long long i = 1; i <= n; i++)
    if (sum > 0)
      cout << a[1] + pre[i] - pre[1] + now + 1 << " ", sum--;
    else
      cout << a[1] + pre[i] - pre[1] + now << " ";
  return 0;
}
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
