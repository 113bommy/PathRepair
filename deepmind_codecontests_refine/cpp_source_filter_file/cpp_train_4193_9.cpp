#include <bits/stdc++.h>
using namespace std;
const long long mod = 10e9 + 7;
const long long P = 200003;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    int sum = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (j == m) {
          if (a[i][j] == 'R') {
            c1++;
          }
        } else if (i == n) {
          if (a[i][j] == 'D') {
            c2++;
          }
        }
      }
    }
    cout << c1 + c2 << '\n';
  }
  return 0;
}
