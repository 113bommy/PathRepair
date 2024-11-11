#include <bits/stdc++.h>
using namespace ::std;
const long long maxn = 1e5 + 50;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 500;
vector<pair<long long, long long> > yal[maxn * 4];
map<pair<long long, long long>, long long> ml;
set<pair<long long, long long> > yalha;
bool ans[maxn];
vector<pair<long long, bool> > syal;
long long sz[maxn];
long long par[maxn];
bool rang[maxn];
pair<long long, bool> find_par(long long a) {
  if (par[a] == a) {
    return make_pair(a, 0);
  }
  pair<long long, bool> e = find_par(par[a]);
  e.second ^= rang[a];
  return e;
}
long long kharab = 0;
void add(pair<long long, long long> e) {
  if (kharab) {
    kharab++;
    return;
  }
  long long v = e.first;
  long long u = e.second;
  pair<long long, bool> pv = find_par(v);
  pair<long long, bool> pu = find_par(u);
  if (pv.first == pu.first) {
    if (pv.second == pu.second) {
      kharab = 1;
      return;
    } else {
      syal.push_back(make_pair(0, 0));
    }
  } else {
    if (sz[pv.first] < sz[pu.first]) {
      swap(pv, pu);
    }
    par[pu.first] = pv.first;
    sz[pv.first] += sz[pu.first];
    rang[pu.first] = (1 ^ pv.second ^ pu.second);
    syal.push_back(make_pair(pu.first, 1));
  }
}
void pop_yal() {
  if (kharab) {
    kharab--;
    return;
  }
  if (syal.back().second == 0) {
    syal.pop_back();
  } else {
    long long v = syal.back().first;
    sz[par[v]] -= sz[v];
    par[v] = v;
    rang[v] = 0;
    syal.pop_back();
  }
}
bool check_is_bid() {
  if (kharab) {
    return 0;
  }
  return 1;
}
void add_yal(long long L, long long R, long long node, long long l, long long r,
             pair<long long, long long> e) {
  if (l <= L && R <= r) {
    yal[node].push_back(e);
    return;
  }
  if (r <= L || R <= l) {
    return;
  }
  long long mid = (L + R) / 2;
  add_yal(L, mid, 2 * node, l, r, e);
  add_yal(mid, R, 2 * node + 1, l, r, e);
}
void dfs(long long l, long long r, long long node) {
  for (auto e : yal[node]) {
    add(e);
  }
  if (l + 1 == r) {
    ans[l] = check_is_bid();
  } else {
    long long mid = (l + r) / 2;
    dfs(l, mid, 2 * node);
    dfs(mid, r, 2 * node + 1);
  }
  for (auto e : yal[node]) {
    pop_yal();
  }
}
int main() {
  for (long long i = 0; i < maxn; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  long long n, q;
  cin >> n >> q;
  for (long long i = 1; i <= q; i++) {
    long long v, u;
    cin >> v >> u;
    v--;
    u--;
    yalha.insert(make_pair(v, u));
    if (ml[make_pair(v, u)]) {
      add_yal(0, maxn, 1, ml[make_pair(v, u)], i, make_pair(v, u));
      ml[make_pair(v, u)] = 0;
    } else {
      ml[make_pair(v, u)] = i;
    }
  }
  for (auto e : yalha) {
    if (ml[e]) {
      add_yal(0, maxn, 1, ml[e], q + 1, e);
      ml[e] = 0;
    }
  }
  dfs(0, maxn, 1);
  for (long long i = 1; i <= q; i++) {
    if (ans[i]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
