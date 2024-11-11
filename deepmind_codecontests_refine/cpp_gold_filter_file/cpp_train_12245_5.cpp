#include <bits/stdc++.h>
using namespace std;
vector<int> G[100005];
int color[100005];
long long sum;
void init() {
  for (int i = 0; i < 100005; i++) {
    G[i].clear();
    color[i] = -1;
  }
}
int ranse() {
  queue<int> q;
  q.push(1);
  color[1] = 2;
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (int i = 0; i < G[a].size(); i++) {
      if (color[G[a][i]] == color[a]) {
        return 1;
      } else {
        if (color[G[a][i]] == -1) {
          color[G[a][i]] = -color[a];
          q.push(G[a][i]);
        }
      }
    }
  }
  return 0;
}
int main() {
  int m;
  while (cin >> m) {
    sum = 0;
    init();
    for (int i = 0; i < m - 1; i++) {
      int s, t;
      cin >> s >> t;
      G[s].push_back(t);
      G[t].push_back(s);
    }
    if (ranse() == 0) {
      for (int i = 0; i < 100005; i++) {
        if (color[i] == 2) {
          sum++;
        }
      }
      long long num = sum * (m - sum);
      cout << num - (m - 1) << endl;
    }
  }
  return 0;
}
