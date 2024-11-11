#include <bits/stdc++.h>
using namespace std;
struct lichao {
  int l, r, A;
  long long B;
  lichao() : l(0), r(0), A(0), B(0x7fffffffffffffffLL) {}
};
const int SZ = 1 << 17;
vector<int> adj[100000];
vector<lichao> tree(2 * SZ);
int node_cnt, num[100000], A[100000], B[100000];
long long ans[100000];
int get_sign(long long a) { return a < 0 ? -1 : a > 0; }
void add_tree2(int A, long long B, int p, int s = -SZ, int e = SZ - 1) {
  int m = (s + e) >> 1, &pA = tree[p].A;
  long long &pB = tree[p].B;
  long long ys = 1LL * A * s + B, ym = 1LL * A * m + B, ye = 1LL * A * e + B,
            pys = 1LL * pA * s + pB, pym = 1LL * pA * m + pB,
            pye = 1LL * pA * e + pB;
  if (ym < pym) {
    swap(A, pA);
    swap(B, pB);
    swap(ys, pys);
    swap(ym, pym);
    swap(ye, pye);
  }
  if (ys >= pys && ye >= pye) return;
  if (get_sign(ys - pys) * get_sign(ym - pym) < 0 || ym == pym && ys < pys) {
    if (tree[p].l == 0) tree[p].l = tree.size(), tree.push_back(lichao());
    add_tree2(A, B, tree[p].l, s, m);
  } else {
    if (tree[p].r == 0) tree[p].r = tree.size(), tree.push_back(lichao());
    add_tree2(A, B, tree[p].r, m + 1, e);
  }
}
void add_tree(int n, int A, long long B) {
  for (add_tree2(A, B, n += SZ); n >>= 1;) add_tree2(A, B, n);
}
long long get_min2(int x, int p, int s = -SZ, int e = SZ - 1) {
  int m = (s + e) >> 1;
  if (p == 0 || s == e) return 1LL * tree[p].A * x + tree[p].B;
  return min(
      1LL * tree[p].A * x + tree[p].B,
      x <= m ? get_min2(x, tree[p].l, s, m) : get_min2(x, tree[p].r, m + 1, e));
}
long long get_min(int s, int e, int x) {
  long long ret = 0x7fffffffffffffffLL;
  for (s |= SZ, e |= SZ; s <= e; s >>= 1, e >>= 1) {
    if (s & 1) ret = min(ret, get_min2(x, s++));
    if (~e & 1) ret = min(ret, get_min2(x, e--));
  }
  return ret;
}
void dfs(int c) {
  bool leaf = true;
  num[c] = ++node_cnt;
  for (auto n : adj[c])
    if (num[n] == 0) {
      leaf = false;
      dfs(n);
    }
  ans[c] = (leaf ? 0 : get_min(num[c], node_cnt, A[c]));
  add_tree(num[c], B[c], ans[c]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    adj[--a].push_back(--b);
    adj[b].push_back(a);
  }
  dfs(0);
  for (int i = 0; i < N; i++) cout << ans[i] << ' ';
  return 0;
}
