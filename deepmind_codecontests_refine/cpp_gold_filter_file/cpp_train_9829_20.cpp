#include <bits/stdc++.h>
using namespace std;
int a[6];
int b[6];
void doit() {
  int n, m;
  cin >> n >> m;
  bool a[n][n];
  bool side = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if ((a[i][j]) && ((i == 0) || (i == n - 1) || (j == 0) || (j == m - 1))) {
        side = 1;
      }
    }
  }
  int best = 4;
  if (side) {
    best = 2;
  }
  cout << best << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    doit();
  }
}
