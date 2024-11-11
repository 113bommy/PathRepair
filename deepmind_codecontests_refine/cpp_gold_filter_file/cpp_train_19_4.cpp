#include <bits/stdc++.h>
using namespace std;
const long long MAX = 3e5 + 5;
long long inf = (long long)30000;
long long mod = (long long)998244353;
long long ans = 0, vert;
long long n, k, par[MAX], sz[MAX], cnt[MAX][2], clr[MAX], pos[MAX];
vector<long long> sets[MAX];
vector<long long> b[MAX];
void x_or(long long dad) {
  for (int i = 0; i < sets[dad].size(); i++) {
    clr[sets[dad][i]] ^= 1;
  }
  cnt[dad][0] = 0;
  cnt[dad][1] = 0;
  for (int i = 0; i < sets[dad].size(); i++) {
    long long v = sets[dad][i];
    if (clr[v] == 0)
      cnt[dad][0]++;
    else
      cnt[dad][1]++;
  }
}
long long get(long long u) {
  if (par[u] == u)
    return u;
  else {
    long long v = get(par[u]);
    par[u] = v;
    return v;
  }
}
void unite(long long a, long long b) {
  if (get(a) == get(b)) return;
  if (sz[get(a)] < sz[get(b)]) swap(a, b);
  if (vert == 1 && clr[a] != clr[b]) x_or(get(b));
  if (vert == 0 && clr[a] == clr[b]) x_or(get(b));
  a = get(a);
  b = get(b);
  for (int i = 0; i < sets[b].size(); i++) sets[a].push_back(sets[b][i]);
  sets[b].clear();
  par[b] = a;
  sz[a] += sz[b];
  ans -= min(cnt[b][0], cnt[b][1]) + min(cnt[a][0], cnt[a][1]);
  cnt[a][0] += cnt[b][0];
  cnt[a][1] += cnt[b][1];
  ans += min(cnt[a][0], cnt[a][1]);
}
void unite_1(long long v, long long u) {
  if (vert == 1 && clr[v] != clr[u]) x_or(get(u));
  if (vert == 0 && clr[v] == clr[u]) x_or(get(u));
  v = get(v);
  u = get(u);
  par[u] = v;
  for (int i = 0; i < sets[u].size(); i++) {
    sets[v].push_back(sets[u][i]);
  }
  sets[u].clear();
  ans -= min(cnt[u][1], cnt[u][0]);
  ans += cnt[u][1];
  cnt[v][1] += cnt[u][1];
  cnt[v][0] += cnt[u][0];
}
void solve() {
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 1; i <= k; i++) {
    long long c;
    cin >> c;
    for (int j = 0; j < c; j++) {
      long long a;
      cin >> a;
      b[a].push_back(i);
    }
  }
  for (int i = 1; i <= k; i++) {
    sz[i] = 1;
    clr[i] = 0;
    cnt[i][0] = 1;
    par[i] = i;
    sets[i].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    vert = s[i - 1] - 48;
    if (b[i].size() == 1 && !pos[get(b[i][0])]) {
      long long v = b[i][0];
      if (clr[v] == 0 && vert == 0) x_or(get(v));
      if (clr[v] == 1 && vert == 1) x_or(get(v));
      ans -= min(cnt[get(v)][0], cnt[get(v)][1]);
      ans += cnt[get(v)][1];
      pos[get(v)] = 1;
    } else if (b[i].size() == 2) {
      if (pos[get(b[i][0])] || pos[get(b[i][1])]) {
        if (pos[get(b[i][0])] && pos[get(b[i][1])])
          ;
        else {
          long long u, v;
          v = b[i][0];
          u = b[i][1];
          if (pos[get(b[i][1])]) swap(u, v);
          unite_1(v, u);
        }
      } else {
        unite(b[i][0], b[i][1]);
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ios::sync_with_stdio(0);
  long long q;
  q = 1;
  while (q--) solve();
  return 0;
}
