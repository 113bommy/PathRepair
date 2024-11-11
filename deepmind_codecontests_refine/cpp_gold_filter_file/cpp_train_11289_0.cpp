#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p);
template <class T>
ostream &operator<<(ostream &os, vector<T> &v);
template <class T>
ostream &operator<<(ostream &os, set<T> &v);
inline void optimizeIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const int nmax = 2e5 + 7;
long long ar[nmax];
long long tar[nmax];
vector<int> adj[nmax];
int st[nmax];
int en[nmax];
long long ara[nmax];
int d[nmax];
int clk = 0;
void dfs(int u, int p) {
  st[u] = ++clk;
  ara[clk] = ar[u];
  for (int v : adj[u]) {
    if (v == p) continue;
    d[v] = d[u] + 1;
    dfs(v, u);
  }
  en[u] = clk;
}
struct node {
  long long sum;
  long long lazy;
  node() {
    sum = 0;
    lazy = 0;
  }
  void create_leaf(long long val) {
    sum = val;
    lazy = 0;
  }
  void merge_nodes(node &A, node &B) { sum = A.sum + B.sum; }
};
const int nmax2 = nmax << 2;
node Tree[3][nmax2];
void build(int num, int cur, int start, int end) {
  if (start == end) {
    Tree[num][cur].create_leaf(ara[start]);
    return;
  }
  int mid = (start + end) >> 1;
  int lc = cur << 1, rc = lc | 1;
  build(num, lc, start, mid);
  build(num, rc, mid + 1, end);
  Tree[num][cur].merge_nodes(Tree[num][lc], Tree[num][rc]);
}
void node_update(int num, int v, int st, int en, long long add) {
  Tree[num][v].sum += (en - st + 1) * add;
  Tree[num][v].lazy += add;
}
void push(int num, int v, int st, int en) {
  int mid = (st + en) >> 1;
  int lc = v << 1, rc = lc | 1;
  if (Tree[num][v].lazy) {
    node_update(num, lc, st, mid, Tree[num][v].lazy);
    node_update(num, rc, mid + 1, en, Tree[num][v].lazy);
    Tree[num][v].lazy = 0;
  }
}
void update(int num, int cur, int start, int end, int l, int r, long long add) {
  if (l > r) return;
  if (l == start && r == end) {
    node_update(num, cur, start, end, add);
  } else {
    int mid = (start + end) >> 1;
    int lc = cur << 1, rc = lc | 1;
    push(num, cur, start, end);
    update(num, lc, start, mid, l, min(r, mid), add);
    update(num, rc, mid + 1, end, max(l, mid + 1), r, add);
    Tree[num][cur].merge_nodes(Tree[num][lc], Tree[num][rc]);
  }
}
long long query(int num, int cur, int start, int end, int l, int r) {
  if (l > r) return 0;
  if (start >= l && end <= r) {
    return Tree[num][cur].sum;
  }
  int mid = (start + end) >> 1;
  int lc = cur << 1, rc = lc | 1;
  push(num, cur, start, end);
  long long p1 = query(num, lc, start, mid, l, min(r, mid));
  long long p2 = query(num, rc, mid + 1, end, max(l, mid + 1), r);
  return p1 + p2;
}
vector<int> lvl[nmax];
int main() {
  optimizeIO();
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) cin >> ar[i];
  for (int i = 1; i <= n; i++) cin >> tar[i];
  dfs(1, -1);
  build(0, 1, 1, n);
  build(1, 1, 1, n);
  for (int i = 1; i <= n; i++) lvl[d[i]].push_back(i);
  vector<int> res;
  for (int i = 0; i < n; i++) {
    for (int now : lvl[i]) {
      int x = now;
      long long ans = query(d[x] % 2, 1, 1, n, st[x], st[x]);
      ans %= 2;
      if (tar[x] != ans) {
        update(d[x] % 2, 1, 1, n, st[x], en[x], 1);
        res.push_back(x);
      }
    }
  }
  cout << res.size() << "\n";
  for (int x : res) cout << x << "\n";
  return 0;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
  os << "{" << p.first << ", " << p.second << "} ";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> &v) {
  os << "[ ";
  for (int i = 0; i < v.size(); i++) {
    os << v[i] << " ";
  }
  os << " ]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> &v) {
  os << "[ ";
  for (T i : v) {
    os << i << " ";
  }
  os << " ]";
  return os;
}
