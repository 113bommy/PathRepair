#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 69;
long long n, a, d[N], c[N], s[N], g[N], l[N], r[N], res = 0;
struct segment_tree {
  vector<long long> it;
  int type;
  long long oo;
  segment_tree(int _type) {
    type = _type;
    if (type)
      oo = -1e18;
    else
      oo = 1e18;
    it.resize(4 * N);
  }
  long long opt(long long a, long long b) {
    if (type) return max(a, b);
    return min(a, b);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      it[p] = s[l];
      return;
    }
    int m = (l + r) / 2;
    build(p * 2, l, m);
    build(p * 2 + 1, m + 1, r);
    it[p] = opt(it[p * 2], it[p * 2 + 1]);
  }
  long long get(int p, int l, int r, int ql, int qr) {
    if (ql > r || l > qr) return oo;
    if (ql <= l && r <= qr) return it[p];
    int m = (l + r) / 2;
    return opt(get(p * 2, l, m, ql, qr), get(p * 2 + 1, m + 1, r, ql, qr));
  }
} it_max(1), it_min(0);
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a;
  for (int i = 1; i <= n; i++) {
    cin >> d[i] >> c[i];
    res = max(res, a - c[i]);
  }
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a - c[i];
  for (int i = 1; i < n; i++) g[i] = (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
  it_min.build(1, 1, n);
  it_max.build(1, 1, n);
  for (int i = 1; i < n; i++) {
    l[i] = i;
    while (l[i] != 1 && g[l[i] - 1] <= g[i]) l[i] = l[l[i] - 1];
  }
  for (int i = n - 1; i > 1; i--) {
    r[i] = i;
    while (r[i] != n - 1 && g[r[i] + 1] <= g[i]) r[i] = r[r[i] + 1];
  }
  for (int i = 1; i < n; i++)
    res = max(res, it_max.get(1, 1, n, i + 1, r[i] + 1) -
                       it_min.get(1, 1, n, l[i] - 1, i - 1) - g[i]);
  cout << res;
}
