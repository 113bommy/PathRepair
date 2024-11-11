#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  out << "[";
  for (auto k : v) out << k << ",";
  out << "]"
      << "\n";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, set<T> s) {
  out << "{";
  for (auto k : s) out << k << ",";
  out << "}"
      << "\n";
  return out;
}
template <class T, class U>
ostream& operator<<(ostream& out, pair<T, U> p) {
  out << "[ " << p.first << " , " << p.second << " ] ";
  return out;
}
template <class T, class U>
istream& operator>>(istream& in, pair<T, U>& p) {
  in >> p.first >> p.second;
  return in;
}
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void DFS(int i, int j, int c, vector<string>& in,
         vector<vector<vector<pair<int, int> > > >& adj,
         vector<vector<int> >& res) {
  if (res[i][j] != -1) return;
  if (in[i][j] == 'X') return;
  res[i][j] = c;
  for (auto p : adj[i][j]) DFS(p.first, p.second, 5 - c, in, adj, res);
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  vector<vector<int> > res(N, vector<int>(M, -1));
  vector<string> in(N);
  vector<vector<vector<pair<int, int> > > > adj(
      N, vector<vector<pair<int, int> > >(M));
  for (int i = 0; i < int(N); i++) {
    cin >> in[i];
  }
  bool ok = true;
  for (int i = 0; i < int(N); i++) {
    for (int j = 0; j < int(M); j++) {
      if (in[i][j] == 'X') {
        int v = 0;
        for (int k = 0; k < int(4); k++) {
          int i2 = i + dy[k];
          int j2 = j + dx[k];
          if (((j2 >= 0) and (j2 < M) and (i2 >= 0) and (i2 < N)) and
              in[i2][j2] == '.')
            v++;
        }
        if (v % 2 == 1) ok = false;
        bool dig = false;
        for (int k = 0; k < int(4); k++) {
          int i2 = i + dy[k], j2 = j + dx[k];
          int i3 = i + dy[(k + 1) % 4], j3 = j + dx[(k + 1) % 4];
          if (((j2 >= 0) and (j2 < M) and (i2 >= 0) and (i2 < N)) and
              ((j3 >= 0) and (j3 < M) and (i3 >= 0) and (i3 < N)) and
              in[i2][j2] == '.' and in[i3][j3] == '.') {
            dig = true;
            adj[i2][j2].push_back({i3, j3});
            adj[i3][j3].push_back({i2, j2});
          }
        }
        if (!dig) {
          for (int k = 0; k < int(2); k++) {
            int i2 = i + dy[k], j2 = j + dx[k];
            int i3 = i + dy[(k + 2) % 4], j3 = j + dx[(k + 2) % 4];
            if (((j2 >= 0) and (j2 < M) and (i2 >= 0) and (i2 < N)) and
                ((j3 >= 0) and (j3 < M) and (i3 >= 0) and (i3 < N)) and
                in[i2][j2] == '.' and in[i3][j3] == '.') {
              adj[i2][j2].push_back({i3, j3});
              adj[i3][j3].push_back({i2, j2});
            }
          }
        }
      }
    }
  }
  if (!ok) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < int(N); i++)
    for (int j = 0; j < int(M); j++) DFS(i, j, 1, in, adj, res);
  for (int i = 0; i < int(N); i++)
    for (int j = 0; j < int(M); j++)
      if (in[i][j] == 'X') {
        res[i][j] = 0;
        for (int k = 0; k < int(4); k++) {
          int i2 = i + dy[k], j2 = j + dx[k];
          if (((j2 >= 0) and (j2 < M) and (i2 >= 0) and (i2 < N)) and
              in[i2][j2] == '.')
            res[i][j] += res[i2][j2];
        }
      }
  cout << "YES" << '\n';
  for (int i = 0; i < int(N); i++) {
    for (int j = 0; j < int(M); j++) cout << res[i][j] << " ";
    cout << '\n';
  }
}
