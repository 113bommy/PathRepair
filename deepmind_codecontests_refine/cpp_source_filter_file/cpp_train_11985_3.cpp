#include <bits/stdc++.h>
using namespace std;
using ti = tuple<int, int, int>;
using lint = long long;
class Sumtree {
 public:
  vector<lint> tree;
  vector<lint> lazy;
  Sumtree() {}
  Sumtree(int n) {
    tree.resize(4 * n + 5);
    lazy.resize(4 * n + 5);
  }
  void update(int n, int ns, int ne, int l, int r, lint v) {
    if (lazy[n] != 0) {
      tree[n] += (ne - ns + 1) * lazy[n];
      if (ns != ne) {
        lazy[2 * n] += lazy[n];
        lazy[2 * n + 1] += lazy[n];
      }
      lazy[n] = 0;
    }
    if (r < ns || ne < l) return;
    if (l <= ns && ne <= r) {
      tree[n] += (ne - ns + 1) * v;
      if (ns != ne) {
        lazy[2 * n] += v;
        lazy[2 * n + 1] += v;
      }
      return;
    }
    int m = (ns + ne) / 2;
    update(2 * n, ns, m, l, r, v);
    update(2 * n + 1, m + 1, ne, l, r, v);
    tree[n] = (tree[2 * n] + tree[2 * n + 1]);
  }
  lint query(int n, int ns, int ne, int l, int r) {
    if (ne < l || r < ns) return 0;
    if (lazy[n]) {
      tree[n] += (ne - ns + 1) * lazy[n];
      if (ns != ne) {
        lazy[2 * n] += lazy[n];
        lazy[2 * n + 1] += lazy[n];
      }
      lazy[n] = 0;
    }
    if (l <= ns && ne <= r) {
      return tree[n];
    }
    int m = (ns + ne) / 2;
    lint q1 = query(2 * n, ns, m, l, r);
    lint q2 = query(2 * n + 1, m + 1, ne, l, r);
    return q1 + q2;
  }
};
const int N = 3 * 1e5 + 5;
Sumtree st(N);
vector<int> adj[N];
bool vis[N];
lint ans[N];
int num;
vector<lint> up_dist[N];
vector<lint> up_val[N];
vector<int> sta;
void go(int n) {
  vis[n] = true;
  sta.push_back(n);
  int sz = (int)sta.size();
  for (size_t i = 0; i < up_val[n].size(); i++) {
    lint t = up_dist[n][i];
    lint l = up_val[n][i];
    st.update(1, 1, num, sz, min(N - 1, sz + (int)t), l);
  }
  ans[n] = st.query(1, 1, num, sz, sz);
  for (int x : adj[n]) {
    if (!vis[x]) {
      go(x);
    }
  }
  for (size_t i = 0; i < up_val[n].size(); i++) {
    lint t = up_dist[n][i];
    lint l = up_val[n][i];
    st.update(1, 1, num, sz, min(N - 1, sz + (int)t), l);
  }
  sta.pop_back();
}
int main() {
  scanf("%d", &num);
  for (int i = 0; i < num - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int v;
    lint d, x;
    scanf("%d%lld%lld", &v, &d, &x);
    up_dist[v].push_back(d);
    up_val[v].push_back(x);
  }
  go(1);
  for (int i = 1; i <= num; i++) {
    printf("%lld ", ans[i]);
  }
  return 0;
}
