#include <bits/stdc++.h>
using namespace std;
char s[200][200];
int mm[200][200], bb[200][200];
int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int lei[101][2], co = 0;
int n, m;
void dismm() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", mm[i][j]);
    }
    cout << endl;
  }
  return;
}
void disbb() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", bb[i][j]);
    }
    cout << endl;
  }
  return;
}
int main() {
  while (cin >> n >> m) {
    memset(mm, 0, sizeof(mm));
    memset(bb, 0, sizeof(bb));
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        char t;
        t = s[i][j];
        if (t == '*') {
          bb[i + 1][j + 1] = -1;
          mm[i + 1][j + 1] = -1;
          lei[co][0] = i + 1;
          lei[co][1] = j + 1;
          co++;
        } else if (t != '.') {
          bb[i + 1][j + 1] = t - '0';
        }
      }
    for (int i = 0; i < co; i++) {
      int a = lei[i][0], b = lei[i][1];
      for (int j = 0; j < 8; j++) {
        mm[a + x[j]][b + y[j]]++;
      }
    }
    for (int k = 0; k < co; k++) {
      int a = lei[k][0], b = lei[k][1];
      mm[a][b] = -1;
    }
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        if (bb[i][j] != mm[i][j]) {
          printf("NO\n");
          flag = 0;
          break;
        }
      if (flag == 0) break;
    }
    if (flag == 1) printf("YES\n");
  }
  return 0;
}
