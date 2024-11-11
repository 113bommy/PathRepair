#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
char s[maxn];
vector<int> e[maxn];
int main() {
  int n, m, i, j, k, len;
  bool flag;
  while (scanf("%s", s) != EOF) {
    k = 0;
    m = 0;
    len = strlen(s);
    flag = false;
    for (i = 1; i <= len; i++) e[i].clear();
    for (i = 0; i < len; i++) {
      if (s[i] == '0') {
        e[++k].push_back(i + 1);
        m = max(k, m);
      } else {
        if (k <= 0) {
          flag = true;
          break;
        }
        e[--k].push_back(i + 1);
      }
    }
    if (k < m || flag)
      printf("-1\n");
    else {
      printf("%d\n", k);
      for (i = 1; i <= k; i++) {
        printf("%d", e[i].size());
        for (j = 0; j < e[i].size(); j++) printf(" %d", e[i][j]);
        printf("\n");
      }
    }
  }
  return 0;
}
