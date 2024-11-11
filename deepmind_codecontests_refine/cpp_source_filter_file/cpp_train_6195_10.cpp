#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long p) {
  if (b == 0) return 0;
  long long res = 1;
  while (p) {
    if (p % 2) {
      res = (res * b) % 1000000007;
      p--;
    } else {
      b = (b * b) % 1000000007;
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
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long n, i, j;
  cin >> n;
  vector<long long> p(n), v(n), d(n), r;
  queue<long long> q;
  for (i = 0; i < n; i++) cin >> v[i] >> d[i] >> p[i];
  for (i = 0; i < n; i++) {
    if (p[i] >= 0) {
      r.push_back(i + 1);
      for (j = i + 1; j < n && v[i] > 0; j++) {
        if (p[j] >= 0) {
          p[j] -= v[i];
          v[i]--;
          if (p[j] < 0) q.push(j);
        }
      }
      while (q.size()) {
        for (j = q.front() + 1; j < n; j++) {
          if (p[j] > 0) {
            p[j] -= d[q.front()];
            if (p[j] < 0) q.push(j);
          }
        }
        q.pop();
      }
    }
  }
  cout << r.size() << endl;
  for (i = 0; i < r.size(); i++) cout << r[i] << " ";
}
