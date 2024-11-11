#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> p(n + 1);
  vector<int> d(n, 0);
  vector<int> ver;
  for (int i = n; i >= 1; i--) {
    cin >> p[i];
  }
  for (int k = 1; k <= n; k++) {
    int p1 = p[k];
    ver.push_back(p1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] > a[i][p1] + a[p1][j]) {
          a[i][j] = a[i][p1] + a[p1][j];
        }
      }
    }
    for (int i = 0; i < ver.size(); i++) {
      for (int j = 0; j < ver.size(); j++) {
        d[k - 1] += a[ver[i]][ver[j]];
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    cout << d[i] << " ";
  }
  return 0;
}
