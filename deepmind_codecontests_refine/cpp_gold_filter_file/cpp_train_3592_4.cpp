#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[1010];
int dist[1010][1010][4];
const int INF = 9999999;
vector<int> x, y;
int vis[1010][1010];
void handNeigh(int i, int j, int stat) {
  if ((i > 0 && !vis[i - 1][j]) && s[i - 1][j] != '#') {
    x.push_back(i - 1);
    y.push_back(j);
    dist[i - 1][j][stat] = dist[i][j][stat] + 1;
    vis[i - 1][j] = 1;
  }
  if ((j > 0 && !vis[i][j - 1]) && s[i][j - 1] != '#') {
    x.push_back(i);
    y.push_back(j - 1);
    dist[i][j - 1][stat] = dist[i][j][stat] + 1;
    vis[i][j - 1] = 1;
  }
  if ((i < n - 1 && !vis[i + 1][j]) && s[i + 1][j] != '#') {
    x.push_back(i + 1);
    y.push_back(j);
    dist[i + 1][j][stat] = dist[i][j][stat] + 1;
    vis[i + 1][j] = 1;
  }
  if ((j < m - 1 && !vis[i][j + 1]) && s[i][j + 1] != '#') {
    x.push_back(i);
    y.push_back(j + 1);
    dist[i][j + 1][stat] = dist[i][j][stat] + 1;
    vis[i][j + 1] = 1;
  }
}
void countDist() {
  for (int sta = 1; sta <= 3; sta++) {
    x.clear();
    y.clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        vis[i][j] = 0;
        dist[i][j][sta] = INF;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == sta + '0') {
          x.push_back(i);
          y.push_back(j);
          vis[i][j] = 1;
          dist[i][j][sta] = 0;
        }
      }
    }
    for (unsigned int ind = 0; ind < x.size(); ind++) {
      int i = x[ind];
      int j = y[ind];
      handNeigh(i, j, sta);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  countDist();
  int dist12 = INF;
  int dist13 = INF;
  int dist23 = INF;
  int parsa = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#') continue;
      if (s[i][j] == '.') {
        parsa = min(parsa, dist[i][j][1] + dist[i][j][2] + dist[i][j][3] - 2);
      } else if (s[i][j] == '1') {
        dist12 = min(dist12, dist[i][j][2] - 1);
      } else if (s[i][j] == '2') {
        dist23 = min(dist23, dist[i][j][3] - 1);
      } else {
        dist13 = min(dist13, dist[i][j][1] - 1);
      }
    }
  }
  parsa = min(parsa, dist12 + dist13);
  parsa = min(parsa, dist12 + dist23);
  parsa = min(parsa, dist23 + dist13);
  if (parsa > INF - 2)
    cout << -1 << "\n";
  else
    cout << parsa << "\n";
}
