#include <bits/stdc++.h>
using namespace std;
long long inline read() {
  long long num = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num * neg;
}
const long long maxn = 1000010;
long long n, m, a[maxn], l[maxn], r[maxn], ans[maxn], L[maxn], R[maxn],
    stk[maxn], tp;
struct BIT {
  long long sum[maxn];
  void update(long long x, long long k) {
    for (long long i = x; i <= n; i += i & (-i)) sum[i] += k;
  }
  long long Query(long long x) {
    long long ans = 0;
    for (long long i = x; i; i -= i & (-i)) ans += sum[i];
    return ans;
  }
} t1, t2;
vector<long long> q[maxn], pos[maxn];
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= m; i++) l[i] = read();
  for (long long i = 1; i <= m; i++) r[i] = read();
  for (long long i = 1; i <= m; i++) ans[i] = r[i] - l[i] + 1;
  for (long long i = 1; i <= n; i++) R[i] = n, L[i] = 1;
  for (long long i = 1; i <= n; i++) {
    while (tp && a[stk[tp]] < a[i]) {
      R[stk[tp]] = i - 1;
      tp--;
    }
    stk[++tp] = i;
  }
  tp = 0;
  for (long long i = n; i >= 1; i--) {
    while (tp && a[stk[tp]] < a[i]) {
      L[stk[tp]] = i + 1;
      tp--;
    }
    stk[++tp] = i;
  }
  for (long long i = 1; i <= m; i++) q[r[i]].push_back(i);
  for (long long i = 1; i <= n; i++) pos[R[i]].push_back(i);
  for (long long i = 1; i <= n; i++) t1.update(i, R[i]);
  for (long long i = n; i >= 1; i--) {
    for (long long j = 0; j < pos[i].size(); j++) {
      long long x = pos[i][j];
      t1.update(x, -R[x]);
      t2.update(x, 1);
    }
    for (long long j = 0; j < q[i].size(); j++) {
      long long x = q[i][j];
      ans[x] += t1.Query(r[x]) - t1.Query(l[x] - 1) +
                i * (t2.Query(r[x]) - t2.Query(l[x] - 1));
    }
  }
  for (long long i = 1; i <= n; i++) t1.sum[i] = 0;
  for (long long i = 1; i <= n; i++) t2.sum[i] = 0;
  for (long long i = 1; i <= n; i++) q[i].clear(), pos[i].clear();
  for (long long i = 1; i <= m; i++) q[l[i]].push_back(i);
  for (long long i = 1; i <= n; i++) pos[L[i]].push_back(i);
  for (long long i = 1; i <= n; i++) t1.update(i, L[i]);
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < pos[i].size(); j++) {
      long long x = pos[i][j];
      t1.update(x, -L[x]);
      t2.update(x, 1);
    }
    for (long long j = 0; j < q[i].size(); j++) {
      long long x = q[i][j];
      ans[x] -= t1.Query(r[x]) - t1.Query(l[x] - 1) +
                i * (t2.Query(r[x]) - t2.Query(l[x] - 1));
    }
  }
  for (long long i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
