#include <bits/stdc++.h>
using namespace std;
int N, K;
const int MOD = 1000000007;
int Fact[1000005];
int DP2[(1 << 17) + 5], Nb2[(1 << 17) + 5], Number[155];
;
vector<pair<int, int> > G[100005];
vector<int> V, V2, V3;
vector<int> Aux, Aux2;
bool Use[100005], Use2[100005];
int cnt1 = 0, cnt2 = 0;
int DP[155][155], TT[155];
map<int, int> M, M2;
int Matrix[155][155], X[155][155];
int D[155][155][2], Sz[155], Tmp[155][2];
bool u[155];
struct Edge {
  int x, y, w;
} E[55], E2[55];
void Read() {
  cin >> N >> K;
  for (int i = 1; i <= K; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    --w;
    E[i].x = x;
    E[i].y = y;
    E[i].w = w;
    if (Use[x] == 0) {
      V.push_back(x);
      ++cnt1;
      M[x] = cnt1;
      Use[x] = 1;
    }
    if (Use2[y] == 0) {
      V2.push_back(y);
      ++cnt2;
      M2[y] = cnt2;
      Use2[y] = 1;
    }
  }
  for (int i = 1; i <= cnt1 + cnt2; i++)
    for (int j = 1; j <= cnt1 + cnt2; j++) Matrix[i][j] = -2;
  for (int i = 1; i <= K; i++) {
    int x = E[i].x, y = E[i].y, w = E[i].w;
    x = M[x];
    y = M2[y] + cnt1;
    G[x].push_back(make_pair(y, w));
    G[y].push_back(make_pair(x, w));
    Matrix[x][y] = Matrix[y][x] = w;
  }
  for (int i = 1; i <= cnt1 + cnt2; i++) Use[i] = 0;
}
void DFS(int node) {
  Use[node] = 1;
  V3.push_back(node);
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i].first, w = G[node][i].second;
    if (Use[neighb] == 0) {
      DFS(neighb);
    }
  }
}
inline void Add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void Solvemethod1(int pos) {
  Aux.clear();
  Aux2.clear();
  int nb1 = 0, nb2 = 0;
  int s = V3.size(), t = 0;
  for (int i = 0; i < V3.size(); i++) {
    t += G[V3[i]].size();
    if (V3[i] > cnt1)
      nb2++;
    else
      nb1++;
  }
  t /= 2;
  if (nb2 < nb1) {
    for (int i = 0; i < V3.size(); i++) {
      if (V3[i] > cnt1) {
        Aux.push_back(V3[i]);
      } else
        Aux2.push_back(V3[i]);
    }
  }
  if (nb2 >= nb1) {
    for (int i = 0; i < V3.size(); i++) {
      if (V3[i] <= cnt1) {
        Aux.push_back(V3[i]);
      } else
        Aux2.push_back(V3[i]);
    }
  }
  int s2 = Aux.size();
  for (int i = 0; i < (1 << s2); i++) DP2[i] = 0, Nb2[i] = 0;
  DP2[0] = 1;
  Nb2[0] = 1;
  for (int i = 0; i <= s2; i++) Number[i] = 0;
  for (int i = 0; i < Aux2.size(); i++) {
    for (int conf = (1 << s2) - 1; conf >= 0; conf--) {
      for (int j = 0; j < s2; j++) {
        if ((conf & (1 << j)) != 0) continue;
        if (DP2[conf] == -1 || Matrix[Aux2[i]][Aux[j]] == -2) continue;
        Add(DP2[conf + (1 << j)],
            (1LL * DP2[conf] * Matrix[Aux2[i]][Aux[j]]) % MOD);
      }
    }
  }
  for (int conf = 0; conf < (1 << s2); conf++) {
    int cnt = 0;
    for (int j = 0; j < s2; j++) {
      if ((conf & (1 << j)) != 0) cnt++;
    }
    Add(Number[cnt], DP2[conf]);
  }
  for (int i = 0; i <= s2; i++) {
    for (int j = i; j <= K; j++) {
      Add(DP[pos][j], (1LL * DP[pos - 1][j - i] * Number[i]) % MOD);
    }
  }
}
int Father(int x) {
  int init = x;
  while (TT[x] != x) x = TT[x];
  while (init != x) {
    int next = TT[init];
    TT[init] = x;
    init = next;
  }
  return x;
}
void DFS2(int node, int father) {
  Sz[node] = 1;
  int sum = 0, limit = V3.size();
  for (int j = 0; j <= limit; j++) D[node][j][0] = D[node][j][1] = 0;
  D[node][0][0] = 1;
  D[node][0][1] = 0;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i].first, w = G[node][i].second;
    if (neighb == father || X[node][neighb] == -2) continue;
    DFS2(neighb, node);
    Sz[node] += Sz[neighb];
    for (int j = Sz[node] / 2; j >= 0; j--) {
      Tmp[j][0] = D[node][j][0];
      Tmp[j][1] = D[node][j][1];
      D[node][j][0] = D[node][j][1] = 0;
    }
    for (int j = 0; j <= Sz[node] / 2; j++) {
      for (int k = 0; k + j <= Sz[node] / 2 && k <= Sz[neighb] / 2; k++) {
        int aux = D[neighb][k][0];
        Add(aux, D[neighb][k][1]);
        Add(D[node][j + k][0], (1LL * Tmp[j][0] * aux) % MOD);
        Add(D[node][j + k][1], (1LL * Tmp[j][1] * aux) % MOD);
        if (u[node] == 1 || u[neighb] == 1 || j + k + 1 > Sz[node] / 2)
          continue;
        Add(D[node][j + k + 1][1],
            (((1LL * Tmp[j][0] * D[neighb][k][0]) % MOD) * w) % MOD);
      }
    }
  }
}
void Solvemethod2(int pos) {
  int ind = 0;
  for (int i = 0; i < V3.size(); i++) {
    TT[V3[i]] = V3[i];
  }
  for (int i = 1; i <= cnt1 + cnt2; i++)
    for (int j = 1; j <= cnt1 + cnt2; j++) X[i][j] = Matrix[i][j];
  for (int i = 0; i < V3.size(); i++) {
    int node = V3[i];
    if (node > cnt1) continue;
    for (int j = 0; j < G[node].size(); j++) {
      int neighb = G[node][j].first, w = G[node][j].second;
      if (Father(neighb) == Father(node)) {
        E2[ind].x = node;
        E2[ind].y = neighb;
        E2[ind].w = w;
        X[node][neighb] = X[neighb][node] = -2;
        ind++;
      } else
        TT[Father(neighb)] = Father(node);
    }
  }
  int sz = (1 << ind);
  for (int conf = 0; conf < sz; conf++) {
    for (int i = 1; i <= cnt1 + cnt2; i++) u[i] = 0;
    int cnt = 0, val = 1;
    bool ok = 1;
    for (int j = 0; j < ind; j++) {
      if ((conf & (1 << j)) != 0) {
        ++cnt;
        if (u[E2[j].x] == 1 || u[E2[j].y] == 1) {
          ok = 0;
          break;
        }
        u[E2[j].x] = 1;
        u[E2[j].y] = 1;
        val = (1LL * val * E2[j].w) % MOD;
      }
    }
    if (ok == 0) continue;
    int root = V3[0];
    DFS2(root, 0);
    for (int i = 0; i <= Sz[root] / 2; i++) {
      int aux = D[root][i][0];
      Add(aux, D[root][i][1]);
      aux = (1LL * val * aux) % MOD;
      for (int j = i + cnt; j <= K; j++) {
        Add(DP[pos][j], (1LL * DP[pos - 1][j - cnt - i] * aux) % MOD);
      }
    }
  }
}
void Solve() {
  int nb = 0;
  DP[0][0] = 1;
  for (int i = 0; i < V.size(); i++) V[i] = M[V[i]];
  for (int i = 0; i < V2.size(); i++) V2[i] = M2[V2[i]] + cnt1;
  for (int i = 1; i <= cnt1 + cnt2; i++) Use[i] = 0;
  for (int i = 0; i < V.size(); i++) {
    if (Use[V[i]] == 0) {
      V3.clear();
      DFS(V[i]);
      int t = 0;
      for (int j = 0; j < V3.size(); j++) t += G[V3[j]].size();
      t /= 2;
      ++nb;
      int s = V3.size();
      if (s / 2 <= t - s)
        Solvemethod1(nb);
      else
        Solvemethod2(nb);
    }
  }
  Fact[0] = 1;
  for (int i = 1; i <= N; i++) Fact[i] = (1LL * Fact[i - 1] * i) % MOD;
  int ans = 0;
  for (int i = 0; i <= K; i++) {
    Add(ans, (1LL * DP[nb][i] * Fact[N - i]) % MOD);
  }
  cout << ans << "\n";
}
int main() {
  Read();
  Solve();
  return 0;
}
