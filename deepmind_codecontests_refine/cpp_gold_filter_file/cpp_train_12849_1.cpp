#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
int main() {
  int m, n;
  cin >> m >> n;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int p1[m], p2[m], p3[m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'G') {
        p1[i] = j;
      }
      if (a[i][j] == 'S') {
        p2[i] = j;
      }
    }
    if (p1[i] > p2[i]) {
      ans = -1;
      break;
    }
    p3[i] = p2[i] - p1[i];
  }
  if (ans == 0) {
    sort(p3, p3 + m);
    int a = p3[0];
    ans = 0;
    for (int i = 0; i < m;) {
      ans++;
      while (i < m && p3[i] == a) {
        i++;
      }
      a = p3[i];
    }
  }
  cout << ans << endl;
}
