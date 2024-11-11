#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
vector<vector<int>> selfloops;
vector<vector<pair<int, int>>> adjlist;
vector<vector<int>> otherIdx;
vector<int> cycle, validIdx;
void swapEdges(int n, int a, int b) {
  int neighA = adjlist[n][a].first, neighB = adjlist[n][b].first;
  int idxNeighA = otherIdx[n][a], idxNeighB = otherIdx[n][b];
  swap(adjlist[n][a], adjlist[n][b]);
  swap(otherIdx[n][a], otherIdx[n][b]);
  otherIdx[neighA][idxNeighA] = b;
  otherIdx[neighB][idxNeighB] = a;
}
void removeEdge(int n, int i) {
  int other = adjlist[n][i].first;
  validIdx[n]++;
  int otherIndex = otherIdx[n][i];
  if (otherIndex != validIdx[other]) {
    swapEdges(other, otherIndex, validIdx[other]);
  }
  validIdx[other]++;
}
void addEdge(int a, int b, int id) {
  otherIdx[a].push_back((ll)(adjlist[b]).size() + (a == b));
  otherIdx[b].push_back((ll)(adjlist[a]).size());
  adjlist[a].push_back({b, id});
  adjlist[b].push_back({a, -id});
}
void euler(int n) {
  while (validIdx[n] < (ll)(adjlist[n]).size()) {
    ll edge = adjlist[n][validIdx[n]].second;
    int nn = adjlist[n][validIdx[n]].first;
    removeEdge(n, validIdx[n]);
    euler(nn);
    cycle.push_back(edge);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> in(n);
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    in[i] = {a, b};
  }
  for (ll res = 1;; res--) {
    selfloops.assign(1ll << res, {});
    adjlist.assign(1ll << res, {});
    otherIdx.assign(1ll << res, {});
    validIdx.assign(1ll << res, 0);
    cycle.clear();
    ll mask = (1ll << res) - 1;
    for (ll i = 0; i < n; i++) {
      addEdge(in[i].first & mask, in[i].second & mask, i + 1);
    }
    bool ok = true;
    ll start = 0;
    for (ll i = 0; i < (1ll << res); i++) {
      ok &= ((ll)(adjlist[i]).size() % 2) == 0;
      if (!adjlist[i].empty()) start = i;
    }
    if (ok) euler(start);
    if ((ll)(cycle).size() == n) {
      reverse(begin(cycle), end(cycle));
      cout << res << endl;
      for (ll x : cycle) {
        ll a = 2 * abs(x) - 1;
        ll b = 2 * abs(x);
        ll c = in[abs(x) - 1].first;
        ll d = in[abs(x) - 1].second;
        if (x < 0) swap(a, b);
        if (x < 0) swap(c, d);
        cout << a << " " << b << " ";
      }
      cout << endl;
      return 0;
    }
  }
}
