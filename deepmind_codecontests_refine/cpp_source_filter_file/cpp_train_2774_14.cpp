#include <bits/stdc++.h>
using namespace std;
inline long long r() {
  char c;
  long long x, f = 1;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  x = c - '0';
  for (c = getchar(); isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
long long n, k, a[300010], b[300010], ans, minn = 1e18;
int main() {
  n = r();
  k = r();
  for (register int i = 1; i <= k; i++) b[i] = r();
  for (register int i = 1; i <= k; i++) {
    int x = n / b[i];
    if (n - b[i] * x < minn) ans = i, minn = n - b[i] * x;
  }
  cout << ans << ' ' << n / b[ans] << endl;
  return 0;
}
