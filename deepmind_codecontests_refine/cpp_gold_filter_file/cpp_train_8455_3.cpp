#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> x;
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      x.push_back(p);
    }
    vector<int> y = x;
    reverse(y.begin(), y.end());
    int L[n + 1][n + 1];
    int flag = 0, i, j;
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= n; j++) {
        if (i == 0 || j == 0)
          L[i][j] = 0;
        else if (x[i - 1] == y[j - 1])
          L[i][j] = L[i - 1][j - 1] + 1;
        else
          L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        if (L[i][j] >= 3) {
          flag = 1;
          break;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
