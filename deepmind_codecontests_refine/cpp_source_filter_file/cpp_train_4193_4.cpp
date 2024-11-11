#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    char ch[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> ch[i][j];
    }
    int c = 0;
    for (int i = 0; i < m - 1; i++) {
      if (ch[0][i] == 'D') c++;
    }
    for (int i = 0; i < n - 1; i++) {
      if (ch[i][m - 1] == 'R') c++;
    }
    printf("%d\n", c);
  }
  return 0;
}
