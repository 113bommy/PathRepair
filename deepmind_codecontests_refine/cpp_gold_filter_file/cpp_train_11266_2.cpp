#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
long long b[N], t[4 * N], o[4 * N];
void build(int v, int l, int r) {
  if (l == r) {
    t[v] = b[l];
  } else {
    int m = (r + l) >> 1;
    build(v + v + 1, l, m);
    build(v + v + 2, m + 1, r);
    t[v] = min(t[v + v + 1], t[v + v + 2]);
  }
}
void push(int v) {
  t[v] += o[v];
  if (v + v + 2 < 4 * N) {
    o[v + v + 1] += o[v];
    o[v + v + 2] += o[v];
  }
  o[v] = 0;
}
void update(int v, int l, int r, int tl, int tr, int val) {
  if (tl > tr) return;
  if (tl == l && tr == r) {
    o[v] += val;
    push(v);
  } else {
    push(v);
    int m = (r + l) >> 1;
    update(v + v + 1, l, m, tl, min(m, tr), val);
    update(v + v + 2, m + 1, r, max(m + 1, tl), tr, val);
    t[v] = min(t[v + v + 1], t[v + v + 2]);
  }
}
void update(int tl, int tr, int val, int n) {
  update(0, 0, n - 1, tl, tr, val);
}
long long findMin(int v, int l, int r, int tl, int tr) {
  push(v);
  if (tl > tr) return 1e18;
  if (tl == l && tr == r) {
    return t[v];
  }
  int m = (r + l) >> 1;
  long long t1 = findMin(v + v + 1, l, m, tl, min(m, tr));
  long long t2 = findMin(v + v + 2, m + 1, r, max(m + 1, tl), tr);
  return min(t1, t2);
}
long long findMin(int tl, int tr, int n) {
  return findMin(0, 0, n - 1, tl, tr);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int p[n], pos[n + 1];
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    b[i] = sum, sum += a[i];
  }
  b[n] = sum;
  build(0, 0, n);
  long long ans = findMin(1, n - 1, n + 1);
  for (int val = 1; val <= n; ++val) {
    update(0, pos[val], a[pos[val]], n + 1);
    update(pos[val] + 1, n, -a[pos[val]], n + 1);
    ans = min(ans, findMin(1, n - 1, n + 1));
  }
  cout << ans;
}
