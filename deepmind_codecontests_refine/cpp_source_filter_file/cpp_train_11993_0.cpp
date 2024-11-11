#include <bits/stdc++.h>
using namespace std;
int root(int arr[], int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}
void Union(int arr[], int Size[], int a, int b) {
  int rootA = root(arr, a);
  int rootB = root(arr, b);
  if (Size[rootA] < Size[rootB]) {
    arr[rootA] = arr[rootB];
    Size[rootB] += Size[rootA];
  } else {
    arr[rootB] = arr[rootA];
    Size[rootA] += Size[rootB];
  }
}
bool findRoot(int a, int b, int arr[]) {
  if (root(arr, a) == root(arr, b))
    return true;
  else
    return false;
}
bool nCyc = false;
bool check(int i, int mask) { return (mask & (1 << i)) != 0; }
int setBit(int i, int mask) { return (mask | (1 << i)); }
bool isPrime(long long x) {
  if (x == 2) return true;
  if (x % 2 == 0 || x < 2) return false;
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0) return false;
  return true;
}
queue<pair<int, int> > q;
vector<pair<int, int> > nodes;
int dist[25][25], cost[25][25];
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
char adj[25][25];
void bfs(int i, int j) {
  pair<int, int> p;
  memset(dist, -1, sizeof dist);
  dist[i][j] = 0;
  q.push(make_pair(i, j));
  while (!q.empty()) {
    p = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int pos1 = p.first + dx[i], pos2 = p.second + dy[i];
      if (dist[pos1][pos2] == -1) {
        dist[pos1][pos2] = dist[p.first][p.second] + 1;
        q.push(make_pair(pos1, pos2));
      }
    }
  }
}
int main() {
  string s;
  cin >> s;
  int dp[s.length()];
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'm' || s[i] == 'w') {
      cout << 0;
      return 0;
    }
  }
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= s.length(); i++) {
    if ((s[i - 2] == 'n' && s[i - 1] == 'n') ||
        (s[i - 2] == 'u' || s[i - 1] == 'u'))
      dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
    else
      dp[i] = dp[i - 1];
  }
  cout << dp[s.length()];
  return 0;
}
