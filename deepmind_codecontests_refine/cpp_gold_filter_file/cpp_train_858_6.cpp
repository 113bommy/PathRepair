#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int powmd(long long int a, long long int b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  long long int half = powmd(a, b / 2);
  long long int ans = half * half;
  ans %= 1000000007;
  if (b & 1) {
    ans *= a;
  }
  ans %= 1000000007;
  return ans;
}
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long int dfs(long long int curr_node, vector<long long int>& subtree_size,
                  vector<long long int>& visited,
                  vector<vector<long long int> >& gr) {
  visited[curr_node] = 1;
  subtree_size[curr_node] = 1;
  for (auto it : gr[curr_node]) {
    if (!visited[it]) {
      subtree_size[curr_node] += dfs(it, subtree_size, visited, gr);
    }
  }
  return subtree_size[curr_node];
}
void dfs2(long long int curr_node, vector<long long int>& dp,
          vector<long long int>& visited, vector<vector<long long int> >& gr,
          vector<long long int>& subtree_size) {
  visited[curr_node] = 1;
  dp[curr_node] = gr.size() - subtree_size[curr_node];
  for (auto it : gr[curr_node]) {
    if (!visited[it]) {
      dfs2(it, dp, visited, gr, subtree_size);
      dp[curr_node] = max(dp[curr_node], subtree_size[it]);
    }
  }
  return;
}
int32_t main() {
  fastIO();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<vector<long long int> > gr(n);
    long long int x, y;
    for (long long int i = 0; i < n - 1; i++) {
      cin >> x >> y;
      x--;
      y--;
      gr[x].push_back(y);
      gr[y].push_back(x);
    }
    vector<long long int> visited(n, 0);
    vector<long long int> subtree_size(n, 0);
    dfs(0, subtree_size, visited, gr);
    for (long long int i = 0; i < n; i++) {
      visited[i] = 0;
    }
    vector<long long int> dp(n);
    dfs2(0, dp, visited, gr, subtree_size);
    long long int min_value = 1e18;
    for (long long int i = 0; i < n; i++) {
      min_value = min(dp[i], min_value);
    }
    vector<long long int> vertex;
    for (long long int i = 0; i < n; i++) {
      if (dp[i] == min_value) vertex.push_back(i);
    }
    if (vertex.size() == 1) {
      cout << vertex[0] + 1 << " " << gr[vertex[0]][0] + 1 << endl;
      cout << vertex[0] + 1 << " " << gr[vertex[0]][0] + 1 << endl;
    } else {
      long long int first_vertex = vertex[0];
      long long int second_vertex = vertex[1];
      long long int third_vertex;
      for (auto it : gr[first_vertex]) {
        if (it != first_vertex and it != second_vertex) {
          third_vertex = it;
          break;
        }
      }
      cout << first_vertex + 1 << " " << third_vertex + 1 << endl;
      cout << second_vertex + 1 << " " << third_vertex + 1 << endl;
    }
  }
  return 0;
}
