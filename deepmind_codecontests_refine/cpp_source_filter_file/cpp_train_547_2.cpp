#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
long long a[1001][1001];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> a[i][j];
        if ((i + j) & 1 && !(a[i][j]))
          ++a[i][j];
        else if (!(i + j) & 1 && a[i][j] & 1)
          ++a[i][j];
        cout << a[i][j] << ' ';
      }
      cout << endl;
    }
  }
}
