#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
long long int C[10][10];
const long long int mod = 1000000007;
int ar[100005];
long long int memo[6][400005];
struct node {
  long long int val[6];
  int l, r;
  bool disable;
  long long int all;
  node(bool flag = false) {
    if (flag)
      disable = true;
    else {
      memset(val, 0, sizeof(val));
      all = -1;
      disable = false;
    }
  }
};
struct segtree {
  node val[400005];
  node merge(node a, node b) {
    if (a.disable) return b;
    if (b.disable) return a;
    int sz = a.r - a.l;
    node res;
    res.l = a.l;
    res.r = b.r;
    for (int i = 0; i < 6; ++i) {
      res.val[i] = a.val[i];
      long long int mul = 1;
      for (int j = 0; j < i + 1; ++j) {
        res.val[i] += b.val[i - j] * C[i][j] * mul % mod;
        mul *= sz;
        mul %= mod;
      }
      res.val[i] %= mod;
    }
    return res;
  }
  int n;
  void init(int n_) {
    n = 1;
    while (n < n_) n <<= 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 6; ++j) val[i + n - 1].val[j] = (i < n_ ? ar[i] : 0);
      val[i + n - 1].l = i;
      val[i + n - 1].r = i + 1;
    }
    for (int i = n - 2; i >= 0; --i)
      val[i] = merge(val[i * 2 + 1], val[i * 2 + 2]);
  }
  void push(int i) {
    if (val[i].all != -1) {
      int len = val[i].r - val[i].l;
      len /= 2;
      val[i * 2 + 1].all = val[i * 2 + 2].all = val[i].all;
      for (int j = 0; j < 6; ++j)
        val[i * 2 + 1].val[j] = val[i * 2 + 2].val[j] =
            memo[j][len] * val[i].all % mod;
      val[i].all = -1;
    }
  }
  node query(int a, int b, int i, int l, int r) {
    if (a <= l && r <= b) return val[i];
    if (b <= l || r <= a) return node(true);
    int md = (l + r) >> 1;
    push(i);
    return merge(query(a, b, i * 2 + 1, l, md), query(a, b, i * 2 + 2, md, r));
  }
  void set(int a, int b, int i, int l, int r, long long int v) {
    if (a <= l && r <= b) {
      val[i].all = v;
      for (int j = 0; j < 6; ++j) val[i].val[j] = memo[j][r - l] * v % mod;
      return;
    }
    if (b <= l || r <= a) return;
    int md = (l + r) >> 1;
    push(i);
    set(a, b, i * 2 + 1, l, md, v);
    set(a, b, i * 2 + 2, md, r, v);
    val[i] = merge(val[i * 2 + 1], val[i * 2 + 2]);
  }
};
segtree seg;
int n, m;
int mpow(int a, int k) {
  long long int res = 1;
  for (int i = 0; i < k; ++i) res *= a, res %= mod;
  return res;
}
int main() {
  for (int i = 0; i < 10; ++i) {
    C[i][0] = 1;
    for (int j = 0; j < i; ++j) C[i][j + 1] = C[i - 1][j] + C[i - 1][j + 1];
  }
  for (int i = 0; i < 6; ++i) {
    memo[i][0] = 0;
    for (int j = 0; j < 400000; ++j) {
      memo[i][j + 1] = (memo[i][j] + mpow(j + 1, i)) % mod;
    }
  }
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &ar[i]);
  seg.init(n);
  char tmp[10];
  for (int hoge = 0; hoge < m; ++hoge) {
    int l, r, x;
    scanf("%s%d%d%d", tmp, &l, &r, &x);
    --l;
    if (tmp[0] == '=') {
      seg.set(l, r, 0, 0, seg.n, x);
    } else {
      node tmp = seg.query(l, r, 0, 0, seg.n);
      cout << tmp.val[x] << endl;
    }
  }
  return 0;
}
