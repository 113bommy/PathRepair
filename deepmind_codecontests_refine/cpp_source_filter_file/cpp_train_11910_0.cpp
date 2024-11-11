#include <bits/stdc++.h>
using namespace std;
int main() {
  queue<pair<int, int> > S;
  int h, w, l, r, answer = 0, h1, w1;
  cin >> h >> w;
  vector<vector<char> > g(h);
  vector<vector<int> > used(h);
  vector<vector<int> > dist(h);
  for (int i = 0; i < h; ++i) {
    g[i].resize(w);
    used[i].resize(w, 0);
    dist[i].resize(w, 0);
  }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      cin >> g[i][j];
      if (g[i][j] == 'E') {
        l = i;
        r = j;
      }
      if (g[i][j] == 'S') {
        h1 = i;
        w1 = j;
      }
      if (g[i][j] == 'T') used[i][j] = 1;
    }
  S.push(make_pair(l, r));
  used[l][r] = 1;
  dist[l][r] = 0;
  while (!S.empty()) {
    pair<int, int> A = S.front();
    S.pop();
    int l = A.first, r = A.second;
    if (l + 1 < h && used[l + 1][r] == 0) {
      S.push(make_pair(l + 1, r));
      used[l + 1][r] = 1;
      dist[l + 1][r] = dist[l][r] + 1;
    }
    if (r + 1 < w && used[l][r + 1] == 0) {
      S.push(make_pair(l, r + 1));
      used[l][r + 1] = 1;
      dist[l][r + 1] = dist[l][r] + 1;
    }
    if (l - 1 >= 0 && used[l - 1][r] == 0) {
      S.push(make_pair(l - 1, r));
      used[l - 1][r] = 1;
      dist[l - 1][r] = dist[l][r] + 1;
    }
    if (r - 1 >= 0 && used[l][r - 1] == 0) {
      S.push(make_pair(l, r - 1));
      used[l][r - 1] = 1;
      dist[l][r - 1] = dist[l][r] + 1;
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (g[i][j] >= '1' && g[i][j] <= '9' && dist[i][j] <= dist[h1][w1])
        answer += g[i][j] - '0';
    }
  }
  cout << answer;
  return 0;
}
