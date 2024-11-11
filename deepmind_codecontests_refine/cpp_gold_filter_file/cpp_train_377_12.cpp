#include <bits/stdc++.h>
using namespace std;
struct meeting {
  int l, r, t;
  bool operator<(const meeting &r) const { return t > r.t; }
};
const int N = 500010;
const int INF = 1e9;
int l[N], r[N], t[N], v[N];
int n, p, k;
priority_queue<meeting> que;
meeting make(int ml, int mr, int len) {
  r[ml] = mr;
  l[mr] = ml;
  v[mr] = len;
  return (meeting){ml, mr, len};
}
int main() {
  scanf("%d %d", &k, &n);
  for (int i = 0; i < n; i++) scanf("%d", &t[i]);
  sort(t, t + n);
  que.push(make(0, 1, INF));
  for (int i = 1; i < n; i++) que.push(make(i, i + 1, t[i] - t[i - 1]));
  que.push(make(n, n + 1, INF));
  int ans = 0;
  while (k--) {
    while (true) {
      meeting m = que.top();
      que.pop();
      if (l[m.r] != m.l || r[m.l] != m.r) continue;
      ans += m.t;
      que.push(make(l[m.l], r[m.r], v[m.l] + v[r[m.r]] - v[m.r]));
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
