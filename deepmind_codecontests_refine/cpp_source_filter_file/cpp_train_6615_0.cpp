#include <bits/stdc++.h>
using namespace std;
const int D = 1e6 + 3;
const int MAXN = 110;
int F[MAXN];
struct Mt {
  int v[MAXN][MAXN];
  int N, M;
  Mt() {
    for (int i = 0; i < MAXN; i++) {
      for (int j = 0; j < MAXN; j++) {
        v[i][j] = 0;
      }
    }
  }
  void I() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        v[i][j] = 0;
      }
      v[i][i] = 1;
    }
  }
  void pr() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << v[i][j];
      }
      cout << endl;
    }
  }
};
Mt operator*(Mt A, Mt B) {
  Mt Res;
  Res.N = A.N;
  Res.M = B.M;
  for (int k = 0; k < A.M; k++) {
    for (int i = 0; i < Res.N; i++) {
      for (int j = 0; j < Res.M; j++) {
        Res.v[i][j] += (1ll * A.v[i][k] * B.v[k][j]) % D;
        Res.v[i][j] %= D;
      }
    }
  }
  return Res;
}
Mt pw(Mt A, int p) {
  Mt Res;
  Res.N = A.N;
  Res.M = A.M;
  Res.I();
  while (p) {
    if (p & 1) {
      Res = Res * A;
    }
    A = A * A;
    p >>= 1;
  }
  return Res;
}
int main() {
  int C, W, H;
  cin >> C >> W >> H;
  F[0] = 1;
  for (int i = 1; i < W + 1; i++) {
    F[i] = H * F[i - 1];
    F[i] %= D;
  }
  Mt A;
  A.N = W + 1;
  A.M = W + 1;
  for (int i = 0; i < W; i++) {
    A.v[i][i + 1] = 1;
  }
  for (int i = 0; i < W + 1; i++) {
    A.v[W][i] = F[W - i];
  }
  Mt ans = pw(A, C);
  cout << ans.v[W][W] + ans.v[W][W - 1] << endl;
  return 0;
}
