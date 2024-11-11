#include <bits/stdc++.h>
using namespace std;
int N;
int willKill(char g[105][105], int i, int j) {
  int r = 0;
  for (int k = 0; k < N; k += 1)
    r +=
        (g[i][k] == '.' || g[i][k] == 'E') + (g[k][i] == '.' || g[k][i] == 'E');
  return r;
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false), cin.tie(0);
  char map[105][105];
  cin >> N;
  for (int i = 0; i < N; i += 1)
    for (int j = 0; j < N; j += 1) cin >> map[i][j];
  vector<pair<int, int> > vectMoves;
  for (int i = 0; i < N; i += 1) {
    for (int j = 0; j < N; j += 1) {
      if (map[i][j] == '.') {
        vectMoves.push_back(make_pair(i, j));
        break;
      }
    }
  }
  if ((int)vectMoves.size() == N) {
    for (typeof(vectMoves.begin()) it = vectMoves.begin();
         it != vectMoves.end(); ++it)
      cout << it->first + 1 << ' ' << it->second + 1 << '\n';
    return 0;
  }
  vectMoves.clear();
  for (int i = 0; i < N; i += 1) {
    for (int j = 0; j < N; j += 1) {
      if (map[j][i] == '.') {
        vectMoves.push_back(make_pair(j, i));
        break;
      }
    }
  }
  if ((int)vectMoves.size() == N) {
    for (typeof(vectMoves.begin()) it = vectMoves.begin();
         it != vectMoves.end(); ++it)
      cout << it->first + 1 << ' ' << it->second + 1 << '\n';
    return 0;
  }
  cout << -1 << '\n';
  return 0;
}
