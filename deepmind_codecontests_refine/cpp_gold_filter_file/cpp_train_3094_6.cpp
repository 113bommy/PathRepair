#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (min(a, b) > 1 || (a == 1 && b == 1 && (n == 2 || n == 3))) {
    cout << "NO" << endl;
  } else {
    int t = max(a, b);
    vector<vector<int>> re(n, vector<int>(n));
    for (int i = 0; i < n - t; ++i) {
      re[i + 1][i] = re[i][i + 1] = 1;
    }
    if (b > 1) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
          if (i != j) re[i][j] = !re[i][j];
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << re[i][j];
      cout << endl;
    }
  }
}
