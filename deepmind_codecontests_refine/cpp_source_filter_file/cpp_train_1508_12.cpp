#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[210], w[210], sol[210];
queue<int> cd;
int nrsol;
int C[210][210];
int F[210][210];
bool viz[210], viz2[210];
int ant[210];
int S, D;
int A[210];
bool BFS(int s) {
  int i;
  for (i = S; i <= D; ++i) viz[i] = false;
  viz[s] = true;
  cd.push(s);
  while (!cd.empty()) {
    s = cd.front();
    cd.pop();
    if (s != D)
      for (i = 0; i < v[s].size(); ++i)
        if (!viz[v[s][i]] && F[s][v[s][i]] < C[s][v[s][i]]) {
          ant[v[s][i]] = s;
          viz[v[s][i]] = true;
          cd.push(v[s][i]);
        }
  }
  return viz[D];
}
void DFS(int x) {
  viz2[x] = true;
  for (int i = 0; i < v[x].size(); ++i)
    if (!viz2[v[x][i]]) DFS(v[x][i]);
  sol[nrsol].push_back(x);
}
int main() {
  int i, j, k;
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> A[i];
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      int val = A[i] + A[j];
      bool prim = true;
      for (k = 2; k * k < val; ++k)
        if (val % k == 0) prim = false;
      if (prim && A[i] % 2 == 0) {
        v[i].push_back(j);
        v[j].push_back(i);
        C[i][j] = 1;
      }
    }
  S = 0;
  D = n + 1;
  for (i = 1; i <= n; ++i)
    if (A[i] % 2 == 0) {
      v[S].push_back(i);
      v[i].push_back(S);
      C[S][i] = 2;
    } else {
      v[D].push_back(i);
      v[i].push_back(D);
      C[i][D] = 2;
    }
  int flow = 0, newflow, s;
  while (BFS(S))
    for (i = 0; i < v[D].size(); ++i) {
      ant[D] = v[D][i];
      newflow = 2100000000;
      s = D;
      while (s != S) {
        newflow = min(newflow, C[ant[s]][s] - F[ant[s]][s]);
        s = ant[s];
      }
      s = D;
      while (s != S) {
        F[ant[s]][s] += newflow;
        F[s][ant[s]] -= newflow;
        s = ant[s];
      }
      flow += newflow;
    }
  if (flow != n)
    cout << "Impossible\n";
  else {
    for (i = 1; i <= n; ++i)
      for (j = 1; j <= n; ++j)
        if (F[i][j] == 1) {
          w[i].push_back(j);
          w[j].push_back(i);
        }
    for (i = 1; i <= n; ++i)
      if (!viz2[i]) {
        nrsol++;
        DFS(i);
      }
    cout << nrsol << "\n";
    for (i = 1; i <= nrsol; ++i) {
      cout << sol[i].size() << " ";
      for (j = 0; j < sol[i].size(); ++j) cout << sol[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}
