#include <bits/stdc++.h>
using namespace std;
const int SZ = 1 << 16;
int mod;
void add_to(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mul(int a, int b) { return (long long)a * b % mod; }
struct Matrix {
  int a[2][2];
  Matrix(int e = 0) : a() {
    for (int i = 0; i < 2; i++) a[i][i] = e;
  }
  Matrix(int a00, int a01, int a10, int a11) {
    a[0][0] = a00;
    a[0][1] = a01;
    a[1][0] = a10;
    a[1][1] = a11;
  }
  int *operator[](int p) { return a[p]; }
  const int *operator[](int p) const { return a[p]; }
  Matrix operator*(const Matrix &b) const {
    Matrix res;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++) add_to(res[i][j], mul(a[i][k], b[k][j]));
    return res;
  }
};
Matrix bin_pow(Matrix a, long long b) {
  Matrix res(1);
  while (b > 0) {
    if (b % 2 == 1) res = res * a;
    a = a * a;
    b /= 2;
  }
  return res;
}
struct SegTree {
  Matrix t[2 * SZ];
  void build(vector<Matrix> arr) {
    for (int i = 0; i < (int)arr.size(); i++) t[SZ + i] = arr[i];
    for (int i = SZ - 1; i > 0; i--) t[i] = t[2 * i] * t[2 * i + 1];
  }
  Matrix get(int v, int l, int r, int a, int b) {
    if (a > r || b < l) return Matrix(1);
    if (a <= l && r <= b) return t[v];
    int m = (l + r) / 2;
    return get(2 * v, l, m, a, b) * get(2 * v + 1, m + 1, r, a, b);
  }
  Matrix get(int a, int b) { return get(1, 0, SZ - 1, a, b); }
};
long long k;
int n, m;
int seq[SZ];
pair<long long, int> queries[SZ];
vector<long long> changes;
SegTree tree;
int get_seq(long long p) {
  int ind = lower_bound(queries, queries + m, make_pair(p, -1)) - queries;
  if (ind < m && queries[ind].first == p) return queries[ind].second;
  return seq[p % n];
}
Matrix get_matrix(long long p) {
  return Matrix(0, get_seq(p - 2), 1, get_seq(p - 1));
}
Matrix get_matrix_on_seg(long long l, long long r) {
  if (l > r) return Matrix(1);
  long long gl = (l - 2) / n;
  long long gr = (r - 2) / n;
  int pl = (l - 2) % n + 2;
  int pr = (r - 2) % n + 2;
  if (gl == gr) return tree.get(pl, pr);
  Matrix left = tree.get(pl, n + 1);
  Matrix right = tree.get(2, pr);
  gl++;
  gr--;
  Matrix mid = bin_pow(tree.get(2, n + 1), gr - gl + 1);
  return left * mid * right;
}
void solve() {
  scanf("%lld%d%d", &k, &mod, &n);
  if (mod == 1) {
    puts("0");
    return;
  }
  if (k == 0) {
    puts("0");
    return;
  }
  if (k == 1) {
    puts("1");
    return;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &seq[i]);
    seq[i] %= mod;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    long long j;
    int vj;
    scanf("%lld%d", &j, &vj);
    vj %= mod;
    queries[i] = make_pair(j, vj);
  }
  sort(queries, queries + m);
  for (int i = 0; i < m; i++) {
    long long j = queries[i].first;
    changes.push_back(j + 1);
    changes.push_back(j + 2);
  }
  changes.push_back(k);
  sort(changes.begin(), changes.end());
  changes.resize(unique(changes.begin(), changes.end()) - changes.begin());
  vector<Matrix> base(n + 2);
  int dirty_hack = m;
  m = 0;
  for (int i = 2; i < (int)base.size(); i++) base[i] = get_matrix(i);
  m = dirty_hack;
  tree.build(base);
  Matrix trans(1);
  long long prv = 1;
  for (int i = 0;; i++) {
    long long nxt = changes[i];
    trans = trans * get_matrix_on_seg(prv + 1, nxt - 1);
    trans = trans * get_matrix(nxt);
    if (nxt == k) break;
    prv = nxt;
  }
  Matrix vec(0, 1, 0, 0);
  vec = vec * trans;
  printf("%d\n", vec[0][1]);
}
int main() {
  solve();
  0;
  return 0;
}
