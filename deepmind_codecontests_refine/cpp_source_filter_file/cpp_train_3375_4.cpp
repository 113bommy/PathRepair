#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  out << '(' << p.first << ',' << p.second << ')';
  return out;
}
template <class T1, class T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& x : v) in >> x;
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<vector<T>>& v) {
  for (auto& x : v) out << x << '\n';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (auto x : v) out << x << ' ';
  return out;
}
const int N = 100005;
struct node {
  int ind, val, l, r;
} Q[N];
int a[N], A[N], bit[N], freq[N], color[N];
int n;
void update(int ind, int val) {
  for (int i = ind; i <= n; i += i & -i) {
    bit[i] += val;
  }
}
int query(int r) {
  int res = 0;
  while (r > 0) {
    res += bit[r];
    r -= r & -r;
  }
  return res;
}
inline void add(int i) {
  if (freq[color[a[i]]] > 0) {
    update(freq[color[a[i]]], -1);
  }
  freq[color[a[i]]]++;
  update(freq[color[a[i]]], 1);
}
inline void del(int i) {
  update(freq[color[a[i]]], -1);
  freq[color[a[i]]]--;
  if (freq[color[a[i]]] > 0) update(freq[color[a[i]]], 1);
}
vector<int> g[N];
int in[N], out[N], cur = 1;
bool vis[N];
void dfs(int second = 1) {
  vis[second] = true;
  a[cur] = second;
  in[second] = cur++;
  for (auto to : g[second]) {
    if (!vis[to]) dfs(to);
  }
  out[second] = cur - 1;
}
void Mo(int n, int q) {
  int BLOCK = max((int)(n / sqrt(q)), 1);
  sort(Q, Q + q, [&](node& a, node& b) {
    if (a.l / BLOCK == b.l / BLOCK) return a.r < b.r;
    return a.l / BLOCK < b.l / BLOCK;
  });
  int curL = 1, curR = 0;
  for (int i = 0; i < q; i++) {
    while (curR < Q[i].r) add(++curR);
    while (curR > Q[i].r) del(curR--);
    while (curL < Q[i].l) add(curL++);
    while (curL > Q[i].l) del(--curL);
    A[Q[i].ind] = query(n) - query(min(n, Q[i].val - 1));
  }
}
void solve() {
  int m;
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) {
    cin >> color[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  for (int i = 0; i < m; i++) {
    int val;
    cin >> val >> Q[i].val;
    Q[i].ind = i;
    Q[i].l = in[val];
    Q[i].r = out[val];
  }
  Mo(n, m);
  for (int i = 0; i < m; i++) {
    cout << A[i] << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
