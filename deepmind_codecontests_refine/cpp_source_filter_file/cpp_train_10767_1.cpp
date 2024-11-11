#include <bits/stdc++.h>
using namespace std;
inline void SetIO(string Name) {
  string Input = Name + ".in", Output = Name + ".out";
  freopen(Input.c_str(), "r", stdin), freopen(Output.c_str(), "w", stdout);
}
const int N = 100010, M = 110, Mod = 1000000007;
int n, m, MaxDepth;
int Arr[M][N], C[N][M];
inline void Input() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) scanf("%d", &Arr[0][i]);
}
inline void Work(int Depth, int l, int r, int k) {
  int &Left = Arr[Depth + 1][l], &Right = Arr[Depth + 1][r + 1];
  if (!k) {
    if ((++Left) >= Mod) Left -= Mod;
    if ((--Right) < 0) Right += Mod;
  } else {
    if ((Right -= C[r - l + k][k]) < 0) Right += Mod;
    Work(Depth + 1, l, r, k - 1);
  }
}
inline void Search(int Depth) {
  if (Depth < MaxDepth + 1) Search(Depth + 1);
  if (!Depth) return;
  int Cnt = 0;
  for (int i = (1); i <= (n); i++) {
    if ((Cnt += Arr[Depth][i]) >= Mod) Cnt -= Mod;
    if ((Arr[Depth - 1][i] += Cnt) >= Mod) Arr[Depth - 1][i] -= Mod;
  }
}
inline void Solve() {
  for (int i = (0); i <= (n); i++) C[i][0] = 1;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (100); j++) {
      int &T = C[i][j];
      if ((T += C[i - 1][j - 1]) >= Mod) T -= Mod;
      if ((T += C[i - 1][j]) >= Mod) T -= Mod;
    }
  MaxDepth = 0;
  while (m--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    Work(0, l, r, k);
    if (MaxDepth < k) MaxDepth = k;
  }
  Search(0);
  for (int i = (1); i <= (n - 1); i++) printf("%d ", Arr[0][i]);
  printf("%d\n", Arr[0][n]);
}
int main() {
  Input();
  Solve();
  return 0;
}
