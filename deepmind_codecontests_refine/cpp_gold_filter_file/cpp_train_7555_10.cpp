#include <bits/stdc++.h>
using namespace std;
struct cww {
  cww() {
    if (0) {
      ios::sync_with_stdio(false);
      cin.tie(0);
    }
  }
} star;
template <typename T>
inline void chmin(T &l, T r) {
  l = min(l, r);
}
template <typename T>
inline void chmax(T &l, T r) {
  l = max(l, r);
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &it : v) is >> it;
  return is;
}
int b[5123456];
long long c[5123456];
long long dist[5123456];
int E = 0;
vector<vector<int> > edge;
int now = 0;
struct node {
  int a, b;
};
namespace ST {
node mem[1][312345];
int cnt = 0;
node *get() { return mem[cnt]; }
}  // namespace ST
void addedge(int from, int to, long long cost) {
  edge[from].push_back(E);
  b[E] = to;
  c[E] = cost;
  E++;
}
struct seg_tree {
  int size;
  node *seg;
  void init(int l, int r, int k = 0) {
    auto &v = seg[k];
    edge.push_back(vector<int>());
    edge.push_back(vector<int>());
    seg[k].a = now++;
    seg[k].b = now++;
    if (r - l == 1) {
      addedge(seg[k].a, l, 0);
      addedge(l, seg[k].b, 0);
    } else if (r - l > 1) {
      int m = (l + r) / 2;
      init(l, m, k * 2 + 1);
      init(m, r, k * 2 + 2);
      if (m - l >= 1) {
        addedge(seg[k].a, seg[k * 2 + 1].a, 0);
        addedge(seg[k * 2 + 1].b, seg[k].b, 0);
      }
      if (r - m >= 1) {
        addedge(seg[k].a, seg[k * 2 + 2].a, 0);
        addedge(seg[k * 2 + 2].b, seg[k].b, 0);
      }
    }
  }
  seg_tree(int n) {
    size = 1;
    while (size < n) size *= 2;
    seg = ST::get();
    init(0, size);
  }
  void lr_v(int a, int b, int k, int l, int r, int v, long long cost) {
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      addedge(seg[k].b, v, cost);
    } else {
      int m = (l + r) / 2;
      lr_v(a, b, k * 2 + 1, l, m, v, cost);
      lr_v(a, b, k * 2 + 2, m, r, v, cost);
    }
  }
  void lr_v(int a, int b, int v, long long cost) {
    lr_v(a, b, 0, 0, size, v, cost);
  }
  void v_lr(int a, int b, int k, int l, int r, int v, long long cost) {
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      addedge(v, seg[k].a, cost);
    } else {
      int m = (l + r) / 2;
      v_lr(a, b, k * 2 + 1, l, m, v, cost);
      v_lr(a, b, k * 2 + 2, m, r, v, cost);
    }
  }
  void v_lr(int a, int b, int v, long long cost) {
    v_lr(a, b, 0, 0, size, v, cost);
  }
};
const long long INF = 1e15;
int main() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  s--;
  edge.resize(n);
  now = n;
  seg_tree st(n);
  for (int i = (0); i < (m); i++) {
    int type, aa, bb, cc, dd;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d %d %d", &aa, &bb, &cc);
      st.v_lr(bb - 1, bb, aa - 1, cc);
    }
    if (type == 2) {
      scanf("%d %d %d %d", &aa, &bb, &cc, &dd);
      st.v_lr(bb - 1, cc, aa - 1, dd);
    }
    if (type == 3) {
      scanf("%d %d %d %d", &aa, &bb, &cc, &dd);
      st.lr_v(bb - 1, cc, aa - 1, dd);
    }
  }
  for (int i = (0); i < (now); i++) dist[i] = INF;
  using P = pair<long long, int>;
  priority_queue<P> que;
  que.push(P(0, s));
  dist[s] = 0;
  while (que.size()) {
    int v;
    long long cost;
    tie(cost, v) = que.top();
    que.pop();
    cost = -cost;
    if (dist[v] < cost) continue;
    for (auto &e : edge[v]) {
      long long nxtcost = cost + c[e];
      int u = b[e];
      if (dist[u] > nxtcost) {
        que.push(P(-nxtcost, u));
        dist[u] = nxtcost;
      }
    }
  }
  if (dist[0] == INF)
    printf("-1");
  else
    printf("%lld", dist[0]);
  for (int i = (1); i < (n); i++) {
    if (dist[i] == INF)
      printf(" -1");
    else
      printf(" %lld", dist[i]);
  }
  cout << endl;
  return 0;
}
