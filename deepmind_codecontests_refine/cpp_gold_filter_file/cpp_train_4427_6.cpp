#include <bits/stdc++.h>
using namespace std;
struct node {
  int ed;
  long long v;
  node *next;
} s[200000 + 5];
int sl[200000 + 5];
int fa[200000 + 5][20 + 5];
long long sa[200000 + 5][20 + 5];
int f[200000 + 5];
pair<long long, pair<int, int> > s1[200000 + 5];
void push(int x, int y, long long z) {
  node *p = new node;
  p->ed = y;
  p->v = z;
  p->next = s[x].next;
  s[x].next = p;
}
int find(int a) {
  if (f[a] != a) {
    f[a] = find(f[a]);
  }
  return f[a];
}
void op(int a, int b) { f[find(a)] = find(b); }
void dfs(int l, int Fa) {
  for (int i = 1; fa[l][i - 1]; i++) {
    fa[l][i] = fa[fa[l][i - 1]][i - 1];
    sa[l][i] = max(sa[l][i - 1], sa[fa[l][i - 1]][i - 1]);
  }
  for (node *i = s[l].next; i; i = i->next) {
    if (i->ed == Fa) {
      continue;
    }
    fa[i->ed][0] = l;
    sa[i->ed][0] = i->v;
    sl[i->ed] = sl[l] + 1;
    dfs(i->ed, l);
  }
}
long long g(int x, int y) {
  if (sl[x] > sl[y]) {
    swap(x, y);
  }
  long long smax = 0;
  for (int i = sl[y] - sl[x], j = 0; i; i >>= 1, j++) {
    if (i & 1) {
      smax = max(sa[y][j], smax);
      y = fa[y][j];
    }
  }
  if (x != y) {
    for (int i = 20; i >= 0; i--) {
      if (fa[x][i] != fa[y][i]) {
        smax = max(smax, sa[x][i]);
        smax = max(smax, sa[y][i]);
        x = fa[x][i];
        y = fa[y][i];
      }
    }
    smax = max(smax, sa[x][0]);
    smax = max(smax, sa[y][0]);
  }
  return smax;
}
int main() {
  int n, m;
  priority_queue<pair<long long, pair<int, int> >,
                 vector<pair<long long, pair<int, int> > >,
                 greater<pair<long long, pair<int, int> > > >
      q;
  long long ans = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    long long z;
    scanf("%d %d %lld", &x, &y, &z);
    q.push(make_pair(z, make_pair(x, y)));
    s1[i] = make_pair(z, make_pair(x, y));
  }
  for (int j = 1; j < n; j++) {
    while (find(q.top().second.first) == find(q.top().second.second)) {
      q.pop();
    }
    push(q.top().second.first, q.top().second.second, q.top().first);
    push(q.top().second.second, q.top().second.first, q.top().first);
    op(q.top().second.first, q.top().second.second);
    ans += q.top().first;
    q.pop();
  }
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    printf("%lld\n",
           ans - g(s1[i].second.first, s1[i].second.second) + s1[i].first);
  }
}
