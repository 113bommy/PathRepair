#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > Graph(200);
int N = 0, visited[200];
map<int, pair<long long int, long long int> > M;
void dfs(int idx) {
  visited[idx] = 1;
  int i, n = Graph[idx].size();
  for (i = 0; i < n; i++)
    if (visited[Graph[idx][i]] == 0) dfs(Graph[idx][i]);
  return;
}
int main() {
  long long int i, j, k, n, m, a, b;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> m >> a >> b;
    if (m == 1) {
      N++;
      M[N] = make_pair(a, b);
      for (j = 1; j < N; j++) {
        if ((M[j].first > a && M[j].first < b) ||
            (M[j].second > a && M[j].second < b))
          Graph[N].push_back(j);
        if ((a > M[j].first && a < M[j].second) ||
            (b > M[j].first && b < M[j].second))
          Graph[j].push_back(N);
      }
    } else {
      memset(visited, 0, 200);
      dfs(a);
      if (visited[b] == 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
