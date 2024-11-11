#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long p, long long m) {
  if (b == 0) return 0;
  long long res = 1;
  while (p) {
    if (p % 2) {
      res = (res * b) % m;
      p--;
    } else {
      b = (b * b) % m;
      p /= 2;
    }
  }
  return res;
}
long long Root(long long r, vector<long long> &root) {
  while (root[r] != r) {
    root[r] = root[root[r]];
    r = root[r];
  }
  return r;
}
void EE(long long a, long long b, long long &x, long long &y) {
  long long t;
  if (b == 0) {
    y = 0, x = 1;
    return;
  }
  EE(b, a % b, x, y);
  t = x;
  x = y;
  y = t - a / b * y;
}
void build(long long node, long long start, long long end, vector<long long> &a,
           vector<long long> &tree) {
  if (start == end) {
    tree[node] = a[start];
    return;
  }
  long long mid = (start + end) / 2;
  build(2 * node, start, mid, a, tree);
  build(2 * node + 1, mid + 1, end, a, tree);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long query(long long node, long long start, long long end, long long l,
                long long r, vector<long long> &tree, vector<long long> &lazy) {
  if (lazy[node]) {
    tree[node] = end - start + 1 - tree[node];
    if (start != end) {
      lazy[2 * node] = lazy[2 * node] ^ 1;
      lazy[2 * node + 1] = lazy[2 * node + 1] ^ 1;
    }
    lazy[node] = 0;
  }
  if (start >= l && end <= r) {
    return tree[node];
  }
  if (l > end || r < start) return 0;
  long long mid = (start + end) / 2;
  return query(2 * node, start, mid, l, r, tree, lazy) +
         query(2 * node + 1, mid + 1, end, l, r, tree, lazy);
}
void update(long long node, long long start, long long end, long long l,
            long long r, vector<long long> &tree, vector<long long> &lazy) {
  if (lazy[node]) {
    tree[node] = end - start + 1 - tree[node];
    if (start != end) {
      lazy[2 * node] = lazy[2 * node] ^ 1;
      lazy[2 * node + 1] = lazy[2 * node + 1] ^ 1;
    }
    lazy[node] = 0;
  }
  if (l > end || r < start) return;
  if (start >= l && end <= r) {
    tree[node] = end - start + 1 - tree[node];
    if (start != end) {
      lazy[2 * node] = lazy[2 * node] ^ 1;
      lazy[2 * node + 1] = lazy[2 * node + 1] ^ 1;
    }
    return;
  }
  long long mid = (start + end) / 2;
  update(2 * node, start, mid, l, r, tree, lazy);
  update(2 * node + 1, mid + 1, end, l, r, tree, lazy);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
vector<vector<long long> > mm(vector<vector<long long> > &a,
                              vector<vector<long long> > &b) {
  long long r, c1, c2, i, j, k;
  r = a.size();
  c1 = b.size();
  c2 = b[0].size();
  vector<vector<long long> > res(r, vector<long long>(c2));
  for (j = 0; j < r; j++) {
    for (k = 0; k < c2; k++) {
      for (i = 0; i < c1; i++) {
        res[j][k] = (res[j][k] + a[j][i] * b[i][k]) % 1000000007;
      }
    }
  }
  return res;
}
vector<vector<long long> > exp(vector<vector<long long> > &M, long long power) {
  long long m = M.size();
  vector<vector<long long> > id(m, vector<long long>(m));
  long long i, j;
  for (i = 0; i < m; i++) id[i][i] = 1;
  while (power > 0) {
    if (power % 2) id = mm(id, M);
    M = mm(M, M);
    power /= 2;
  }
  return id;
}
long long hashv(long long l, long long r, vector<long long> &pre, long long m,
                long long p) {
  long long t = (pre[r] - pre[l - 1] + m) % m;
  long long in = power(p, (l - 1) * (m - 2), m);
  return (t * in) % m;
}
void hashb(long long p, long long m, string &s, vector<long long> &pre) {
  long long i, t = p;
  for (i = 1; i < pre.size(); i++) {
    pre[i] = (pre[i - 1] + (s[i - 1] - 96) * t) % m;
    t = (t * p) % m;
  }
}
int main() {
  double r = 0, t1, p;
  long long n, t, i, j;
  cin >> n >> p >> t;
  vector<vector<double> > dp(t + 1, vector<double>(n + 1));
  dp[0][0] = 100;
  for (i = 1; i <= t; i++) {
    dp[i][0] = dp[i - 1][0] * (1 - p);
    for (j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j - 1] * p;
      t1 = dp[i - 1][j];
      if (j != n) t1 *= (1 - p);
      dp[i][j] += t1;
    }
  }
  for (i = 1; i <= n; i++) r += i * dp[t][i];
  printf("%.15lf", r / 100);
}
