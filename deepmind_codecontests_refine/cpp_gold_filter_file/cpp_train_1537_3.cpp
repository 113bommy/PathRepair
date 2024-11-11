#include <bits/stdc++.h>
using namespace std;
bool a[2010][2010];
bool mark[2010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &c);
      a[i][j] = c % 2;
    }
  }
  bool flag = 1;
  int cnt;
  int k = 0;
  for (int i = 0; i < m; i++) {
    cnt = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i]) {
        cnt += a[j][i];
        k = j;
      }
    }
    if (!cnt) {
      flag = 0;
      break;
    } else if (cnt == 1) {
      mark[k] = 1;
    }
  }
  if (!flag) {
    puts("NO");
    return 0;
  }
  flag = 0;
  for (int i = 0; i < n; i++) {
    if (!mark[i]) {
      flag = 1;
      break;
    }
  }
  puts(flag ? "YES" : "NO");
  return 0;
}
