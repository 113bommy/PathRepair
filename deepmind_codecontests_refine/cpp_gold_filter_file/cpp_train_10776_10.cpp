#include <bits/stdc++.h>
using namespace std;
int N, M;
int G[501][501];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> M;
  for (i = 0; i < (M); i++) {
    cin >> x >> y;
    G[x - 1][y - 1] = G[y - 1][x - 1] = 1;
  }
  int a = -1, c = -1;
  for (y = 0; y < (N); y++)
    for (x = 0; x < (y); x++)
      if (G[x][y] == 0) a = x, c = y;
  if (a == -1) {
    cout << "Yes" << endl;
    cout << string(N, 'a') << endl;
    return;
  }
  string S = string(N, '-');
  S[a] = 'a';
  S[c] = 'c';
  for (i = 0; i < (N); i++)
    if (i != a && i != c) {
      if (G[i][a] == 0 && G[i][c] == 0) {
        cout << "No" << endl;
        return;
      }
      if (G[i][a] == 1 && G[i][c] == 0) S[i] = 'a';
      if (G[i][a] == 0 && G[i][c] == 1) S[i] = 'c';
      if (G[i][a] == 1 && G[i][c] == 1) S[i] = 'b';
    }
  for (y = 0; y < (N); y++)
    for (x = 0; x < (y); x++)
      if (G[x][y] ^ (abs(S[x] - S[y]) <= 1)) {
        cout << "No" << endl;
        return;
      }
  cout << "Yes" << endl;
  cout << S << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
