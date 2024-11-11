#include <bits/stdc++.h>
using namespace std;
int in() {
  int a;
  scanf("%d", &a);
  return a;
}
double din() {
  double a;
  scanf("%lf", &a);
  return a;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
const double eps = 1e-8;
const double pi = 3.14159265358979323;
const int INF = 999999999;
int myfn(int a) {
  int r = 0;
  for (int i = 1; i < a; ++i) {
    r += i;
  }
  return r;
}
void dfs(vector<vector<int> > &graph, vector<int> &comp, vector<int> &used,
         int v) {
  used[v] = 1;
  comp.push_back(v);
  for (int i = 0; i < graph[v].size(); ++i) {
    if (graph[v][i] && !used[i]) {
      dfs(graph, comp, used, i);
    }
  }
}
void dfs(vector<vector<int> > &g, vector<vector<int> > &f, int v,
         vector<int> &u, int c) {
  for (int i = 0; i < g.size(); ++i) {
    if (g[v][i] && !u[i]) {
      dfs(g, f, i, u, c + g[v][i]);
      f[v][i] = min(g[v][i], u[i]);
      f[i][v] = -f[v][i];
    }
  }
}
int main() {
  int n = in();
  vector<vector<int> > ex(3, vector<int>());
  ex[0].push_back(1);
  ex[0].push_back(2);
  ex[1].push_back(1);
  ex[1].push_back(3);
  ex[2].push_back(2);
  ex[2].push_back(3);
  int lastHobbit = 3;
  for (int hobbits = 6; hobbits <= n; hobbits += ex.size()) {
    ex.push_back(vector<int>());
    for (int i = 0; i < ex.size() - 1; i++) {
      ex[i].push_back(lastHobbit + i + 1);
      ex[ex.size() - 1].push_back(lastHobbit + i + 1);
    }
    lastHobbit = hobbits;
  }
  printf("%d\n", ex.size());
  for (int i = 0; i < ex.size(); i++) {
    for (int j = 0; j < ex[0].size(); j++) {
      printf("%d ", ex[i][j]);
    }
    printf("\n");
  }
  return 0;
}
