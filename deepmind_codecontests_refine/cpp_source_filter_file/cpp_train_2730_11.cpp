#include <bits/stdc++.h>
using namespace std;
namespace seg {
long long dat[2 * 1000010];
void init() {
  for (int i = 0; i < 2 * 1000010; i++) dat[i] = 1e17;
}
void upd(long long l, long long r, long long x) {
  l += 1000010, r += 1000010 + 1;
  for (long long a = l, b = r; a < b; a >>= 1, b >>= 1) {
    if (a & 1) {
      dat[a] = min(dat[a], x);
      a++;
    }
    if (b & 1) {
      b--;
      dat[b] = min(dat[b], x);
    }
  }
}
long long qry(long long i) {
  i += 1000010;
  long long res = 1e17;
  for (; i; i >>= 1) {
    res = min(res, dat[i]);
  }
  return res;
}
}  // namespace seg
long long n, k;
bool incs[1000010];
long long incid[1000010];
vector<long long> inc;
vector<long long> g[1000010];
char ch[1000010];
vector<long long> C;
long long dis[1000010], fin[1000010], cc;
void dfs1(long long x) {
  dis[x] = cc++;
  if (incs[x]) {
    incid[x] = C.size();
    C.push_back(dis[x]);
  }
  vector<pair<char, long long> > v;
  for (auto y : g[x]) v.push_back(make_pair(ch[y], y));
  sort(v.begin(), v.end());
  for (auto e : v) {
    dfs1(e.second);
  }
  fin[x] = cc;
}
long long dist[1000010];
void dfs2(long long x, long long cost) {
  if (incs[x]) {
    cost = min(cost, seg::qry(dis[x]) + incid[x]);
  }
  dist[x] = cost;
  auto il = lower_bound(C.begin(), C.end(), dis[x]);
  auto ir = upper_bound(C.begin(), C.end(), fin[x]);
  if (il != C.end() && ir != C.begin()) {
    ir--;
    long long l = *il;
    long long r = *ir;
    seg::upd(l, r, cost - (il - C.begin() - 1));
  }
  for (auto y : g[x]) {
    dfs2(y, cost + 1);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long p;
    cin >> p >> ch[i];
    g[p].push_back(i);
  }
  for (int i = 0; i < n + 1; i++) incs[i] = 0;
  cin >> k;
  for (int i = 0; i < k; i++) {
    long long a;
    cin >> a;
    incs[a] = 1;
    inc.push_back(a);
  }
  cc = 0;
  dfs1(0);
  seg::init();
  dfs2(0, 0);
  for (auto c : inc) cout << dist[c] << "\n";
}
