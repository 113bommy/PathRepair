#include <bits/stdc++.h>
using namespace std;
int N, sol;
int G[100100], CG[100100];
set<int> S;
vector<int> V;
int main() {
  cin >> N;
  G[0] = G[1] = G[2] = 0;
  CG[0] = CG[1] = CG[2] = 0;
  for (int I = 3; I <= N; I++) {
    S.clear();
    int M = 2 * I;
    for (int d = 2; d * d < M; d++)
      if (M % d == 0) {
        int a2 = M / d - d - 1;
        if (a2 % 2) continue;
        int a = a2 / 2;
        S.insert(CG[a + d] ^ CG[a]);
      }
    V = vector<int>(S.begin(), S.end());
    if (int((V).size()) == 0 || V[0] != 0) {
      G[I] = 0;
    } else {
      G[I] = V[int((V).size()) - 1] + 1;
      for (int K = 0; K < int((V).size()) - 1; K++)
        if (V[K + 1] > V[K] + 1) {
          G[I] = V[K] + 1;
          break;
        }
    }
    CG[I] = CG[I - 1] ^ G[I];
  }
  if (G[N] == 0)
    cout << -1 << endl;
  else {
    int M = 2 * N;
    for (int d = 2; d * d < M; d++)
      if (M % d == 0) {
        int a2 = M / d - d - 1;
        if (a2 % 2) continue;
        int a = a2 / 2;
        if (CG[a + d] ^ CG[a] == 0) {
          sol = d;
          break;
        }
      }
    cout << sol << endl;
  }
}
