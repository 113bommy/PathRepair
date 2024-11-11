#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;
long long a[N];
long long f[2][210][6000];
struct node {
  long long t, f;
} p[205];
node get(long long x) {
  long long t = 0, f = 0;
  long long tmp = x;
  while (x % 2 == 0) ++t, x /= 2;
  x = tmp;
  while (x % 5 == 0) ++f, x /= 5;
  return {t, f};
}
int main() {
  ios::sync_with_stdio(false);
  long long n, K;
  cin >> n >> K;
  int i, j;
  for (i = 1; i <= n; i++) cin >> a[i];
  long long up = 0;
  int cur = 0;
  memset(f, -1, sizeof f);
  f[0][0][0] = 0;
  int now = 0;
  for (long long i = 1; i <= n; ++i) {
    now = now ^ 1;
    p[i] = get(a[i]);
    long long d1 = p[i].f;
    long long d2 = p[i].t;
    up += d1;
    for (long long j = 0; j <= min(i, K); ++j) {
      for (long long l = 0; l <= up; ++l) {
        f[now][j][l] = f[now ^ 1][j][l];
        if (j && l >= d1 && f[now ^ 1][j - 1][l - d1] != -1)
          f[now][j][l] = max(f[now][j][l], f[now ^ 1][j - 1][l - d1] + d2);
      }
    }
  }
  long long ans = 0;
  for (i = 0; i <= up; i++) {
    ans = max(ans, min(1ll * i, f[n & 1][K][i]));
  }
  cout << ans << endl;
  return 0;
}
