#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5);
int dn;
long long n, d[N], a[N + 10];
long long ans, dp[N + 10];
long long px[N], b[N];
bool used[N];
long long check(long long n) {
  if (n < 3) return -1;
  n--;
  int p = -1;
  for (int i = 2; 1ll * i * i <= n; i++)
    if (n % i == 0) {
      p = i;
      break;
    }
  if (p == -1) return n;
  while (n % p == 0) n /= p;
  if (n == 1) return p;
  return -1;
}
void rec(long long n, int mx) {
  if (n == 1) {
    ans++;
    return;
  }
  for (int i = mx; i > 0; i--) {
    if (n % dp[i] == 0 && !used[b[i]]) {
      used[b[i]] = 1;
      rec(n / dp[i], i);
      used[a[i]] = 0;
    }
  }
}
int main() {
  scanf("%I64d", &n);
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) {
      d[++dn] = i;
      if (1ll * i * i != n) d[++dn] = n / i;
    }
  }
  d[++dn] = n;
  sort(d + 1, d + dn + 1);
  int an = 0;
  for (int i = 1; i <= dn; i++) {
    px[i] = check(d[i]);
    if (px[i] != -1) a[++an] = px[i];
  }
  sort(a + 1, a + an + 1);
  int cn = unique(a + 1, a + an + 1) - a - 1;
  int m = 0;
  for (int i = 1; i <= dn; i++) {
    if (px[i] != -1) {
      px[i] = lower_bound(a + 1, a + cn + 1, px[i]) - a;
      dp[++m] = d[i];
      b[m] = px[i];
    }
  }
  rec(n, m);
  cout << ans;
  return 0;
}
