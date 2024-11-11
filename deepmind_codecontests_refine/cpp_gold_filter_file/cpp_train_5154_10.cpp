#include <bits/stdc++.h>
using namespace std;
vector<long> A[100005];
long B[100005], D[100005];
long pa[100005][100];
vector<long> C[100005], TT[100005][50], TR;
void dfs(long u, long p) {
  D[u] = D[p] + 1;
  pa[u][0] = p;
  TT[u][0] = C[u];
  for (int v : A[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}
vector<long> loc(vector<long> A1, vector<long> F) {
  vector<long> DA1 = TR;
  int j = 0;
  for (int i : A1) {
    while (j < F.size() && F[j] < i) {
      DA1.push_back(F[j]);
      ++j;
    }
    DA1.push_back(i);
  }
  while (j < F.size()) {
    DA1.push_back(F[j]);
    ++j;
  }
  while (DA1.size() > 10) DA1.pop_back();
  return DA1;
}
void LCA(long u, long v, long c) {
  vector<long> DA1 = TR;
  if (D[u] < D[v]) swap(u, v);
  long kt = D[u] - D[v];
  for (int i = 0; i <= 20; ++i)
    if ((kt >> i) & 1) {
      DA1 = loc(DA1, TT[u][i]);
      u = pa[u][i];
    }
  if (u == v) {
    DA1 = loc(DA1, TT[u][0]);
  } else {
    for (int i = 20; i >= 0; --i) {
      if (pa[u][i] != pa[v][i]) {
        DA1 = loc(DA1, TT[u][i]);
        DA1 = loc(DA1, TT[v][i]);
        u = pa[u][i];
        v = pa[v][i];
      }
    }
    DA1 = loc(DA1, TT[u][0]);
    DA1 = loc(DA1, TT[v][0]);
    DA1 = loc(DA1, TT[pa[u][0]][0]);
  }
  long zz = DA1.size();
  long k = min(c, zz);
  cout << k << " ";
  for (int i = 0; i <= k - 1; ++i) cout << DA1[i] << " ";
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long n, m, q, a, b, c;
  cin >> n >> m >> q;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> a >> b;
    A[a].push_back(b);
    A[b].push_back(a);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> B[i];
    C[B[i]].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    sort(C[i].begin(), C[i].end());
    while (C[i].size() > 10) C[i].pop_back();
  }
  dfs(1, 0);
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= n; ++j) {
      TT[j][i] = loc(TT[j][i - 1], TT[pa[j][i - 1]][i - 1]);
      pa[j][i] = pa[pa[j][i - 1]][i - 1];
    }
  }
  while (q > 0) {
    --q;
    cin >> a >> b >> c;
    LCA(a, b, c);
  }
  return 0;
}
