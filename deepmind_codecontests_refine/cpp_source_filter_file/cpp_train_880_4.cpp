#include <bits/stdc++.h>
using namespace std;
int n, m, k, Q;
int ans[200000];
priority_queue<int> q[220000];
int tr[400000];
pair<pair<pair<int, int>, pair<int, int> >, int> P[200020];
pair<int, int> p[200000];
void build(int t, int l, int r) {
  if (l == r) {
    if (q[l].size() == 0)
      tr[t] = 100000000;
    else
      tr[t] = -q[l].top();
    return;
  }
  build(2 * t, l, (l + r) / 2);
  build(2 * t + 1, (l + r) / 2 + 1, r);
  tr[t] = max(tr[2 * t], tr[2 * t + 1]);
}
void upd(int t, int l, int r, int L) {
  if (r < L || L < l) return;
  if (l == r) {
    if (q[l].size() == 0)
      tr[t] = 100000000;
    else
      tr[t] = -q[l].top();
    return;
  }
  upd(2 * t, l, (l + r) / 2, L);
  upd(2 * t + 1, (l + r) / 2 + 1, r, L);
  tr[t] = max(tr[2 * t], tr[2 * t + 1]);
}
int get_max(int t, int l, int r, int L, int R) {
  if (R < l || L > r) return 0;
  if (L <= l && r <= R) return tr[t];
  return max(get_max(2 * t, l, (l + r) / 2, L, R),
             get_max(2 * t + 1, (l + r) / 2 + 1, r, L, R));
}
void rem(int l) {
  if (q[p[l].second].size()) {
    q[p[l].second].pop();
  }
  upd(1, 1, n, p[l].second);
}
int l;
void solve() {
  l = 1;
  for (int i = 1; i <= Q; i++) {
    while (l <= k && p[l].first < P[i].first.first.first) {
      rem(l);
      l++;
    }
    if (get_max(1, 1, n, P[i].first.first.second, P[i].first.second.second) <=
        P[i].first.second.first)
      ans[P[i].second] = max(ans[P[i].second], 1);
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &Q);
  n = max(n, m);
  for (int i = 1; i <= k; i++)
    scanf("%d%d", &p[i].first, &p[i].second), q[p[i].second].push(-p[i].first);
  sort(p + 1, p + k + 1);
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d%d%d", &P[i].first.first.first, &P[i].first.first.second,
          &P[i].first.second.first, &P[i].first.second.second);
    P[i].second = i;
  }
  int i;
  sort(P + 1, P + Q + 1);
  build(1, 1, n);
  solve();
  for (i = 1; i <= n; i++)
    while (q[i].size()) q[i].pop();
  for (i = 1; i <= k; i++)
    swap(p[i].first, p[i].second), q[p[i].second].push(-p[i].first);
  sort(p + 1, p + k + 1);
  build(1, 1, n);
  for (i = 1; i <= Q; i++)
    swap(P[i].first.first.first, P[i].first.first.second),
        swap(P[i].first.second.first, P[i].first.second.second);
  sort(P + 1, P + Q + 1);
  solve();
  for (i = 1; i <= Q; i++)
    if (ans[i])
      printf("YES\n");
    else
      printf("NO\n");
}
