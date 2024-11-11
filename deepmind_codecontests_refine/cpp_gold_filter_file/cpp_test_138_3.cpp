#include <bits/stdc++.h>
const int N = 400005;
using namespace std;
int n, m, k, fa[N], cnt[N];
long long res, ans[N], sum[N];
pair<int, int> a[N], b[N], q[N];
int find(int first) {
  return first == fa[first] ? first : fa[first] = find(fa[first]);
}
void merge(int first, int second) {
  first = find(first);
  second = find(second);
  res -= sum[first] - sum[first - cnt[first]];
  res -= sum[second] - sum[second - cnt[second]];
  cnt[second] += cnt[first];
  fa[first] = second;
  res += sum[second] - sum[second - cnt[second]];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i].first), res += a[i].first, a[i].second = 1;
  for (int i = n + 1; i <= n + m; ++i)
    scanf("%d", &a[i].first), a[i].second = 0;
  sort(a + 1, a + n + m + 1);
  for (int i = 1; i <= n + m; ++i) {
    fa[i] = i;
    sum[i] = sum[i - 1] + a[i].first;
    cnt[i] = a[i].second;
    b[i] = make_pair(a[i].first - a[i - 1].first, i - 1);
  }
  for (int i = 1; i <= k; ++i) scanf("%d", &q[i].first), q[i].second = i;
  sort(q + 1, q + k + 1);
  sort(b + 1, b + n + m + 1);
  int nw = 0;
  for (int i = 1; i <= k; ++i) {
    while (nw < n + m && b[nw + 1].first <= q[i].first) {
      ++nw;
      merge(b[nw].second, b[nw].second + 1);
    }
    ans[q[i].second] = res;
  }
  for (int i = 1; i <= k; ++i) printf("%lld\n", ans[i]);
  return 0;
}
