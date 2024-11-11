#include <bits/stdc++.h>
using namespace std;
const long long LIM = 1000000;
int n, m;
vector<vector<long long> > G, GCD, LCM;
vector<bool> vis;
vector<int> res;
vector<vector<int> > adj;
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long t = a % b;
    a = b;
    b = t;
  }
  return a;
}
long long lcm(long long a, long long b) {
  long long g = gcd(a, b);
  return g * (a / g) * (b / g);
}
bool dfs(int prev, int v) {
  long long nv = G[prev][v] / res[prev];
  long long pv = res[prev];
  if (nv < 1 || pv < 1 || nv > LIM || pv > LIM || nv * pv != G[prev][v] ||
      gcd(nv, pv) != GCD[prev][v] || lcm(nv, pv) != LCM[prev][v])
    return false;
  if (vis[v]) {
    if (nv != res[v]) return false;
    return true;
  }
  vis[v] = true;
  res[v] = nv;
  bool ok = true;
  for (int i = 0; i < adj[v].size(); i++) {
    int t = adj[v][i];
    if (!dfs(v, t)) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    vis[v] = false;
    res[v] = -1;
  }
  return ok;
}
int main() {
  istream &in = cin;
  in >> n >> m;
  G = vector<vector<long long> >(n, vector<long long>(n, -1));
  GCD = G;
  LCM = G;
  vis = vector<bool>(n, false);
  res = vector<int>(n, -1);
  adj = vector<vector<int> >(n);
  vector<int> deg(n, 0);
  for (int i = 0; i < m; i++) {
    int f, t, gcd, lcm;
    in >> f >> t >> gcd >> lcm;
    if (lcm % gcd != 0) {
      cout << "NO";
      return 0;
    }
    f--;
    t--;
    GCD[f][t] = GCD[t][f] = gcd;
    LCM[f][t] = LCM[t][f] = lcm;
    G[f][t] = G[t][f] = (long long)lcm * gcd;
    deg[f]++;
    deg[t]++;
    adj[t].push_back(f);
    adj[f].push_back(t);
  }
  for (int i = 0; i < n; i++)
    if (deg[i] > 0 && res[i] == -1) {
      long long max_mul = 0;
      for (int j = 0; j < adj[i].size(); j++)
        max_mul = max(max_mul, G[i][adj[i][j]]);
      set<long long> divs;
      bool ok = false;
      for (long long first = 1; first * first <= 1000000; first++) {
        bool divall = true;
        for (int j = 0; j < adj[i].size(); j++)
          if (G[i][adj[i][j]] % first != 0) {
            divall = false;
            break;
          }
        if (!divall) continue;
        divs.insert(first);
        for (int j = 0; j < adj[i].size(); j++)
          divs.insert(G[i][adj[i][j]] / first);
      }
      for (set<long long>::iterator it = divs.begin(); it != divs.end(); it++) {
        res[i] = *it;
        bool all_neib = true;
        for (int j = 0; j < adj[i].size(); j++) {
          vis = vector<bool>(n, false);
          vis[i] = true;
          if (!dfs(i, adj[i][j])) {
            all_neib = false;
            break;
          }
        }
        if (all_neib) {
          ok = true;
          break;
        }
      }
      if (!ok) {
        cout << "NO";
        return 0;
      }
    }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << (deg[i] == 0 ? 1 : res[i]) << " ";
  return 0;
}
