#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
vector<pair<int, int>> sur = {{1, 0},   {0, -1}, {0, 1},  {-1, 0},
                              {-1, -1}, {1, 1},  {1, -1}, {-1, 1}};
bool bounds(int i, int j, int n, int m) {
  return i >= 0 && i <= n && j >= 0 && j <= m;
}
vector<long long> a;
vector<vector<long long>> g;
vector<bool> visited;
int dfs(int c, int length, int origin) {
  visited[c] = true;
  for (auto x : g[c]) {
    if (visited[x]) {
      if (x == origin) {
        return length + 1;
      } else {
        return 0;
      }
    } else {
      return dfs(x, length + 1, origin);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t, n, r;
  cin >> n;
  a = vector<long long>(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[a[a[i]]] == i) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
