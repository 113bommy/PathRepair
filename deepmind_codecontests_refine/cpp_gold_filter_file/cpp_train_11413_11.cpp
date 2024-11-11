#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T &x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T &x, L y) {
  return y < x ? (x = y, 1) : 0;
}
const int maxn = 1e5 + 17;
struct E {
  int v, u, w, idx;
} e[maxn];
int n, par[maxn], dpar[maxn], iman[maxn], st[maxn], en[maxn], h[maxn];
long long res[maxn];
vector<int> g[maxn];
void majid(int p, int v) {
  for (p++; p < maxn; p += p & -p) iman[p] += v;
}
int hamid(int p) {
  int ans = 0;
  for (; p; p ^= p & -p) ans += iman[p];
  return ans;
}
int hamid(int l, int r) { return hamid(r) - hamid(l); }
int r(int v) { return ~par[v] ? par[v] = r(par[v]) : v; }
void set_ord(int v = 0) {
  static int tim = 0;
  st[v] = tim++;
  for (auto u : g[v])
    if (u != dpar[v]) {
      h[u] = h[v] + 1;
      dpar[u] = v;
      set_ord(u);
    }
  en[v] = tim;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> e[i].v >> e[i].u >> e[i].w;
    e[i].idx = i + 1;
    e[i].v--, e[i].u--;
    g[e[i].v].push_back(e[i].u);
    g[e[i].u].push_back(e[i].v);
  }
  dpar[0] = -1;
  set_ord();
  for (int i = 0; i < n - 1; i++)
    if (e[i].u == dpar[e[i].v]) swap(e[i].v, e[i].u);
  sort(e, e + n - 1,
       [](E &a, E &b) { return a.w != b.w ? a.w < b.w : h[a.v] < h[b.v]; });
  memset(par, -1, sizeof par);
  for (int v = 0; v < n; v++) majid(st[v], 1);
  for (int v = 1; v < n; v++) majid(st[dpar[v]], -1);
  for (int i = 0, j = 0; i < n - 1; i = j) {
    while (j < n - 1 && e[j].w == e[i].w) j++;
    for (int k = i; k < j; k++) {
      majid(st[e[k].v], hamid(st[e[k].u], en[e[k].u]));
      int who = r(e[k].v);
      if (~dpar[who]) majid(st[dpar[who]], -hamid(st[e[k].u], en[e[k].u]));
      par[e[k].u] = who;
    }
    for (int k = i; k < j; k++) {
      int down = hamid(st[e[k].u], en[e[k].u]),
          up = hamid(st[par[e[k].u]], en[par[e[k].u]]);
      res[k] = (long long)down * (up - down) * 2;
    }
  }
  long long ans = *max_element(res, res + n - 1);
  vector<int> cer;
  for (int i = 0; i < n - 1; i++)
    if (res[i] == ans) cer.push_back(e[i].idx);
  cout << ans << ' ' << cer.size() << '\n';
  sort(cer.begin(), cer.end());
  for (auto x : cer) cout << x << ' ';
  cout << '\n';
  return 0;
}
