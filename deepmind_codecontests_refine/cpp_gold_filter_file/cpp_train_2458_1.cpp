#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 17;
int N;
vector<int> graph[maxn];
long double DFS(int u, int p) {
  long double ret = 0;
  for (int v : graph[u])
    if (v != p) ret += DFS(v, u) + 1.0;
  if (graph[u].size() <= 1) return ret;
  return ret / (graph[u].size() - (u != 1));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  cout << fixed << setprecision(17);
  cout << DFS(1, 1) << endl;
  return 0;
}
