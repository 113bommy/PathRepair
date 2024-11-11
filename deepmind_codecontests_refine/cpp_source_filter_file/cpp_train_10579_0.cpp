#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000003;
int phi[maxn], pr[maxn], c[maxn], mnp[maxn], sz, npr[maxn], n, a[maxn];
long long ans, sum;
long long get(int l, int r) {
  if (l > r) return 0;
  return a[r] - a[l - 1];
}
int main() {
  scanf("%d", &n);
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!npr[i]) {
      pr[++sz] = i;
      c[i] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= sz && 1ll * pr[j] * i <= n; ++j) {
      npr[i * pr[j]] = true;
      mnp[i * pr[j]] = pr[j];
      c[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) {
        phi[i * pr[j]] = phi[i] * pr[j];
        break;
      }
      phi[i * pr[j]] = phi[i] * phi[pr[j]];
    }
  }
  ans = 1ll * (n - 2) * (n - 1) / 2;
  for (int i = 2; i <= n; ++i) sum += phi[i] - 1, a[c[i]]++;
  ans += sum;
  for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
  for (int i = 1; i <= sz; ++i) {
    long long x = get(max(pr[i] + 1, n / pr[i] + 1), max(pr[i] + 1, n / 2 + 1)),
              y = a[pr[i]] - a[pr[i] - 1];
    long long z = get(max(pr[i] + 1, n / 2 + 1), n);
    ans += y * x;
    ans -= 2 * y * z;
  }
  printf("%lld\n", ans);
  return 0;
}
