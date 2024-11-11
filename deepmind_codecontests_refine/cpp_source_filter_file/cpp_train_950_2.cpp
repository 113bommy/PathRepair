#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
const int mod = 1000000007;
long long myPow(long long x, int p) {
  long long result = 1;
  while (true) {
    if (p & 1) {
      result = result * x % mod;
    }
    if (!p) break;
    p = p >> 1;
    x = x * x % mod;
  }
  return result;
}
vector<int> f(int n) {
  vector<int> result;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      int cnt = 0;
      visited[i] = true;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int t = q.front();
        q.pop();
        cnt++;
        for (int j = 0; j != graph[t].size(); j++) {
          if (!visited[graph[t][j]]) {
            visited[graph[t][j]] = true;
            q.push(graph[t][j]);
          }
        }
      }
      result.push_back(cnt);
    }
  }
  return result;
}
int main() {
  int n, k;
  cin >> n >> k;
  graph.resize(n);
  visited.resize(n);
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    if (x == 0) {
      graph[u - 1].push_back(v - 1);
      graph[v - 1].push_back(u - 1);
    }
  }
  vector<int> v = f(n);
  long long tmp = 0;
  for (int i = 0; i != v.size(); i++) {
    tmp = (tmp + myPow(v[i], k)) % mod;
  }
  long long result = myPow(n, k) - tmp;
  cout << result % mod << endl;
}
