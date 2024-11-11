#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> visited(m + 1, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++) {
      int y;
      cin >> y;
      visited[y] = 1;
    }
  }
  for (int i = 1; i <= m; i++)
    if (!visited[i]) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}
