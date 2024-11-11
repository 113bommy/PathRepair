#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int n, A, cf, cm;
long long m;
int a[MAX_N];
pair<long long, long long> b[MAX_N];
long long pre[MAX_N];
long long ans, cnt, mn;
int main() {
  scanf("%d%d%d%d%lld", &n, &A, &cf, &cm, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = {a[i], i};
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++)
    pre[i] = pre[i - 1] + (i - 1) * (b[i].first - b[i - 1].first);
  b[n + 1] = {A, n + 1};
  for (int R = n + 1, r = n; R >= 1; R--) {
    m -= A - b[R].first;
    if (m < 0) break;
    b[R].first = A;
    r = min(r, R - 1);
    do {
      long long diff = m - pre[r];
      if (diff >= 0) {
        long long tmp, mnx;
        if (r != 0)
          mnx = b[r].first + diff / r;
        else
          mnx = A;
        mnx = min(mnx, 1ll * A);
        tmp = 1ll * (n + 1 - R) * cf + 1ll * mnx * cm;
        if (tmp > ans) ans = tmp, cnt = R, mn = mnx;
        break;
      }
    } while (r--);
  }
  for (int i = cnt; i <= n; i++) a[b[i].second] = A;
  for (int i = 1; i <= n; i++)
    if (a[i] < mn) a[i] = mn;
  printf("%lld\n", ans);
  for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
  return 0;
}
