#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
vector<int> P, was;
void dfs(int v, int from) {
  P[v] = from;
  was[v] = 1;
  for (int i = 0; i < graph[v].size(); i++) {
    if (was[graph[v][i]] == 0) {
      dfs(graph[v][i], v);
    }
  }
}
int main() {
  int city_number;
  cin >> city_number;
  graph.assign(city_number + 1, vector<int>());
  int capital, new_capital;
  cin >> capital;
  cin >> new_capital;
  for (int j = 1; j <= city_number; j++) {
    int k;
    if (j != capital) {
      cin >> k;
      graph[j].push_back(k);
      graph[k].push_back(j);
    }
  }
  was.assign(city_number + 1, 0);
  P.assign(city_number + 1, 0);
  dfs(new_capital, 0);
  for (int i = 1; i <= city_number; i++) {
    if (P[i] != 0) {
      cout << P[i] << " ";
    }
  }
  return 0;
}
