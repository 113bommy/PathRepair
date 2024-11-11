#include <bits/stdc++.h>
using namespace std;
long long fact(long long n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * fact(n - 1);
}
long long gcd(long long a, long long b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  if (a == 1 || b == 1)
    return 1;
  else if (a == 0)
    return b;
  else if (b == 0)
    return a;
  else {
    long long r = a > b ? a % b : b % a;
    if (r == 0)
      return min(a, b);
    else
      return gcd(min(a, b), r);
  }
}
void edgeU(vector<int> G[], int source, int dest) {
  G[source].push_back(dest);
  G[dest].push_back(source);
}
void edgeD(vector<int> G[], int source, int dest) { G[source].push_back(dest); }
bool BFS(vector<int> G[], int s, int v) {
  vector<bool> visited(v);
  vector<int> parent(v);
  vector<int> dist(v);
  for (int i = 0; i < v; i++) {
    visited[i] = false;
    dist[i] = INT_MAX;
    parent[i] = -1;
  }
  visited[s] = true;
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (q.empty() == false) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      if (visited[G[u][i]] == false) {
        visited[G[u][i]] = true;
        dist[G[u][i]] = dist[u] + 1;
        parent[G[u][i]] = u;
        q.push(G[u][i]);
      } else if (parent[u] != G[u][i] && parent[u] != -1)
        return true;
    }
  }
  return false;
}
void DFSvisit(vector<int> G[], int u, vector<bool> &visited) {
  visited[u] = true;
  for (int i = 0; i < G[u].size(); i++) {
    if (visited[G[u][i]] == false) DFSvisit(G, G[u][i], visited);
  }
}
void DFS(vector<int> G[], int s, int v) {
  vector<bool> visited(v, false);
  for (int i = 0; i < v; i++) {
    if (visited[i] == false) DFSvisit(G, i, visited);
  }
}
bool Comparator(int a, int b) { return (a >= b); }
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  char c[3] = {'R', 'G', 'B'};
  int cnt[3];
  cnt[0] = 0, cnt[1] = 0, cnt[2] = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == c[0])
      cnt[0]++;
    else if (s[i] == c[1])
      cnt[1]++;
    else
      cnt[2]++;
  }
  vector<char> ans;
  for (int i = 0; i <= 2; i++) {
    if (cnt[(i + 1) % 3] > 0 && cnt[(i + 2) % 3] > 0)
      ans.push_back(c[i]);
    else if (cnt[(i + 1) % 3] == 0 && cnt[(i + 2) % 3] == 0)
      ans.push_back(c[i]);
    else if (cnt[(i + 1) % 3] == 0) {
      if (cnt[i] >= 0 && cnt[(i + 2) % 3] != 1) ans.push_back(c[i]);
    } else if (cnt[(i + 2) % 3] == 0) {
      if (cnt[i] > 0 && cnt[(i + 1) % 3] != 1) ans.push_back(c[i]);
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i];
  return 0;
}
