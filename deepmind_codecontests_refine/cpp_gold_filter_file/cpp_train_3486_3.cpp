#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, cnt = 0;
  cin >> n >> m;
  char a[50][50];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      string t = "    ";
      t[0] = a[i][j];
      t[1] = a[i + 1][j];
      t[2] = a[i][j + 1];
      t[3] = a[i + 1][j + 1];
      sort(t.begin(), t.end());
      if (t == "acef") {
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}
