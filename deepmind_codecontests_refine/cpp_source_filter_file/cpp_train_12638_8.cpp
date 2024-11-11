#include <bits/stdc++.h>
using namespace std;
const int N = 3001, M = 100;
int x[N], y[N];
int path[N][M];
int distance(int index1, int index2) {
  int xindex = x[index1] - x[index2];
  int yindex = y[index1] - y[index2];
  int xsq = xindex * xindex;
  int ysq = yindex * yindex;
  return xsq + ysq;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      path[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
  }
  vector<pair<int, pair<int, int> > > vec;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vec.push_back(make_pair(distance(i, j), make_pair(i, j)));
    }
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); ++i) {
    pair<int, int> par = vec[i].second;
    for (int t = 0; t < M; ++t) {
      if (path[par.first][t] & path[par.second][t]) {
        double answer = sqrt((double)(vec[i].first)) / 2;
        printf("%.8f", answer);
        break;
      }
      path[par.first][par.second / 32] |= (1 << (par.second % 32));
      path[par.second][par.first / 32] |= (1 << (par.first % 32));
    }
  }
  return 0;
}
