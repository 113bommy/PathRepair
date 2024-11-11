#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > G;
vector<long long int> P;
vector<long long int> Pav;
vector<long long int> DP;
vector<long long int> DPe;
vector<long long int> sub;
long long int nC2(long long int k) { return (k * (k - 1)) / 2; }
long long int PairsProductSum(vector<long long int> &T) {
  long long int sum = 0;
  for (int i = (0); i <= ((int)(T).size() - 1); ++i) sum += T[i];
  long long int ans = sum * sum;
  for (int i = (0); i <= ((int)(T).size() - 1); ++i) ans -= T[i] * T[i];
  return (ans / 2);
}
int DFSv(int v, int par) {
  int n = (int)(G).size();
  for (int i = (0); i <= ((int)(G[v]).size() - 1); ++i)
    if (G[v][i] != par) sub[v] += DFSv(G[v][i], v);
  P[v] = nC2(sub[v]);
  vector<long long int> sonsP;
  for (int i = (0); i <= ((int)(G[v]).size() - 1); ++i)
    if (G[v][i] != par) {
      int u = G[v][i];
      Pav[v] += P[u];
      sonsP.push_back(P[u]);
      DPe[v] += Pav[u];
      DPe[v] += DPe[u];
      DPe[v] += P[u] * (sub[v] - sub[u] - 1);
    }
  for (int i = (0); i <= ((int)(G[v]).size() - 1); ++i)
    if (G[v][i] != par) {
      int u = G[v][i];
      long long int leaving_paths = sub[u] * (sub[v] - sub[u]);
      DP[v] += DP[u];
      DP[v] += (Pav[u] + DPe[u]) * (sub[v] - sub[u]);
      DP[v] += P[u] * (P[v] - Pav[v] - leaving_paths);
    }
  DP[v] += PairsProductSum(sonsP);
  return sub[v];
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  G.resize(n);
  P.resize(n, 0);
  Pav.resize(n, 0);
  DP.resize(n, 0);
  DPe.resize(n, 0);
  sub.resize(n, 1);
  for (int i = (1); i <= (n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  DFSv(0, -1);
  cout << 2 * DP[0];
  return 0;
}
