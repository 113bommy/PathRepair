#include <bits/stdc++.h>
using namespace std;
struct WeightedEdge {
  int to, weight;
};
bool dfs(int start, vector<vector<WeightedEdge>> &adjList, vector<int> &color,
         int newColor) {
  color[start] = newColor;
  for (WeightedEdge e : adjList[start]) {
    if (color[e.to] == 2 &&
        !dfs(e.to, adjList, color, color[start] ^ e.weight)) {
      return false;
    } else if ((color[e.to] ^ color[start]) != e.weight) {
      return false;
    }
  }
  return true;
}
void addEdge(vector<vector<WeightedEdge>> &edges, int a, int b, int weight) {
  edges[a].push_back({b, weight});
  edges[b].push_back({a, weight});
}
int main() {
  string s;
  cin >> s;
  int m = s.length();
  vector<long long> twoPow(m + m, 1);
  for (unsigned i = 1; i < twoPow.size(); i++) {
    twoPow[i] = (twoPow[i - 1] * 2) % 998244353;
  }
  long long ans = 0L;
  for (int aLen = 1; aLen < m; aLen++) {
    vector<vector<WeightedEdge>> edges(m + aLen + 1, vector<WeightedEdge>());
    for (int i = 0; i < m / 2; i++) {
      addEdge(edges, i, m - i - 1, 0);
    }
    for (int i = 0; i < aLen / 2; i++) {
      addEdge(edges, i + m, m + aLen - i - 1, 0);
    }
    for (int i = 0; i < m - aLen; i++) {
      if (s[i] != '?') {
        addEdge(edges, i, m + aLen, s[i] - '0');
      }
    }
    for (int i = m - aLen; i < m; i++) {
      if (s[i] != '?') {
        addEdge(edges, i, i + aLen, s[i] - '0');
      }
    }
    edges[m].push_back({m + aLen, 1});
    edges[m + aLen].push_back({m, 1});
    vector<int> colors(m + aLen + 1, 2);
    int components = -1;
    for (int i = m + aLen; i >= 0; i--) {
      if (colors[i] == 2) {
        if (dfs(i, edges, colors, 0)) {
          components++;
        } else {
          goto impossible;
        }
      }
    }
    ans = (ans + twoPow[components]) % 998244353;
  impossible:;
  }
  cout << ans;
  return 0;
}
