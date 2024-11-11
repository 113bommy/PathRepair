#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    string arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long int row[n], col[m];
    for (int i = 0; i < n; i++) {
      row[i] = m;
    }
    for (int i = 0; i < m; i++) {
      col[i] = n;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == '*') {
          row[i]--;
          col[j]--;
        }
      }
    }
    int ans = 0, temp = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        temp = row[i] + col[j] - (arr[i][j] == '.');
        ans = min(ans, temp);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
