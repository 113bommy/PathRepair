#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long nmax = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long mod1 = 998244353;
const long long inf = 1e18;
long long n, m, L, s, t, dist[1005], dist1[1005], tab[1005][1005],
    pop[1005][1005], tab1[1005][1005];
vector<pair<long long, long long>> nod[1005];
vector<long long> road[1005];
void djkstra(long long s) {
  multiset<pair<long long, long long>> dadoamne;
  for (auto it : nod[s]) {
    dadoamne.insert({it.second, it.first});
    dist[it.first] = it.second;
  }
  while (dadoamne.empty() == false) {
    auto it = dadoamne.begin();
    for (auto it1 : nod[it->second]) {
      if (((it->first) + it1.second) < dist[it1.first]) {
        if (dist[it1.first] != inf)
          dadoamne.erase(dadoamne.find({dist[it1.first], it1.first}));
        dist[it1.first] = (it->first) + it1.second;
        dadoamne.insert({dist[it1.first], it1.first});
      }
    }
    dadoamne.erase(it);
  }
}
void djkstra2(long long s) {
  multiset<pair<long long, long long>> dadoamne;
  for (long long i = 0; i < n; i++) dist1[i] = inf;
  dist1[s] = 0;
  for (auto it : nod[s]) {
    dadoamne.insert({it.second, it.first});
    dist1[it.first] = it.second;
    road[it.first].push_back(s);
  }
  while (dadoamne.empty() == false) {
    auto it = dadoamne.begin();
    for (auto it1 : nod[it->second]) {
      if (((it->first) + it1.second) < dist1[it1.first]) {
        if (dist1[it1.first] != inf) {
          dadoamne.erase(dadoamne.find({dist1[it1.first], it1.first}));
          road[it1.first].pop_back();
        }
        dist1[it1.first] = (it->first) + it1.second;
        dadoamne.insert({dist1[it1.first], it1.first});
        road[it1.first].push_back(it->second);
      }
    }
    dadoamne.erase(it);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> L >> s >> t;
  for (long long i = 0; i < n; i++) dist[i] = inf;
  dist[s] = 0;
  for (long long i = 1; i <= m; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (z == 0) {
      nod[x].push_back({y, inf});
      nod[y].push_back({x, inf});
      tab[x][y] = 1;
      tab[y][x] = 1;
    } else {
      nod[x].push_back({y, z});
      nod[y].push_back({x, z});
    }
  }
  djkstra(s);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < nod[i].size(); j++) {
      if (nod[i][j].second == inf) nod[i][j].second = 1;
    }
  }
  if (dist[t] < L) return cout << "NO", 0;
  for (long long i = 0; i < n; i++) dist1[i] = inf;
  dist1[s] = 0;
  djkstra2(s);
  if (dist1[t] > L) return cout << "NO", 0;
  long long curr = t;
  while (curr != s) {
    long long y = road[curr][0];
    if (tab[curr][y] == 1) {
      tab1[curr][y] = 1;
      tab1[y][curr] = 1;
    }
    curr = y;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < nod[i].size(); j++) {
      if (tab[i][nod[i][j].first] == 1 && tab1[i][nod[i][j].first] == 0)
        nod[i][j].second = inf;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < nod[i].size(); i++) {
      if (dist1[t] == L) break;
      if (tab[i][nod[i][j].first] == 1 && tab1[i][nod[i][j].first] == 1) {
        nod[i][j].second += (L - dist1[t]);
        for (long long r = 0; r < nod[nod[i][j].first].size(); r++) {
          if (nod[nod[i][j].first][r].first == i)
            nod[nod[i][j].first][r].second += (L - dist1[t]);
        }
        djkstra2(s);
      }
    }
    if (dist1[t] == L) break;
  }
  cout << "YES" << '\n';
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < nod[i].size(); j++) {
      if (pop[i][nod[i][j].first] == 0)
        cout << i << ' ' << nod[i][j].first << ' ' << nod[i][j].second << '\n';
      pop[i][nod[i][j].first] = 1;
      pop[nod[i][j].first][i] = 1;
    }
  }
}
