#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[1001][1001];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  vector<int> stolv(m + 1);
  vector<int> stoln(m + 1);
  vector<int> strv(n + 1);
  vector<int> strn(n + 1);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[j][i] == 1 && stolv[i] == 0) {
        stolv[i] = j;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = n; j >= 1; j--) {
      if (a[j][i] == 1 && stoln[i] == 0) {
        stoln[i] = j;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      if (a[i][j] == 1 && strn[i] == 0) {
        strn[i] = j;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1 && strv[i] == 0) {
        strv[i] = j;
      }
    }
  }
  int count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        if (strv[i] < j && strv[i] != 0) count += 1;
        if (strn[i] > j && strn[i] != 0) count += 1;
        if (stolv[j] < i && stolv[j] != 0) count += 1;
        if (stoln[j] > i && stoln[j] != 0) count += 1;
      }
    }
  }
  cout << count;
  return 0;
}
