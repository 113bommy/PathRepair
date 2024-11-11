#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int> > G;
vector<pair<int, int> > E;
void input() {
  scanf("%d %d", &N, &M);
  G.resize(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
    E.push_back(make_pair(a, b));
  }
}
long long sumStepsCalc() {
  long long res = 0;
  for (int i = 0; i < N; i++) {
    long long q = G[i].size();
    res += (q * (q - 1)) / 2;
  }
  return res;
}
long long countThreeCycles() {
  long long res = 0;
  for (int i = 0; i < M; i++) {
    int u = E[i].first;
    int v = E[i].second;
    if (G[u].size() < G[v].size()) swap(u, v);
    for (int j = 0; j < G[v].size(); j++)
      if (binary_search(G[u].begin(), G[u].end(), G[v][j])) res++;
  }
  return res / 3;
}
void solve() {
  long long CN3 = ((1ll * N) * (1ll * (N - 1)) * (1ll * (N - 2))) / 6;
  long long slog = M * 1ll * (N - 2);
  long long sumSteps = sumStepsCalc();
  long long threeCycles = 0;
  cout << CN3 - (slog - sumSteps + threeCycles) << endl;
}
int main() {
  input();
  if (N <= 2) {
    cout << 0 << endl;
    return 0;
  }
  solve();
  return 0;
}
