#include <bits/stdc++.h>
using namespace std;
struct Node {
  int l, r;
  int cnt = 0;
  long long sum = 0;
  int left = -1;
  int right = -1;
} NIL;
vector<Node> st;
Node merge(Node x, Node y) {
  Node z;
  z.cnt = x.cnt + y.cnt;
  z.sum = x.sum + y.sum;
  return z;
}
void add(int u, int x, int v) {
  if (not(st[u].l <= v and v <= st[u].r)) return;
  if (st[u].l == v and v == st[u].r) {
    st[u].cnt += 1;
    st[u].sum += x;
    return;
  }
  int m = (st[u].l + st[u].r) >> 1;
  if (st[u].left == -1) {
    Node x;
    x.l = st[u].l, x.r = m;
    st[u].left = int(st.size());
    st.push_back(x);
  }
  if (st[u].right == -1) {
    Node x;
    x.l = m + 1, x.r = st[u].r;
    st[u].right = int(st.size());
    st.push_back(x);
  }
  add(st[u].left, x, v);
  add(st[u].right, x, v);
  Node s = merge(st[st[u].left], st[st[u].right]);
  st[u].sum = s.sum;
  st[u].cnt = s.cnt;
};
Node gteq(int u, int L, int R) {
  if (u == -1 or st[u].r < L or R < st[u].l) return NIL;
  if (L <= st[u].l and st[u].r <= R) return st[u];
  return merge(gteq(st[u].left, L, R), gteq(st[u].right, L, R));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > p(n);
  for (int i = 0; i < n; i++) cin >> p[i].first;
  for (int i = 0; i < n; i++) cin >> p[i].second;
  sort(begin(p), end(p));
  Node root;
  root.l = -1e8;
  root.r = 1e8;
  st.emplace_back(root);
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    Node s = gteq(0, p[i].second, 1e8);
    ans += s.sum - s.cnt * p[i].first;
    add(0, p[i].first, p[i].second);
  }
  cout << ans << '\n';
  return (0);
}
