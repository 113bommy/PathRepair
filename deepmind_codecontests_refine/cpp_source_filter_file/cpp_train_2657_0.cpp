#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, i, e, f, g, n, m, k, l, ans, B[200005], tree[1000006],
    idx;
pair<long long, long long> A[200005];
void build(long long node, long long start, long long end) {
  if (start == end) {
    tree[node] = A[start].second;
    return;
  }
  build(2 * node, start, (start + end) / 2);
  build(2 * node + 1, (start + end) / 2 + 1, end);
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
void query(long long node, long long start, long long end, long long pos) {
  if (idx != -1) return;
  if (tree[node] >= A[pos].second) return;
  if (end < pos) return;
  if (start >= pos) {
    if (start == end) {
      idx = start;
      return;
    }
    if (tree[2 * node] < A[pos].second)
      query(2 * node, start, (start + end) / 2, pos);
    else
      query(2 * node + 1, (start + end) / 2 + 1, end, pos);
    return;
  }
  query(2 * node, start, (start + end) / 2, pos);
  query(2 * node + 1, (start + end) / 2 + 1, end, pos);
}
int main() {
  cin >> d >> n >> m;
  for (long long i = 1; i <= m; i++) cin >> A[i].first >> A[i].second;
  sort(A + 1, A + 1 + m);
  m++;
  A[m].first = d;
  A[m].second = 0;
  build(1, 1, m);
  for (long long i = 1; i < m; i++) {
    idx = -1;
    query(1, i + 1, m, i);
    B[i] = min(n, A[idx].first - A[i].first);
  }
  k = n;
  for (long long i = 1; i <= m; i++) {
    if (k < A[i].first - A[i - 1].first) {
      cout << -1;
      return 0;
    }
    k -= A[i].first - A[i - 1].first;
    if (k >= B[i]) continue;
    ans += (B[i] - k) * A[i].second;
    k = B[i];
  }
  cout << ans;
}
