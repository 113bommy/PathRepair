#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int A[500][500];
int D[500][500];
int Dist[310][310];
vector<pair<int, int> > B[250000];
int dist(int x1, int ewrgrg, int x2, int y2) {
  return abs(x1 - x2) + abs(ewrgrg - y2);
}
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(int argc, char* argv[]) {
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++) {
      cin >> A[i][j];
      B[A[i][j]].push_back(make_pair(i, j));
      D[i][j] = 1000000000;
      if (A[i][j] == 1) {
        D[i][j] = dist(0, 0, i, j);
      }
    }
  }
  for (int j = (1); j < (p); j++) {
    if (B[j].size() * B[j + 1].size() <= n * m) {
      for (int k = (0); k < (B[j].size()); k++) {
        int x = B[j][k].first;
        int y = B[j][k].second;
        int d = D[x][y];
        for (int i = (0); i < (B[j + 1].size()); i++) {
          int x1 = B[j + 1][i].first;
          int ewrgrg = B[j + 1][i].second;
          D[x1][ewrgrg] = min(D[x1][ewrgrg], d + dist(x, y, x1, ewrgrg));
        }
      }
    } else {
      deque<pair<int, int> > q;
      for (int i = (0); i < (n); i++) {
        for (int k = (0); k < (m); k++) {
          Dist[i][k] = 1000000000;
        }
      }
      vector<pair<int, pair<int, int> > > qq;
      for (int i = (0); i < (B[j].size()); i++) {
        int x = B[j][i].first;
        int y = B[j][i].second;
        qq.push_back(make_pair(D[x][y], make_pair(x, y)));
      }
      sort(qq.begin(), qq.end());
      int ind = 0;
      for (; ind < qq.size() && qq[ind].first == qq[0].first; ind++) {
        int x = qq[ind].second.first;
        int y = qq[ind].second.second;
        Dist[x][y] = qq[ind].first;
        q.push_back(make_pair(x, y));
      }
      while (!q.empty()) {
        pair<int, int> AA = q.front();
        q.pop_front();
        int x = AA.first;
        int y = AA.second;
        int d = Dist[x][y];
        for (; ind < qq.size() && qq[ind].first == d; ind++) {
          int xx = qq[ind].second.first;
          int yy = qq[ind].second.first;
          if (Dist[xx][yy] == 1000000000) {
            Dist[xx][yy] = d;
            q.push_front(make_pair(xx, yy));
          }
        }
        for (int i = (0); i < (4); i++) {
          int x1 = x + dir[i][0];
          int ewrgrg = y + dir[i][1];
          if (x1 >= 0 && ewrgrg >= 0 && x1 < n && ewrgrg < m &&
              Dist[x1][ewrgrg] == 1000000000) {
            Dist[x1][ewrgrg] = d + 1;
            q.push_back(make_pair(x1, ewrgrg));
          }
        }
      }
      for (int i = (0); i < (B[j + 1].size()); i++) {
        int x = B[j + 1][i].first;
        int y = B[j + 1][i].second;
        D[x][y] = Dist[x][y];
      }
    }
  }
  cout << D[B[p][0].first][B[p][0].second] << endl;
}
