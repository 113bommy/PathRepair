#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
const int mod = 1e9 + 7;
int n, m, t, k, ans, tong, a[N], b[N], lab[N], u, v, q, qu[N], c[N], d[N],
    res[N];
string s;
vector<int> adj[N];
struct edge {
  int u, v, l, r;
};
vector<edge> kq;
int findp(int u) { return lab[u] < 0 ? u : findp(lab[u]); }
void hop(int u, int v) {
  if (lab[u] > lab[v]) swap(u, v);
  kq.push_back({u, v, lab[u], lab[v]});
  lab[u] += lab[v];
  lab[v] = u;
}
void rollback() {
  edge x = kq.back();
  lab[x.u] = x.l;
  lab[x.v] = x.r;
  kq.pop_back();
}
void cal(int l, int r, vector<edge> e) {
  vector<edge> now;
  int cnt = 0;
  for (edge x : e) {
    if (x.l <= l && r <= x.r) {
      int u = findp(x.u), v = findp(x.v);
      if (u != v) {
        ++cnt;
        hop(u, v);
      }
    } else if (x.l > r || l > x.r)
      continue;
    else {
      now.push_back(x);
    }
  }
  if (qu[l] == 2 && l == r) {
    res[l] = -lab[findp(a[l])];
  }
  if (l < r) {
    int mid = (l + r) / 2;
    cal(l, mid, now);
    cal(mid + 1, r, now);
  }
  while (cnt-- > 0) rollback();
}
void sol() {
  cin >> n >> q >> k;
  fill_n(lab, n + 2, -1);
  fill_n(d, q + k + 2, q);
  for (int i = 1; i <= q; i++) {
    cin >> qu[i];
    c[i] = t;
    if (qu[i] == 1)
      cin >> a[i] >> b[i];
    else if (qu[i] == 2)
      cin >> a[i];
    else {
      d[t] = i;
      ++t;
    }
  }
  vector<edge> e;
  for (int i = 1; i <= q; i++) {
    if (qu[i] == 1) {
      edge x;
      x.u = a[i];
      x.v = b[i];
      x.l = i;
      x.r = d[c[i] + k - 1];
      e.push_back(x);
    }
  }
  cal(1, q, e);
  for (int i = 1; i <= q; i++)
    if (qu[i] == 2) cout << res[i] << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest = 1;
  while (ntest-- > 0) sol();
}
