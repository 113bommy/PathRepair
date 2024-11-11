#include <bits/stdc++.h>
using namespace std;
static auto faster_iostream = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  return 0;
}();
void print() { cout << '\n'; }
template <class T, class... U>
void print(T x, U... y) {
  cout << x << ' ';
  print(y...);
}
const int N = 2e5 + 5, M = 1e9 + 7;
long long qpow(long long x, long long n) {
  long long res = 1;
  for (; n; n >>= 1, x = x * x % M)
    if (n & 1) res = res * x % M;
  return res;
}
struct node {
  int x, y, z, id;
  bool operator<(const node &b) const {
    if (x != b.x) return x < b.x;
    if (y != b.y) return y < b.y;
    if (z != b.z) return z < b.z;
    return id < b.id;
  }
} a[N], b[N];
int bit[N];
void add(int p, int x) {
  for (; p < N; p += p & -p) bit[p] += x;
}
int get(int p) {
  int res = 0;
  for (; p; p -= p & -p) res += bit[p];
  return res;
}
int ans[N];
void cdq(int l, int r) {
  if (r - l <= 1) return;
  int mid = l + r >> 1;
  cdq(l, mid);
  cdq(mid, r);
  int i = l, j = mid, k = l;
  while (i < mid && j < r) {
    if (a[i].y <= a[j].y) {
      if (!a[i].id) add(a[i].z, 1);
      b[k++] = a[i++];
    } else {
      if (a[j].id) ans[a[j].id] += get(a[j].z);
      b[k++] = a[j++];
    }
  }
  while (j < r) {
    if (a[j].id) ans[a[j].id] += get(a[j].z);
    b[k++] = a[j++];
  }
  for (int t = l; t < i; t++)
    if (!a[t].id) add(a[t].z, -1);
  while (i < mid) b[k++] = a[i++];
  while (l < r) a[l] = b[l], l++;
}
int x[N], y[N], z[N], p[N], q[N];
int bk[N], tot, len;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> y[i];
  for (int i = 0; i < n; i++) cin >> z[i];
  for (int i = 0; i < n; i++) {
    int u = x[i] + z[i], v = x[i] - z[i], w = -y[i];
    bk[tot++] = u, bk[tot++] = v, bk[tot++] = w;
  }
  for (int i = 0; i < m; i++) cin >> p[i];
  for (int i = 0; i < m; i++) cin >> q[i];
  for (int i = 0; i < m; i++) {
    int u = p[i] + q[i], v = p[i] - q[i], w = -p[i];
    bk[tot++] = u, bk[tot++] = v, bk[tot++] = w;
  }
  sort(bk, bk + tot);
  len = unique(bk, bk + tot) - bk;
  tot = 0;
  auto g = [](int x) { return lower_bound(bk, bk + len, x) - bk + 1; };
  for (int i = 0; i < n; i++) {
    int u = x[i] + z[i], v = x[i] - z[i], w = -y[i];
    a[tot].x = g(u), a[tot].y = g(v), a[tot].z = g(w);
    tot++;
  }
  for (int i = 0; i < m; i++) {
    int u = p[i] + q[i], v = p[i] - q[i], w = -p[i];
    a[tot].x = g(u), a[tot].y = g(v), a[tot].z = g(w), a[tot].id = i + 1;
    tot++;
  }
  sort(a, a + tot);
  cdq(0, tot);
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << " \n"[i == m];
  }
}
