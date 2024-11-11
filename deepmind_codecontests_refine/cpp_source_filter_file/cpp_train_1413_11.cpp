#include <bits/stdc++.h>
using namespace std;
struct data {
  struct hash_table {
    static const int n = 1000010, mod = 1000007;
    int h[n];
    int val[n];
    int f, p, c, link[n], last[mod];
    hash_table() : f(0), p(0), c(0) { memset(last, -1, sizeof last); }
    inline int *find(int hash) {
      for (f = -1, p = last[hash % mod]; p != -1; f = p, p = link[p])
        if (h[p] == hash) return &val[p];
      return NULL;
    }
    inline void set(int hash, int num) {
      if (find(hash) != NULL)
        val[p] = num;
      else {
        h[c] = hash;
        val[c] = num;
        hash %= mod;
        link[c] = last[hash];
        last[hash] = c++;
      }
    }
    inline void erase(int hash) {
      if (find(hash) == NULL) return;
      if (f == -1)
        last[hash % mod] = link[p];
      else
        link[f] = link[p];
    }
  } mp;
  int a, x;
  data() : a(0), x(0) {}
} dp;
struct data2 {
  int a, x;
  vector<pair<int, int>> mp;
  data2() : a(0), x(0) {}
};
const int oo = -1e9;
const int N = 5 * 1e5 + 5;
int ans[N], sz[N];
vector<pair<int, int>> adj[N];
pair<int, int> bigch[N];
void getsz(int u, int p) {
  sz[u] = 1;
  int mx = 0;
  for (auto v : adj[u])
    if (v.first != p) {
      getsz(v.first, u);
      sz[u] += sz[v.first];
      if (sz[v.first] > mx) mx = sz[v.first], bigch[u] = v;
    }
}
vector<pair<int, int>> *rec[N];
data2 *mp[N];
int *it;
void dfs(int u, int f, bool keep) {
  for (auto v : adj[u])
    if (v.first != f && v.first != bigch[u].first) {
      dfs(v.first, u, false);
      ans[u] = max(ans[u], ans[v.first]);
    }
  int id = bigch[u].first, m = bigch[u].second;
  if (id != -1) {
    dfs(id, u, true);
    mp[u] = mp[id];
    rec[u] = rec[id];
    ans[u] = max(ans[u], max(1, ans[id]));
    dp.x ^= m, ++dp.a;
    mp[u]->x ^= m, ++mp[u]->a;
    it = dp.mp.find(m ^ dp.x);
    if (it == NULL || *it < 1 - dp.a) {
      rec[u]->push_back({m ^ dp.x, (it == NULL ? oo : *it)});
      dp.mp.set(m ^ dp.x, 1 - dp.a);
      mp[u]->mp.push_back({m ^ mp[u]->x, 1 - mp[u]->a});
    }
    for (auto k : adj[u])
      if (k.first != id && k.first != f) {
        auto &ch = *mp[k.first];
        for (auto i : ch.mp) {
          it = dp.mp.find(i.first ^ ch.x ^ k.second ^ dp.x);
          if (it != NULL)
            ans[u] = max(ans[u], *it + dp.a + i.second + ch.a + 1);
          for (int j = 0; j < 26; ++j) {
            it = dp.mp.find(i.first ^ ch.x ^ k.second ^ 1 << j ^ dp.x);
            if (it != NULL)
              ans[u] = max(ans[u], *it + dp.a + i.second + ch.a + 1);
          }
        }
        for (int j = 0; j < 26; ++j) {
          it = dp.mp.find(k.second ^ 1 << j ^ dp.x);
          if (it != NULL) ans[u] = max(ans[u], *it + dp.a + 1);
        }
        it = dp.mp.find(k.second ^ dp.x);
        if (it != NULL) ans[u] = max(ans[u], *it + dp.a + 1);
        if (it == NULL || *it < 1 - dp.a) {
          rec[u]->push_back({k.second ^ dp.x, (it == NULL ? oo : *it)});
          dp.mp.set(k.second ^ dp.x, 1 - dp.a);
          mp[u]->mp.push_back({k.second ^ mp[u]->x, 1 - mp[u]->a});
        }
        for (auto i : ch.mp) {
          it = dp.mp.find(i.first ^ ch.x ^ dp.x ^ k.second);
          if (it == NULL || *it < i.second + ch.a + 1 - dp.a) {
            rec[u]->push_back(
                {i.first ^ ch.x ^ dp.x ^ k.second, (it == NULL ? oo : *it)});
            dp.mp.set(i.first ^ ch.x ^ dp.x ^ k.second,
                      i.second + ch.a + 1 - dp.a);
            mp[u]->mp.push_back({i.first ^ ch.x ^ mp[u]->x ^ k.second,
                                 i.second + ch.a + 1 - mp[u]->a});
          }
        }
      }
    it = dp.mp.find(dp.x);
    if (it != NULL) ans[u] = max(ans[u], *it + dp.a);
    for (int i = 0; i < 26; ++i) {
      it = dp.mp.find(1 << i ^ dp.x);
      if (it != NULL) ans[u] = max(ans[u], *it + dp.a);
    }
  } else {
    rec[u] = new vector<pair<int, int>>();
    mp[u] = new data2();
  }
  if (!keep) {
    if (id != -1) dp.x ^= m, --dp.a;
    for (auto i = rec[u]->rbegin(); i != rec[u]->rend(); ++i) {
      if (i->second == oo)
        dp.mp.erase(i->first);
      else
        dp.mp.set(i->first, i->second);
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  char c;
  for (int i = 1, u; i < n; ++i) {
    cin >> u >> c;
    adj[--u].push_back({i, 1 << (c - 'a')});
    adj[i].push_back({u, 1 << (c - 'a')});
    bigch[i].first = -1;
  }
  bigch[0].first = -1;
  getsz(0, -1);
  dfs(0, -1, true);
  for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n];
  return 0;
}
