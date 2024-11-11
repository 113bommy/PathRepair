#include <bits/stdc++.h>
using namespace std;
int G[110][110];
int INF = 1000 * 1000;
int n;
int MAX = 0;
int frloop(int i, void (*func)(int)) {
  func(i);
  return i == n ? 0 : frloop(i + 1, func);
}
int frloop(int i, int j, void (*func)(int, int)) {
  func(i, j);
  return j == n ? 0 : frloop(i, j + 1, func);
}
int frloop(int i, int j, int k, void (*func)(int, int, int)) {
  func(i, j, k);
  return k == n ? 0 : frloop(i, j, k + 1, func);
}
void assigninf(int i, int j) { G[i][j] = INF; }
void assignzero(int i) { G[i][i] = 0; }
void assigninffunc(int i) { frloop(i, 0, assigninf); }
void cinnum(int i, int j) { cin >> G[i][j]; }
void cinfunc(int i) { frloop(i, 0, cinnum); }
void maxl3(int k, int i, int j) {
  G[i][j] = (G[i][j] > G[i][k] + G[k][j]) ? (G[i][k] + G[k][j]) : G[i][j];
}
void maxl2(int i, int j) { frloop(i, j, 0, maxl3); }
void maxl1(int i) { frloop(i, 0, maxl2); }
void mxl2(int i, int j) { MAX = G[i][j] > MAX ? G[i][j] : MAX; }
void mxl1(int i) { frloop(i, 0, mxl2); }
int main() {
  cin >> n;
  n--;
  frloop(0, assigninffunc);
  frloop(0, assignzero);
  frloop(0, cinfunc);
  frloop(0, maxl1);
  frloop(0, mxl1);
  cout << MAX << endl;
}
