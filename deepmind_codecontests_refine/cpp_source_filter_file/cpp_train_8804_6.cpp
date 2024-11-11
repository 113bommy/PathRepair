#include <bits/stdc++.h>
using namespace std;
struct data {
  int a, b, h;
};
const int N = 1e5 + 100;
int n;
data c[N];
long long f[N], it[4 * N];
int mx;
long long res;
void nen() {
  vector<int> v;
  map<int, int> m;
  v.push_back(0);
  for (int i = 1; i <= n; i++) {
    v.push_back(c[i].a);
    v.push_back(c[i].b);
  }
  sort(v.begin(), v.end());
  int cnt = 0;
  for (int i = 1; i < v.size(); i++)
    if (v[i] != v[i - 1]) {
      m[v[i]] = ++cnt;
    } else
      m[v[i]] = cnt;
  for (int i = 1; i <= n; i++) {
    c[i].a = m[c[i].a];
    c[i].b = m[c[i].b];
  }
}
bool cmp(data x, data y) { return (x.b > y.b || (x.b == y.b && x.a > y.a)); }
void update(int k, int l, int r, int pos, long long val) {
  if (pos < l || pos > r) return;
  if (l == r) {
    it[k] = max(it[k], val);
    return;
  }
  int m = (l + r) / 2;
  update(k * 2, l, m, pos, val);
  update(k * 2 + 1, m + 1, r, pos, val);
  it[k] = max(it[k * 2], it[k * 2 + 1]);
}
long long get(int k, int l, int r, int u, int v) {
  if (u > r || v < l) return 0;
  if (u <= l && v >= r) return it[k];
  int m = (l + r) / 2;
  return max(get(k * 2, l, m, u, v), get(k * 2 + 1, m + 1, r, u, v));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> c[i].a >> c[i].b >> c[i].h;
  nen();
  sort(c + 1, c + 1 + n, cmp);
  mx = c[1].b;
  for (int i = 1; i <= n; i++) {
    f[i] = get(1, 1, mx, 1, c[i].b) + c[i].h;
    res = max(res, f[i]);
    update(1, 1, mx, c[i].a, f[i]);
  }
  cout << res;
}
