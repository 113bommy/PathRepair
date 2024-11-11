#include <bits/stdc++.h>
using namespace std;
bool flag = 0, flag1 = 0, flag2 = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    char a[n][m], x;
    for (long long int i = 0; i < n; i++)
      for (long long int j = 0; j < m; j++) cin >> x, a[i][j] = (x == '#');
    for (long long int i = 0; i < n - 1; i++)
      for (long long int j = i + 1; j < n; j++) {
        flag = 0;
        flag1 = 0;
        for (long long int k = 0; k < m; k++) {
          if (a[i][k] != a[j][k]) flag = 1;
          if (a[i][k] && a[j][k]) flag1 = 1;
        }
        if (flag && flag1) {
          cout << "No";
          return 0;
        }
      }
    cout << "Yes";
  }
  return 0;
}
