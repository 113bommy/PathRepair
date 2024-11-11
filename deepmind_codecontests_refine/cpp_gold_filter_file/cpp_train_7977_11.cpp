#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1008];
int visited[1008];
int degree[1008];
int children[1008];
int main() {
  int n, a;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> a;
    degree[a]++;
    graph[a].push_back(i);
  }
  for (int i = 0; i < 1008; i++) {
    visited[i] = 0;
    children[i] = 0;
  }
  queue<int> q;
  q.push(1);
  visited[1] = 1;
  while (!q.empty()) {
    int x = q.front();
    for (int i = 0; i < graph[x].size(); i++) {
      int now = graph[x][i];
      if (!visited[now]) {
        visited[now] = true;
        if (degree[now] == 0) {
          children[x]++;
        }
        q.push(now);
      }
    }
    if (children[x] < 3 && degree[x] != 0) {
      cout << "No" << endl;
      return 0;
    }
    q.pop();
  }
  cout << "Yes" << endl;
}
