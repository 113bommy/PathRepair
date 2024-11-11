#include <bits/stdc++.h>
using namespace std;
const int maxn = 600005;
int n, m;
long long dlt[maxn];
int a[maxn], ia[maxn];
int b[maxn], ib[maxn], res[maxn];
int A[maxn], B[maxn], *V, rk[maxn];
bool cmp(int x, int y) { return V[x] < V[y]; }
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) scanf("%d", A + i), rk[i] = i;
  for (int i = 0; i < n; i++) scanf("%d", B + i);
  V = A;
  sort(rk, rk + n, cmp);
  for (int i = 0; i < n; i++) a[i] = A[rk[i]];
  for (int i = 0; i < n; i++) ia[i] = rk[i];
  V = B;
  sort(rk, rk + n, cmp);
  for (int i = 0; i < n; i++) b[i + n] = B[rk[i]];
  for (int i = 0; i < n; i++) ib[i] = ib[i + n] = ib[i + n + n] = rk[i];
  for (int i = n; i < n + n; i++) b[i - n] = b[i] - m, b[i + n] = b[i] + m;
  for (int i = 0; i < n; i++) {
    int k = lower_bound(b, b + n + n + n, a[i]) - b;
    int st = k - i;
    st = max(st, 0);
    st = min(st, n + n + 1);
    dlt[0] += a[i];
    dlt[st] += -2ll * a[i];
    dlt[n + n + 1] += a[i];
  }
  for (int i = 0; i < n + n + n; i++) {
    int L = max(0, i - n + 1), R = i + 1;
    int k = upper_bound(a, a + n, b[i]) - a;
    int st = i - k + 1;
    st = max(st, L);
    st = min(st, R);
    dlt[L] += -b[i];
    dlt[st] += 2 * b[i];
    dlt[R] += -b[i];
  }
  long long ans = 0, minans = dlt[0], st = 0;
  for (int i = 0; i <= n + n; i++)
    if (minans > (ans += dlt[i])) st = i, minans = ans;
  printf("%lld\n", minans);
  for (int i = 0; i < n; i++) res[ia[i]] = ib[st + i];
  for (int i = 0; i < n; i++) printf("%d ", res[i] + 1);
  return 0;
}
