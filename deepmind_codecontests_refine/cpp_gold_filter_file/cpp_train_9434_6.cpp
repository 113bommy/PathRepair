#include <bits/stdc++.h>
using namespace std;
int a[200010];
struct EDGE {
  int to, next;
} e[200010];
int n, head[200010], top, deg[200010];
void add(int u, int v) {
  deg[v]++;
  e[top].to = v;
  e[top].next = head[u];
  head[u] = top++;
}
int b[200010];
queue<int> q;
void topo() {
  int i;
  for (i = 1; i <= n; i++) {
    if (!deg[i]) {
      q.push(i);
    }
  }
  int btop = 1, tmp;
  while (!q.empty()) {
    tmp = q.front();
    b[btop++] = tmp;
    q.pop();
    for (i = head[tmp]; ~i; i = e[i].next) {
      deg[e[i].to]--;
      if (!deg[e[i].to]) q.push(e[i].to);
    }
  }
  if (btop <= n) {
    cout << "-1" << endl;
    exit(0);
  }
}
int L[200010], R[200010], ans[200010];
struct _ {
  int id, l, r;
  bool operator<(const _ &ob) const { return r > ob.r; }
} c[200010];
bool cmp(const _ &a, const _ &b) { return a.l < b.l; }
priority_queue<_> pq;
int main() {
  memset(head, 255, sizeof(head));
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int m, k;
  cin >> n >> m >> k;
  int i;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int u, v;
  for (i = 1; i <= m; i++) {
    cin >> u >> v;
    add(u, v);
  }
  topo();
  int j;
  for (i = 1; i <= n; i++) {
    if (!a[i])
      L[i] = 1, R[i] = k;
    else
      L[i] = R[i] = a[i];
  }
  for (i = 1; i <= n; i++) {
    for (j = head[b[i]]; ~j; j = e[j].next) {
      R[e[j].to] = min(R[e[j].to], R[b[i]] - 1);
    }
  }
  for (i = n; i >= 1; i--) {
    for (j = head[b[i]]; ~j; j = e[j].next) {
      L[b[i]] = max(L[b[i]], L[e[j].to] + 1);
    }
  }
  for (i = 1; i <= n; i++) {
    if (L[i] > R[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  for (i = 1; i <= n; i++) {
    c[i] = (_){i, L[i], R[i]};
  }
  sort(c + 1, c + 1 + n, cmp);
  int o = 1;
  for (i = 1; i <= k; i++) {
    while (o <= n) {
      if (c[o].l > i) break;
      pq.push(c[o]);
      o++;
    }
    bool flag = 0;
    _ tmp;
    while (!pq.empty()) {
      tmp = pq.top();
      if (tmp.r == i) {
        ans[tmp.id] = i;
        pq.pop();
        flag = 1;
        continue;
      } else {
        if (!flag) {
          flag = 1;
          ans[tmp.id] = i;
          pq.pop();
        }
        break;
      }
    }
    if (!flag) {
      cout << "-1" << endl;
      return 0;
    }
  }
  for (i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
