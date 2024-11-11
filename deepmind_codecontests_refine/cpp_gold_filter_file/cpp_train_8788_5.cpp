#include <bits/stdc++.h>
using namespace std;
set<int> SZERO[17];
set<int> SONES[17];
long long arr[100010];
struct DisjointSet {
  vector<int> R, P;
  DisjointSet(int N) {
    R = vector<int>(N, 0);
    P = vector<int>(N, -1);
  }
  int find(int x) { return P[x] == -1 ? x : (P[x] = find(P[x])); }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (R[x] > R[y])
      P[y] = x;
    else
      P[x] = y;
    R[y] += R[x] == R[y];
    return true;
  }
};
int mat[510][510];
int main() {
  for (int i = 0; i < 510; ++i)
    for (int j = 0; j < 510; ++j) mat[i][j] = 1000000000;
  int N, M, K;
  cin >> N >> M >> K;
  int s = 0;
  vector<int> V(K);
  for (int i = 0; i < K; ++i) {
    cin >> V[i];
    V[i] += s;
    s = V[i];
  }
  DisjointSet DS(N);
  for (int i = 0; i < M; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    if (c == 0) DS.join(u, v);
    int gu = upper_bound(V.begin(), V.end(), u) - V.begin();
    int gv = upper_bound(V.begin(), V.end(), v) - V.begin();
    mat[gv][gu] = mat[gu][gv] = min(mat[gu][gv], c);
  }
  int found = 0;
  for (int i = 0; i < K && !found; ++i) {
    int f = i == 0 ? 0 : V[i - 1];
    int s = V[i] - 1;
    for (int j = f; j < s && !found; ++j)
      found = found || (DS.find(j) != DS.find(j + 1));
  }
  if (found) {
    cout << "No" << endl;
  } else {
    for (int k = 0; k < K; ++k)
      for (int i = 0; i < K; ++i)
        for (int j = 0; j < K; ++j)
          if (i != j) mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
    cout << "Yes" << endl;
    for (int i = 0; i < K; ++i) {
      mat[i][i] = 0;
      for (int j = 0; j < K; ++j) {
        if (mat[i][j] == 1000000000)
          cout << -1 << " ";
        else
          cout << mat[i][j] << " ";
      }
      cout << endl;
    }
  }
}
