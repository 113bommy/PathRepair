#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
struct Node {
  long long l, r, w;
  bool operator<(const Node &cmp) const { return r > cmp.r; }
};
long long n, x;
Node a[MAXN];
long long w[MAXN];
int main() {
  scanf("%lld%lld", &n, &x);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld%lld", &a[i].l, &a[i].r, &a[i].w);
  }
  sort(a + 1, a + 1 + n, [](Node a, Node b) { return a.l < b.l; });
  memset(w, INF, sizeof(w));
  w[0] = 0;
  long long ans = INF;
  priority_queue<Node> q;
  for (long long i = 1; i <= n; i++) {
    q.push(a[i]);
    while (!q.empty() && q.top().r < a[i].l) {
      Node t = q.top();
      q.pop();
      w[t.r - t.l + 1] = min(w[t.r - t.l + 1], t.w);
    }
    long long len = a[i].r - a[i].l + 1;
    if (len <= x) {
      ans = min(ans, w[x - len] + a[i].w);
    }
  }
  if (ans != INF) {
    printf("%lld\n", ans);
  } else {
    printf("-1\n");
  }
  return 0;
}
