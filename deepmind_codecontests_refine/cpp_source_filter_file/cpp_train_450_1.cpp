#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007LL;
const int maxn = 2000 + 20;
long long c[maxn];
int a[maxn];
long long qm(long long x, long long y) {
  long long t = 1;
  while (y > 0) {
    while (y % 2 == 0) {
      x = x * x % M;
      y /= 2;
    }
    t = t * x % M;
    y--;
  }
  return t;
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (k == 0) cout << a[i] << " ";
  }
  if (k == 0) exit(0);
  memset(c, 0, sizeof(c));
  c[1] = 1;
  for (int i = 2; i <= n; i++)
    c[i] = c[i - 1] * (k + i - 2) * qm(i - 1, M - 2) % M;
  for (int i = 1; i <= n; i++) {
    long long ans = 0;
    for (int j = 1; j <= i; j++) ans = (ans + c[j] * a[i - j + 1]) % M;
    cout << ans << " ";
  }
  return 0;
}
