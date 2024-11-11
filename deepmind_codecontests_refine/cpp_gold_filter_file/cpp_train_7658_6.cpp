#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
struct edge {
  int x, y, w, p, ind;
  edge(int _x = 0, int _y = 0, int _w = 0, int _p = 0, int _ind = 0) {
    x = _x;
    y = _y;
    w = _w;
    p = _p;
    ind = _ind;
  }
};
int n;
edge a[maxn];
edge dad[maxn];
vector<int> ch[maxn];
int ct = 1;
int fin[maxn];
int disc[maxn];
int cnt;
int ind[maxn];
stack<edge> s[maxn];
long long loga[maxn];
int ab[maxn];
bool killed[maxn];
long long get(int x) {
  long long ret = 0;
  for (; x > 0; x -= x & -x) ret += loga[x];
  return ret;
}
void update(int x, int val) {
  for (; x < maxn; x += x & -x) loga[x] += val;
}
int sz(int x) { return (int)s[ind[x]].size(); }
void join(int x, int y) {
  while (!s[x].empty()) {
    ind[s[x].top().y] = y;
    s[y].push(s[x].top());
    s[x].pop();
  }
}
bool fm[maxn];
edge change[maxn];
void dfs(int x) {
  int curr = -1;
  for (int i = 0; i < ch[x].size(); i++) {
    int y = ch[x][i];
    dfs(y);
    if (curr == -1) {
      curr = ind[y];
      continue;
    }
    if ((int)s[curr].size() < sz(y)) {
      join(curr, ind[y]);
      curr = ind[y];
    } else
      join(ind[y], curr);
  }
  if (curr == -1)
    ind[x] = cnt++;
  else
    ind[x] = curr;
  if (x == 1) return;
  long long sum = get(fin[x] - 1) - get(disc[x] - 1);
  long long req = max((long long)0, sum - dad[x].p);
  int cs = ind[x];
  while (req > 0 && !s[cs].empty()) {
    edge tmp = s[cs].top();
    s[cs].pop();
    int dct = tmp.p - (int)(get(fin[tmp.y] - 1) - get(disc[tmp.y] - 1));
    int take = min(dct, min(tmp.w - 1, tmp.p));
    int old = tmp.w;
    int took = (int)min((long long)take, req);
    tmp.w -= took;
    tmp.p -= took;
    update(disc[tmp.x], tmp.w - old);
    req = max(req - take, (long long)0);
    if (tmp.w == 1 || tmp.p == 0 || dct == 0) {
      fm[tmp.y] = 1;
      change[tmp.y] = tmp;
      ab[tmp.x]++;
      if (tmp.x != x && ab[tmp.x] == (int)ch[tmp.x].size()) {
        edge neww = dad[tmp.x];
        s[cs].push(neww);
        ind[neww.y] = cs;
        ind[neww.x] = cs;
      }
    } else
      s[cs].push(tmp);
  }
  if (req > 0) {
    printf("-1\n");
    exit(0);
  }
  if (ab[x] == (int)ch[x].size()) s[cs].push(dad[x]);
  update(disc[dad[x].x], dad[x].w);
}
void build(int x) {
  disc[x] = ct++;
  for (int i = 0; i < ch[x].size(); i++) build(ch[x][i]);
  fin[x] = ct;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].w, &a[i].p);
    a[i].ind = i;
    ch[a[i].x].push_back(a[i].y);
    dad[a[i].y] = a[i];
  }
  build(1);
  dfs(1);
  int cs = ind[1];
  while (!s[cs].empty()) {
    edge curr = s[cs].top();
    s[cs].pop();
    a[curr.ind].w = curr.w;
    a[curr.ind].p = curr.p;
  }
  printf("%d\n", n);
  for (int i = 0; i < n - 1; i++) {
    if (fm[a[i].y]) a[i] = change[a[i].y];
    printf("%d %d %d %d\n", a[i].x, a[i].y, a[i].w, a[i].p);
  }
  return 0;
}
