#include <bits/stdc++.h>
using namespace std;
const int N = 500100;
struct C {
  int x, y;
  C(int x = 0, int y = 0) : x(x), y(y) {}
  long long operator*(const C& a) const {
    return (long long)x * a.x + (long long)y * a.y;
  }
  long long operator/(const C& a) const {
    return (long long)x * a.y - (long long)y * a.x;
  }
  C conj() const { return C(x, -y); }
  bool operator+(const C& a) const {
    long long u = *this * a.conj(), v = *this / a.conj();
    return !u || !v || ((u > 0) ^ (v > 0));
  }
  bool operator<(const C& a) const { return *this / a < 0; }
  bool operator!=(const C& a) const { return *this < a || a < *this; }
  bool operator==(const C& a) const { return !(*this != a); }
};
int mx[N * 4], q1, q2, q3;
void mdf(int o, int l, int r) {
  if (l == r) {
    mx[o] = q2;
    return;
  }
  int mid = (l + r) / 2;
  if (q1 <= mid)
    mdf(o * 2, l, mid);
  else
    mdf(o * 2 + 1, mid + 1, r);
  mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
}
void qry(int o, int l, int r) {
  if (q1 <= l && r <= q2) {
    q3 = max(q3, mx[o]);
    return;
  }
  int mid = (l + r) / 2;
  if (q1 <= mid) qry(o * 2, l, mid);
  if (q2 > mid) qry(o * 2 + 1, mid + 1, r);
}
int R, q, opt[N], u[N], v[N], w[N], cnt, id[N], fi[N];
pair<C, C> a[N];
C f[N], g[N];
pair<pair<int, int>, int> b[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> R >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> opt[i] >> u[i];
    if (opt[i] != 2) cin >> v[i];
    if (opt[i] == 1) {
      w[i] = ++cnt;
      a[cnt] =
          make_pair(f[cnt] = C(-u[i] - R, v[i]), g[cnt] = C(u[i] - R, v[i]));
    }
  }
  sort(f + 1, f + cnt + 1);
  sort(g + 1, g + cnt + 1);
  int cntl = unique(f + 1, f + cnt + 1) - f - 1,
      cntr = unique(g + 1, g + cnt + 1) - g - 1;
  for (int i = 1; i <= cnt; ++i)
    b[i] =
        make_pair(make_pair(lower_bound(f + 1, f + cntl + 1, a[i].first) - f,
                            lower_bound(g + 1, g + cntr + 1, a[i].second) - g),
                  i);
  sort(b + 1, b + cnt + 1);
  for (int i = cnt; i; --i) id[b[i].second] = i, fi[b[i].first.first] = i;
  for (int i = 1; i <= q; ++i)
    if (opt[i] == 1) {
      q1 = id[w[i]];
      q2 = b[q1].first.second;
      mdf(1, 1, cnt);
    } else if (opt[i] == 2) {
      q1 = id[u[i]];
      q2 = 0;
      mdf(1, 1, cnt);
    } else {
      int x = id[u[i]], y = id[v[i]],
          l = min(b[x].first.first, b[y].first.first),
          r = min(b[x].first.second, b[y].first.second);
      if (x > y) swap(x, y);
      if (f[l] + g[r]) {
        int ql = fi[l], qr = cnt;
        q3 = 0;
        q1 = ql;
        q2 = x - 1;
        if (q1 <= q2) qry(1, 1, cnt);
        q1 = x + 1;
        q2 = y - 1;
        if (q1 <= q2) qry(1, 1, cnt);
        q1 = y + 1;
        q2 = qr;
        if (q1 <= q2) qry(1, 1, cnt);
        if (q3 < r)
          cout << "YES\n";
        else
          cout << "NO\n";
      } else
        cout << "NO\n";
    }
  return 0;
}
