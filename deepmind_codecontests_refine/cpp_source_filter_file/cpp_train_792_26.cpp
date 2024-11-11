#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, tag[102][102];
  char a[102][102];
  memset(tag, 0, sizeof(tag));
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        if (a[i][k] == a[i][j]) tag[i][k] = 1, tag[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < m; k++) {
        if (a[k][i] == a[j][i]) tag[k][i] = 1, tag[j][i] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!tag[i][j]) printf("%c", a[i][j]);
    }
  }
  puts("");
  return 0;
}
