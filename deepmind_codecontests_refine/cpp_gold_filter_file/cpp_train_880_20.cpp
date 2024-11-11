#include <bits/stdc++.h>
using namespace std;
int mult(int x, int y) {
  long long int ans, x1 = (long long int)x, y1 = (long long int)y;
  ans = (x1 * y1) % 1000000007;
  return (int)ans;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
long long int pow1(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return ans;
}
int mina(int arr[], int n) {
  int x = arr[0], i, pos = 0;
  for (i = 1; i < n; i++) {
    if (arr[i] < x) {
      x = arr[i];
      pos = i;
    }
  }
  return x;
}
int maxa(int arr[], int n) {
  int x = arr[0], i, pos = 0;
  for (i = 1; i < n; i++) {
    if (arr[i] > x) {
      x = arr[i];
      pos = i;
    }
  }
  return x;
}
int treex[400005], treey[400005];
void update(int* tree, int node, int low, int high, int pos, int val) {
  if (low == high) {
    tree[node] = val;
    return;
  }
  int mid = (low + high) >> 1;
  if (pos <= mid)
    update(tree, 2 * node, low, mid, pos, val);
  else
    update(tree, 2 * node + 1, mid + 1, high, pos, val);
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int query(int* tree, int node, int low, int high, int l, int r) {
  if (low == l and high == r) return tree[node];
  int mid = (low + high) >> 1;
  if (r <= mid) return query(tree, 2 * node, low, mid, l, r);
  if (mid + 1 <= l) return query(tree, 2 * node + 1, mid + 1, high, l, r);
  return min(query(tree, 2 * node, low, mid, l, mid),
             query(tree, 2 * node + 1, mid + 1, high, mid + 1, r));
}
vector<vector<int> > rx, ry;
vector<vector<pair<pair<int, int>, pair<int, int> > > > qx, qy;
bool ans[200005];
int main() {
  int x, y, n, m, i, j, k, q, x1, y1;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  scanf("%d", &q);
  rx.resize(n + 3);
  ry.resize(m + 3);
  qx.resize(n + 3);
  qy.resize(m + 3);
  for (i = 1; i < k + 1; i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    rx[x].push_back(y);
    ry[y].push_back(x);
  }
  for (i = 1; i < q + 1; i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &x1);
    scanf("%d", &y1);
    qx[x1].push_back(make_pair(make_pair(i, x), make_pair(y, y1)));
    qy[y1].push_back(make_pair(make_pair(i, y), make_pair(x, x1)));
  }
  for (i = 1; i < n + 1; i++) {
    for (j = 0; j < rx[i].size(); j++) update(treey, 1, 1, m, rx[i][j], i);
    for (j = 0; j < qx[i].size(); j++) {
      if (query(treey, 1, 1, m, qx[i][j].second.first,
                qx[i][j].second.second) >= qx[i][j].first.second)
        ans[qx[i][j].first.first] = 1;
    }
  }
  for (i = 1; i < m + 1; i++) {
    for (j = 0; j < ry[i].size(); j++) update(treex, 1, 1, n, ry[i][j], i);
    for (j = 0; j < qy[i].size(); j++) {
      if (query(treex, 1, 1, n, qy[i][j].second.first,
                qy[i][j].second.second) >= qy[i][j].first.second)
        ans[qy[i][j].first.first] = 1;
    }
  }
  for (i = 1; i < q + 1; i++)
    if (ans[i])
      printf("YES\n");
    else
      printf("NO\n");
  return 0;
}
