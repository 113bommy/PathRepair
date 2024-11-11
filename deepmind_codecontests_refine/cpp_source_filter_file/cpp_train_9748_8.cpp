#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, q, a[N], b[N];
long long tag[N * 4], Min[N * 4], ans[N];
void add(int x, int d) {
  tag[x] += d;
  Min[x] += d;
}
void down(int x) {
  if (tag[x]) {
    add(x << 1, tag[x]);
    add(x << 1 | 1, tag[x]);
    tag[x] = 0;
  }
}
void add(int x, int l, int r, int L, int R, int d) {
  if (l >= L && r <= R) return add(x, d);
  down(x);
  int mid = (l + r) >> 1;
  if (L <= mid) add(x << 1, l, mid, L, R, d);
  if (R > mid) add(x << 1 | 1, mid + 1, r, L, R, d);
  Min[x] = min(Min[x << 1], Min[x << 1 | 1]);
}
vector<pair<int, int> > v[N];
struct heap {
  priority_queue<long long, vector<long long>, greater<long long> > p, q;
  void push(long long x) { p.push(x); }
  void erase(long long x) { q.push(x); }
  long long top() {
    while (!q.empty() && p.top() == q.top()) p.pop(), q.pop();
    return p.top();
  }
} Q;
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i < n; i++) scanf("%d%d", &a[i], &b[i]);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    v[x].push_back(pair<int, int>(y, z));
  }
  for (int i = 2; i <= n; i++) add(1, 1, n, i, i, b[i - 1]);
  for (int i = 1; i <= n; i++) {
    for (auto p : v[i]) add(1, 1, n, 1, p.first, p.second);
    ans[i] = Min[1];
  }
  for (int i = 1; i <= n; i++) Q.push(ans[i] + a[i]);
  printf("%lld\n", Q.top());
  while (q--) {
    int p, v;
    scanf("%d%d", &p, &v);
    Q.erase(ans[p] + a[p]);
    a[p] = v;
    Q.push(ans[p] + a[p]);
    printf("%lld\n", Q.top());
  }
  return 0;
}
