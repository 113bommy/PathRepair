#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
bool visited[50][50];
bool isCyclic(long long i, long long j, string second[], long long pi,
              long long pj, char col, long long n, long long m) {
  visited[i][j] = true;
  bool hasCycle = false;
  if (i > 0 && second[i - 1][j] == col) {
    if (visited[i - 1][j]) {
      if (pi != (i - 1) || pj != j) {
        return true;
      }
    } else
      hasCycle = hasCycle || isCyclic(i - 1, j, second, i, j, col, n, m);
  }
  if ((i + 1) < n && second[i + 1][j] == col) {
    if (visited[i + 1][j]) {
      if (pi != (i + 1) || pj != j) {
        return true;
      }
    } else
      hasCycle = hasCycle || isCyclic(i + 1, j, second, i, j, col, n, m);
  }
  if (j > 0 && second[i][j - 1] == col) {
    if (visited[i][j - 1]) {
      if (pi != i || pj != (j - 1)) {
        return true;
      }
    } else
      hasCycle = hasCycle || isCyclic(i, j - 1, second, i, j, col, n, m);
  }
  if ((j + 1) < m && second[i][j + 1] == col) {
    if (visited[i][j + 1]) {
      if (pi != i || pj != (j + 1)) {
        return true;
      }
    } else
      hasCycle = hasCycle || isCyclic(i, j + 1, second, i, j, col, n, m);
  }
  return hasCycle;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  string second[n];
  for (long long i = 0; i < n; i++) cin >> second[i];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) visited[i][j] = false;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (!visited[i][j] &&
          isCyclic(i, j, second, -1, -1, second[i][j], n, m)) {
        cout << "YES";
        return;
      }
    }
  }
  cout << "NO";
}
int main() {
  fastIO();
  long long t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
