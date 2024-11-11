#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[10000] = {false};
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void dfs(int v) {
  visited[v] = true;
  for (int u : adj[v]) {
    if (!visited[u]) dfs(u);
  }
}
bool solve() {}
int main() {
  long long n, m;
  cin >> n >> m;
  pair<char, bool> a[n][m];
  for (long long i = 0; i < n; i++) {
    string local;
    cin >> local;
    for (long long j = 0; j < m; j++) {
      a[i][j].first = local[j];
      a[i][j].second = true;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      for (long long k = 0; k < n; k++) {
        if (a[i][j].first == a[i][k].first and i + j != i + k) {
          a[i][j].second = false, a[i][k].second = false;
        }
      }
      for (long long k = 0; k < m; k++) {
        if (a[i][j].first == a[k][j].first and i + j != j + k)
          a[i][j].second = false, a[k][j].second = false;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j].second) cout << a[i][j].first;
    }
  }
}
