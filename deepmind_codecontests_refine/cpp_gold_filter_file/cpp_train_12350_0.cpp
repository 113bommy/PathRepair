#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 100;
const int INF = 0x3f3f3f3f;
inline long long fpow(long long a, long long b) {
  long long r = 1, t = a;
  while (b) {
    if (b & 1) r = (r * t) % MOD;
    b >>= 1;
    t = (t * t) % MOD;
  }
  return r;
}
struct Edge {
  int id, u, v, w;
  bool operator<(const Edge &oth) const { return w < oth.w; }
} p[MAXN];
struct node {
  int x, id, now;
  bool operator<(const node &oth) const { return x > oth.x; }
};
int fa[MAXN], sz[MAXN], n, m, q;
int ev[MAXN];
bool ans[MAXN];
stack<pair<int, int> > st;
vector<int> que[MAXN];
priority_queue<node> Q;
void init() {
  for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
}
int find_(int x) {
  while (x != fa[x]) x = fa[x];
  return x;
}
void unite(int x, int y) {
  x = find_(x);
  y = find_(y);
  if (x == y) return;
  if (sz[x] > sz[y]) swap(x, y);
  fa[x] = y;
  sz[y] += sz[x];
  st.push({x, y});
}
void Cancel() {
  while (!st.empty()) {
    int xi = st.top().first, yi = st.top().second;
    sz[yi] -= sz[xi];
    fa[xi] = xi;
    st.pop();
  }
}
int main() {
  cin >> n >> m;
  init();
  for (int i = 1; i <= m; i++)
    scanf("%d %d %d", &p[i].u, &p[i].v, &p[i].w), p[i].id = i;
  sort(p + 1, p + m + 1);
  for (int i = 1; i <= m; i++) ev[p[i].id] = i;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int t;
      scanf("%d", &t);
      t = ev[t];
      que[i].push_back(t);
    }
    sort((que[i]).begin(), (que[i]).end());
    Q.push({que[i][0], i, 0});
  }
  for (int i = 1; i <= m; i++) {
    int wi = p[i].w;
    int j = i + 1;
    for (; j <= m && wi == p[j].w; j++)
      ;
    j--;
    while (!Q.empty()) {
      node s = Q.top();
      if (s.x > j) break;
      Q.pop();
      int ui = find_(p[que[s.id][s.now]].u), vi = find_(p[que[s.id][s.now]].v);
      int len = ((int)(que[s.id]).size());
      while (s.now < len && ui != vi && que[s.id][s.now] <= j) {
        unite(ui, vi);
        s.now++;
        if (s.now < len)
          ui = find_(p[que[s.id][s.now]].u), vi = find_(p[que[s.id][s.now]].v);
      }
      Cancel();
      if (s.now == len) {
        ans[s.id] = true;
        continue;
      }
      s.x = que[s.id][s.now];
      if (s.x > j) Q.push(s);
    }
    for (; i <= j; i++) unite(p[i].u, p[i].v);
    i--;
    while (!st.empty()) st.pop();
  }
  for (int i = 1; i <= q; i++) {
    if (ans[i])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
