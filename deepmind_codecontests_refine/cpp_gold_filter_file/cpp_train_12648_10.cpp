#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = getchar();
  long long x = 0, fl = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fl = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch - '0');
  return x * fl;
}
const int NN = 100000 + 17;
const long long INF = 1e18;
void open() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
}
int n;
long long a[NN], f[NN];
long long ans;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = -INF;
    for (int j = i; j >= 1; j--)
      if (f[j] < f[j - 1] + 1LL * j * a[i])
        f[j] = f[j - 1] + 1LL * j * a[i];
      else
        break;
  }
  for (int i = 0; i <= n; i++) {
    ans = max(ans, f[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
