#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int mn = 3000;
  int t[51][51];
  int ct[51][51] = {};
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> t[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ct[i][j] = ct[i - 1][j] + ct[i][j - 1] + t[i][j] - ct[i - 1][j - 1];
    }
  }
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= n; i++) {
    for (int j = b; j <= m; j++) {
      int sum = 0;
      sum = ct[i][j] - ct[i][j - b] - ct[i - a][j] + ct[i - a][j - b];
      if (sum < mn) mn = sum;
    }
  }
  for (int i = b; i <= n; i++) {
    for (int j = a; j <= m; j++) {
      int sum = 0;
      sum = ct[i][j] - ct[i][j - a] - ct[i - b][j] + ct[i - b][j - a];
      if (sum < mn) mn = sum;
    }
  }
  cout << mn << endl;
}
