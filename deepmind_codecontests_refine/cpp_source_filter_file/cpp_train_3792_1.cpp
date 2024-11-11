#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
long long d[2][10001], a[maxn];
const int mod = 1e9 + 7;
int abss(int fd) {
  if (fd < 0) fd *= -1;
  return fd;
}
int main() {
  int n, m, f, g, c;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  d[0][a[0]] = 1;
  long long ans = 0;
  ans += d[0][0];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < maxn; j++) {
      int it = i % 2;
      d[it][j] = d[it ^ 1][abss(a[i] - j)] + d[it ^ 1][abss(a[i] + j)];
      d[it][j] %= mod;
      if (j == a[i]) d[it][j]++;
      d[it][j] %= mod;
      if (j == 0) ans += d[it][j], ans %= mod;
    }
  cout << ans;
}
