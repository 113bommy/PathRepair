#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int n, m, q;
int a[maxn], b[maxn];
int val[2 * maxn], p[2 * maxn];
multiset<pair<int, bool>> S[2 * maxn];
set<pair<int, ll>> ans;
int ata(int nd) {
  if (p[nd] == nd) return nd;
  return p[nd] = ata(p[nd]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> q;
  vector<pair<int, bool>> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back({a[i], 0});
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    v.push_back({b[i], 1});
  }
  sort(v.begin(), v.end());
  map<int, vector<int>> seg;
  ll now = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    if (v[i].second == 0)
      val[i] = v[i].first, now += v[i].first;
    else
      val[i] = 1e9;
    S[i].insert({v[i].first, (v[i].second == 0)});
    p[i] = i;
  }
  ans.insert({0, now});
  for (int i = 1; i < (int)v.size(); i++)
    seg[v[i].first - v[i - 1].first].push_back(i);
  for (auto i : seg) {
    for (auto j : i.second) {
      int a = ata(j - 1);
      int b = ata(j);
      int go = a, lit = b;
      if ((int)S[b].size() > (int)S[a].size()) go = b, lit = a;
      auto cep = S[a].lower_bound({val[a], 1});
      auto sag = S[b].lower_bound({val[b], 1});
      vector<pair<int, int>> er;
      while (cep != S[a].end() and sag != S[b].begin()) {
        sag--;
        er.push_back({(*cep).first, (*sag).first});
        cep++;
      }
      if (sag != S[b].begin()) {
        if (sag == S[b].end())
          val[go] = 1e9;
        else
          val[go] = (*sag).first;
      } else {
        if (cep == S[a].end()) {
          if (sag == S[b].end())
            val[go] = 1e9;
          else
            val[go] = (*sag).first;
        } else
          val[go] = (*cep).first;
      }
      for (auto k : er) {
        now -= k.first;
        now += k.second;
        S[a].erase(S[a].find({k.first, 1}));
        S[b].erase(S[b].find({k.second, 0}));
        S[a].insert({k.first, 0});
        S[b].insert({k.second, 1});
      }
      p[lit] = go;
      for (auto k : S[lit]) S[go].insert(k);
      S[lit].clear();
    }
    if (i.first == 0) ans.erase(ans.begin());
    ans.insert({i.first, now});
  }
  while (q--) {
    int k;
    cin >> k;
    auto t = ans.upper_bound({k, 1e9});
    t--;
    cout << (*t).second << '\n';
  }
}
