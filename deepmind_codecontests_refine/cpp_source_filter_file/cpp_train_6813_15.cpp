#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
int n, m, k;
long long v, p, a[MAXN], b[MAXN], ca[MAXN], cb[MAXN];
priority_queue<long long> qa, qb;
int main() {
  scanf("%d%d%d%I64d", &n, &m, &k, &p);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%I64d", &v);
      a[i] += v;
      b[j] += v;
    }
  }
  for (int i = 0; i < n; ++i) qa.push(a[i]);
  for (int j = 0; j < m; ++j) qb.push(b[j]);
  for (int i = 1; i <= k; ++i) {
    long long cur = qa.top();
    qa.pop();
    ca[i] = ca[i - 1] + cur;
    qa.push(cur - p * m);
    cur = qb.top();
    qb.pop();
    cb[i] = cb[i - 1] + cur;
    qb.push(cur - p * n);
  }
  long long ans = (long long)(1e17 + 0.5);
  ans *= -1;
  for (int i = 1; i <= k; ++i) {
    ans = max(ans, ca[i] + cb[k - i] - ((long long)i) * (k - i) * p);
  }
  printf("%I64d\n", ans);
  return 0;
}
