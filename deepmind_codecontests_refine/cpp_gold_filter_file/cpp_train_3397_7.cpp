#include <bits/stdc++.h>
using namespace std;
const int maxn = 31;
const int maxm = 31;
int n, m, first, q, ans;
char c[maxn][maxm];
bool exist[27];
bool can_push[27];
bool anyS;
char ch;
int main() {
  scanf("%d%d%d\n", &n, &m, &first);
  for (int i = 0, _n = (n); i < _n; i++) {
    for (int j = 0, _n = (m); j < _n; j++) {
      scanf("%c", &c[i][j]);
    }
    scanf("\n");
  }
  for (int i = 0, _n = (n); i < _n; i++) {
    for (int j = 0, _n = (m); j < _n; j++) {
      if (c[i][j] == 'S') {
        anyS = 1;
        continue;
      }
      exist[c[i][j] - 'a'] = 1;
      for (int ii = 0, _n = (n); ii < _n; ii++) {
        for (int jj = 0, _n = (m); jj < _n; jj++) {
          if (c[ii][jj] == 'S') {
            if ((ii - i) * (ii - i) + (jj - j) * (jj - j) <= first * first)
              can_push[c[i][j] - 'a'] = 1;
          }
        }
      }
    }
  }
  scanf("%d\n", &q);
  for (int i = 0, _n = (q); i < _n; i++) {
    scanf("%c", &ch);
    if ((ch >= 'A' && ch <= 'Z' && !anyS) ||
        (ch >= 'a' && ch <= 'z' && !exist[ch - 'a']) ||
        (ch >= 'A' && ch <= 'Z' && !exist[ch - 'A'])) {
      printf("-1\n");
      return 0;
    }
    if (ch >= 'A' && ch <= 'Z') {
      ans += 1 - can_push[ch - 'A'];
    }
  }
  printf("%d\n", ans);
  return 0;
}
