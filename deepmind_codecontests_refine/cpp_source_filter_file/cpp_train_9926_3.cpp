#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 10;
const long long MAXE = 3e5 + 10;
const long long INF = 2e18 + 3;
long long n, m, k, ec;
long long from[2 * MAXE], to[2 * MAXE], prv[2 * MAXE], w[2 * MAXE], head[MAXN],
    sec[2 * MAXE];
long long comp[MAXN], d[MAXN], ss[MAXN];
bool portal[MAXN], mark[MAXN];
set<pair<long long, long long>> st;
long long ans = 0;
void add_edge(long long u, long long v, long long c) {
  from[ec] = u, to[ec] = v, w[ec] = c, prv[ec] = head[u];
  head[u] = ec++;
}
long long get_min() {
  pair<long long, long long> fr = *st.begin();
  st.erase(st.begin());
  return fr.second;
}
void update(long long v) {
  mark[v] = 1;
  for (long long e = head[v]; e != -1; e = prv[e]) {
    long long u = to[e], c = w[e];
    if (!mark[u] && d[u] > w[e] + d[v]) {
      st.erase({d[u], u});
      d[u] = d[v] + w[e];
      st.insert({d[u], u});
      ss[u] = ss[v];
    }
  }
}
void dijk() {
  fill(d, d + MAXN, INF);
  memset(ss, -1, sizeof(ss));
  for (long long i = 0; i < n; i++)
    if (portal[i]) mark[i] = 1, d[i] = 0, ss[i] = i;
  for (long long i = 0; i < n; i++)
    if (portal[i]) update(i);
  while (st.size()) update(get_min());
}
bool cmp(long long e1, long long e2) {
  if (w[e1] != w[e2]) return w[e1] < w[e2];
  return e1 < e2;
}
long long get_comp(long long v) {
  if (comp[v] == v) return v;
  return comp[v] = get_comp(comp[v]);
}
void merge(long long e) {
  if (get_comp(ss[to[e]]) == get_comp(ss[from[e]])) return;
  ans += w[e];
  comp[get_comp(ss[to[e]])] = get_comp(ss[from[e]]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  memset(head, -1, sizeof(head));
  while (m--) {
    long long a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    add_edge(a, b, c);
    add_edge(b, a, c);
  }
  cin >> k;
  while (k--) {
    long long temp;
    cin >> temp, temp--, portal[temp] = 1;
  }
  dijk();
  ans = d[0];
  iota(comp, comp + n, 0);
  iota(sec, sec + ec, 0);
  for (int i = 0; i < ec; i++) w[ec] += d[from[i]] + d[to[i]];
  sort(sec, sec + ec, cmp);
  for (long long e = 0; e < ec; e++) merge(sec[e]);
  cout << ans << endl;
  return 0;
}
