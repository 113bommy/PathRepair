#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
long long l[N], r[N];
long long tt[N];
struct node {
  long long val, l, r, lnum;
  node(long long a = 0, long long b = 0, long long c = 0, long long d = 0) {
    val = a, l = b, r = c, lnum = d;
  }
};
bool operator<(const node &A, const node &B) { return A.val < B.val; }
pair<long long, long long> a[N];
int main() {
  long long n, A, cf, cm;
  long long m;
  scanf("%I64d%I64d%I64d%I64d%I64d", &n, &A, &cf, &cm, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  l[0] = 0;
  for (int i = 1; i < n; ++i) {
    l[i] = l[i - 1] + (a[i].first - a[i - 1].first) * i;
  }
  r[n - 1] = A - a[n - 1].first;
  for (int i = n - 2; i >= 0; --i) {
    r[i] = r[i + 1] + A - a[i].first;
  }
  node ans = node(-1, 0, 0, 0);
  for (int i = 0; i <= n; ++i) {
    if (r[i] > m) continue;
    if (i == 0) {
      ans = max(ans, node(1ll * n * cf + 1ll * A * cm, -1, 0, -1));
      continue;
    }
    int pos = upper_bound(l, l + i, m - r[i]) - l - 1;
    assert(pos >= 0);
    ans = max(
        ans,
        node(1ll * (n - i) * cf +
                 1ll * min(A, a[pos].first + (m - r[i] - l[pos]) / (pos + 1)) *
                     cm,
             pos, i, min(A, a[pos].first + (m - r[i] - l[pos]) / (pos + 1))));
  }
  for (int i = 0; i < n; ++i) {
    if (i <= ans.l)
      tt[a[i].second] = ans.lnum;
    else if (i >= ans.r)
      tt[a[i].second] = A;
    else
      tt[a[i].second] = a[i].first;
  }
  printf("%I64d\n", ans.val);
  for (int i = 0; i < n; ++i) {
    printf("%I64d%c", tt[i], " \n"[i == n - 1]);
  }
  return 0;
}
