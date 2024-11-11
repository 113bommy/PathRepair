#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long n, T, fen[maxn], cn[maxn], w[maxn], a[maxn], t[maxn];
int re, rk;
pair<long long, int> p[maxn], q[maxn];
vector<int> ve[maxn], f;
void up(int u, long long x) {
  for (int i = u; i <= n; i += (i & (-i))) {
    fen[i] += x;
    cn[i]++;
  }
}
long long gt1(int u) {
  long long o = 0;
  for (int i = u; i > 0; i -= (i & (-i))) {
    o += fen[u];
  }
  return o;
}
long long gt2(int u) {
  long long o = 0;
  for (int i = u; i > 0; i -= (i & (-i))) {
    o += cn[u];
  }
  return o;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> T;
  for (int i = 1; i < n + 1; ++i) {
    cin >> a[i] >> t[i];
    p[i] = {t[i], i};
    ve[a[i]].push_back(i);
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i < n + 1; ++i) {
    w[p[i].second] = i;
  }
  for (int i = n; i >= 1; i--) {
    for (auto u : ve[i]) {
      up(w[u], t[u]);
    }
    int l = 0, r = n + 1;
    while (r - l > 1) {
      int md = (l + r) >> 1;
      if (gt1(md) > T)
        r = md;
      else
        l = md;
    }
    int h = min((long long)i, gt2(l));
    if (h >= re) {
      re = h;
      rk = i;
    }
  }
  cout << re << endl << re << endl;
  for (int i = 1; i < n + 1; ++i) {
    if (f.size() == re) break;
    if (rk <= a[p[i].second]) f.push_back(p[i].second);
  }
  for (auto u : f) cout << u << ' ';
  return 0;
}
