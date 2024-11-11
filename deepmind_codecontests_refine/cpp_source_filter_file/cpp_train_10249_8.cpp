#include <bits/stdc++.h>
using namespace std;
int N, S;
int C[111], n, m;
pair<int, int> E[111][111], A[111], B[111];
int sol, curr, pa, pb, ppa, ppb;
int solve(int I, int K) {
  memcpy(A, E[I], sizeof(E[I]));
  memcpy(B, E[K], sizeof(E[K]));
  n = C[I];
  m = C[K];
  int a = 1, b = 1;
  ppa = ppb = 0;
  pa = pb = curr = 0;
  while (a <= n && b <= m) {
    int lo = min(A[a].second, B[b].second);
    pa = pa + lo * A[a].first;
    pb = pb + lo * B[b].first;
    A[a].second -= lo;
    B[b].second -= lo;
    if (A[a].second == 0) a++;
    if (B[b].second == 0) b++;
    if ((ppa < ppb && pa >= pb) || (ppa > ppb && pa <= pb)) curr++;
    if (pa != pb) {
      ppa = pa;
      ppb = pb;
    }
  }
  return curr;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;
  for (int I = 1; I <= N; I++) {
    cin >> C[I];
    for (int K = 1; K <= C[I]; K++) cin >> E[I][K].first >> E[I][K].second;
  }
  for (int I = 1; I <= N; I++)
    for (int K = I + 1; K <= N; K++) sol += solve(I, K);
  cout << sol << endl;
}
