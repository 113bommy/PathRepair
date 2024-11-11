#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    char a[n][m];
    int cnt = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < m; i++) {
      if (a[n - 1][i] == 'D') {
        cnt++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i][m - 1] == 'R') {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
