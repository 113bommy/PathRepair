#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int m;
  cin >> m;
  int adj[6][6] = {0};
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a][b] = adj[b][a] = 1;
  }
  for (int i = 1; i < 6; i++) {
    int d = 0;
    for (int j = 0; j < 6; j++) d += adj[i][j];
    if (d >= 3 || d == 1) return cout << "WIN", 0;
  }
  cout << "FAIL";
  return 0;
}
