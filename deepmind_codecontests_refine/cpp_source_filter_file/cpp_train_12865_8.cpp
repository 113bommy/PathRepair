#include <bits/stdc++.h>
using namespace std;
int H, W;
vector<int> V[101010];
vector<int> R[101010];
int ma[101010];
int K;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> H >> W;
  for (y = 0; y < (H); y++) {
    V[y].resize(W);
    R[y].resize(W);
    for (x = 0; x < (W); x++) cin >> V[y][x];
  }
  for (y = H - 1; y >= 0; y--) {
    for (x = 0; x < (W); x++) {
      if (y == H - 1)
        R[y][x] = 1, ma[y] = 1;
      else {
        if (V[y][x] <= V[y + 1][x])
          R[y][x] = R[y + 1][x] + 1;
        else
          R[y][x] = 1;
        ma[y] = max(ma[y], R[y][x]);
      }
    }
  }
  cin >> K;
  while (K--) {
    cin >> x >> y;
    if (ma[x - 1] < y - x + 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
