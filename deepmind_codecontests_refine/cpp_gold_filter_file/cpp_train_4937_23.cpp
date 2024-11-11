#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> parent;
vector<int> level;
vector<vector<int> > P;
void init_lca() {
  for (int i = 0; i < N; ++i) {
    P[i][0] = parent[i];
  }
  for (int k = 1; k <= 20; ++k) {
    for (int i = 0; i < N; ++i) {
      P[i][k] = P[P[i][k - 1]][k - 1];
    }
  }
}
int anc_level(int A, int l) {
  for (int k = 20; k >= 0; --k) {
    if (level[P[A][k]] >= l) A = P[A][k];
  }
  return A;
}
int anc_dist(int A, int dist) {
  for (int i = 0; i <= 20; i++) {
    if (((1 << i) & dist) != 0) {
      A = P[A][i];
    }
  }
  return A;
}
int lca(int A, int B) {
  if (level[A] < level[B]) swap(A, B);
  A = anc_level(A, level[B]);
  if (A == B) return A;
  for (int k = 20; k >= 0; --k) {
    if (P[A][k] != P[B][k]) {
      A = P[A][k];
      B = P[B][k];
    }
  }
  return P[A][0];
}
int main() {
  int Q, B, D1, D2, num = 3;
  P.resize(4, vector<int>(20 + 1));
  parent.resize(4);
  level.resize(4);
  D1 = 2;
  D2 = 1;
  scanf("%d", &Q);
  parent[0] = 0;
  level[0] = 1;
  parent[1] = 0;
  level[1] = 2;
  parent[2] = 0;
  level[2] = 2;
  parent[3] = 0;
  level[3] = 2;
  init_lca();
  int diametro = 2;
  while (Q--) {
    scanf("%d", &B);
    B--;
    num += 2;
    parent.push_back(B);
    parent.push_back(B);
    level.push_back(level[B] + 1);
    level.push_back(level[B] + 1);
    P.push_back(vector<int>(20 + 1));
    P.push_back(vector<int>(20 + 1));
    P[num][0] = parent[num];
    P[num - 1][0] = parent[num - 1];
    for (int k = 1; k <= 20; ++k) {
      P[num - 1][k] = P[P[num - 1][k - 1]][k - 1];
      P[num][k] = P[P[num][k - 1]][k - 1];
    }
    int G = lca(D1, num), G2 = lca(D2, num), Dist1, Dist2;
    if (G != D1) {
      Dist1 = level[D1] - level[G] + level[num] - level[G];
    } else
      Dist1 = level[num] - level[G];
    if (G2 != D2) {
      Dist2 = level[D2] - level[G2] + level[num] - level[G2];
    } else
      Dist2 = level[num] - level[G2];
    printf("%d\n", max(Dist1, max(diametro, Dist2)));
    if (Dist1 >= Dist2 && Dist1 > diametro) {
      diametro = Dist1;
      D2 = num;
    } else if (Dist1 <= Dist2 && Dist2 > diametro) {
      diametro = Dist2;
      D1 = num;
    }
  }
  return 0;
}
