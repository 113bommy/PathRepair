#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1ll << 60;
const long long mod = 1000000007;
const long double PI = acosl(-1);
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
vector<vector<long long>> power;
set<pair<long long, vector<long long>>> con;
long long n;
void tro() {
  long long i, j;
  map<vector<long long>, bool> vis;
  set<pair<long long, vector<long long>>> fila;
  long long sum = 0;
  vector<long long> aux(n);
  for (i = 0; i < n; i++) {
    sum += power[i][power[i].size() - 1];
    aux[i] = power[i].size() - 1;
  }
  fila.insert(make_pair(sum, aux));
  con.insert(make_pair(sum, aux));
  vis[aux] = 1;
  while (!fila.empty() and con.size() < 200000) {
    auto it = fila.end();
    it--;
    pair<long long, vector<long long>> at = *it;
    fila.erase(it);
    for (i = 0; i < n; i++) {
      if (at.second[i] == 0) continue;
      at.second[i]--;
      if (vis[at.second] == 1) {
        at.second[i]++;
        continue;
      }
      vis[at.second] = 1;
      at.first -= power[i][at.second[i] + 1];
      at.first += power[i][at.second[i]];
      con.insert(at);
      fila.insert(at);
      at.first += power[i][at.second[i] + 1];
      at.first -= power[i][at.second[i]];
      at.second[i]++;
    }
  }
}
void solve() {
  long long m, i, j, sum = 0;
  cin >> n;
  power.resize(n);
  for (i = 0; i < n; i++) {
    cin >> m;
    for (j = 0; j < m; j++) {
      long long x;
      cin >> x;
      power[i].push_back(x);
    }
  }
  set<vector<long long>> ban;
  cin >> m;
  for (i = 0; i < m; i++) {
    vector<long long> aux(n);
    for (j = 0; j < n; j++) {
      cin >> aux[j];
      aux[j]--;
    }
    ban.insert(aux);
  }
  tro();
  auto it = con.end();
  it--;
  while (true) {
    if (ban.count((*it).second)) {
      it--;
      continue;
    }
    for (i = 0; i < n; i++) {
      cout << (*it).second[i] + 1 << ' ';
    }
    cout << "\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
