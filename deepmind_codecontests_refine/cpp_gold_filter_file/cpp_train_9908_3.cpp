#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long x, y, w;
  bool operator<(const Node &a) const { return w < a.w; }
} node[210000];
vector<long long> ve;
vector<long long> ans;
long long dist[1000][1000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> node[i].x >> node[i].y >> node[i].w;
  }
  sort(node + 1, node + 1 + m);
  for (int i = 1; i <= min(m, k); i++) {
    ve.push_back(node[i].x);
    ve.push_back(node[i].y);
  }
  sort(ve.begin(), ve.end());
  ve.erase(unique(ve.begin(), ve.end()), ve.end());
  for (int i = 0; i < ve.size(); i++) {
    for (int j = 0; j < ve.size(); j++) {
      dist[i][j] = 0x3fffffffffffffff;
    }
  }
  for (int i = 0; i < ve.size(); i++) {
    dist[i][i] = 0;
  }
  for (int i = 1; i <= min(m, k); i++) {
    int x = lower_bound(ve.begin(), ve.end(), node[i].x) - ve.begin();
    int y = lower_bound(ve.begin(), ve.end(), node[i].y) - ve.begin();
    dist[x][y] = dist[y][x] = min(dist[x][y], node[i].w);
  }
  for (int k = 0; k < ve.size(); k++) {
    for (int i = 0; i < ve.size(); i++) {
      for (int j = 0; j < ve.size(); j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int i = 0; i < ve.size(); i++) {
    for (int j = i + 1; j < ve.size(); j++) {
      ans.push_back(dist[i][j]);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans[k - 1] << endl;
  return 0;
}
