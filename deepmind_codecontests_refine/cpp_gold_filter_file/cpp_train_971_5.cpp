#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> g[2][N];
deque<pair<int, int> > q;
long long int dis[2][N];
int main() {
  ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  memset(dis[0], 63, sizeof dis[0]);
  memset(dis[1], 63, sizeof dis[1]);
  int n, k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '-' && s[i + 1] == '-') {
      g[0][i + 1].push_back(i + 2);
      g[0][i + 2].push_back(i + 1);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (t[i] == '-' && t[i + 1] == '-') {
      g[1][i + 1].push_back(i + 2);
      g[1][i + 2].push_back(i + 1);
    }
  }
  q.push_back({0, 1});
  dis[0][1] = 0;
  while (q.size()) {
    int v = q.front().second;
    int e = q.front().first;
    q.pop_front();
    for (int i = 0; i < g[e][v].size(); i++) {
      if (g[e][v][i] > dis[e][v] + 1 && dis[e][v] + 1 < dis[e][g[e][v][i]]) {
        dis[e][g[e][v][i]] = dis[e][v] + 1;
        q.push_back({e, g[e][v][i]});
      }
    }
    if (e == 0) {
      if (v + k > t.size()) {
        cout << "YES";
        return 0;
      }
      if (t[v + k - 1] == '-' && dis[e][v] + 1 < dis[1 - e][v + k]) {
        dis[1 - e][v + k] = dis[e][v] + 1;
        q.push_back({1 - e, v + k});
      }
    } else {
      if (v + k > s.size()) {
        cout << "YES";
        return 0;
      }
      if (s[v + k - 1] == '-' && dis[e][v] + 1 < dis[1 - e][v + k]) {
        dis[1 - e][v + k] = dis[e][v] + 1;
        q.push_back({1 - e, v + k});
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = max(0, n - k + 1); j < N; j++) {
      if (dis[i][j] < 10000000) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}
