#include <bits/stdc++.h>
using namespace std;
const long long lim = 200007;
long long sum = 0, A[lim], Vis[lim];
map<long long, map<long long, long long>> M;
vector<long long> Adj[lim];
long long dfs(long long k, long long parent) {
  long long c = 0;
  long long remaining = 0;
  Vis[k] = 1;
  sum += A[k];
  for (long long i = 0; i < Adj[k].size(); i++) {
    if (Vis[Adj[k][i]] == 0) {
      c++;
      remaining += dfs(Adj[k][i], k);
    }
  }
  if (c == 0) {
    M[parent][k] = A[k];
    M[k][parent] = -1 * A[k];
    return A[k];
  } else {
    M[parent][k] = remaining + A[k];
    M[k][parent] = -1 * remaining - A[k];
    return 1 * remaining + A[k];
  }
}
int main() {
  long long n, m, X[lim], Y[lim];
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> A[i];
  cin >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> X[i] >> Y[i];
    Adj[X[i]].push_back(Y[i]);
    Adj[Y[i]].push_back(X[i]);
  }
  for (long long i = 1; i <= n; i++) {
    if (Vis[i] == 0) {
      sum = 0;
      dfs(i, i);
      if (sum != 0) {
        cout << "Impossible";
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
  for (long long i = 1; i <= m; i++) {
    cout << M[X[i]][Y[i]] << endl;
  }
  return 0;
}
