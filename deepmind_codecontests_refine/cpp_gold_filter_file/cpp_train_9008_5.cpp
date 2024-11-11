#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> al[100005];
int sz[100005];
double starting_time[100005];
int p[100005];
void dfs(int node) {
  sz[node] = 1;
  for (int i = 0; i < al[node].size(); i++) {
    int child = al[node][i];
    dfs(child);
    sz[node] += sz[child];
  }
}
void dfs1(int node) {
  double val1 = 0;
  for (int i = 0; i < al[node].size(); i++) {
    val1 += sz[al[node][i]];
  }
  for (int i = 0; i < al[node].size(); i++) {
    starting_time[al[node][i]] = starting_time[p[al[node][i]]] + 1.0 +
                                 (double)(val1 - sz[al[node][i]]) / 2.0;
    dfs1(al[node][i]);
  }
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    al[p[i]].push_back(i);
  }
  starting_time[1] = 1.0;
  dfs(1);
  dfs1(1);
  for (int i = 1; i <= n; i++) printf("%.9lf ", starting_time[i]);
  return 0;
}
