#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const double PI = 3.141592653589793;
int a, b, n, m, k, i, j;
char t[20];
string s, tab[50][50];
int main() {
  ifstream ifile("input.txt");
  if (ifile) freopen("input.txt", "rt", stdin);
  if (ifile) freopen("output.txt", "wt", stdout);
  scanf("%d %d %d", &n, &m, &k);
  while (k--) {
    scanf("%s", &t);
    if (t[0] == '+') {
      scanf("%d %d %s", &a, &b, &t);
      s = t;
      for (i = a; i <= n; i++)
        for (j = (i == a ? b : 1); j <= m; j++)
          if (tab[i][j] == "") {
            tab[i][j] = s;
            i = a + 1;
            j = b + 1;
          }
    } else {
      scanf("%s", &t);
      s = t;
      for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
          if (tab[i][j] == s) {
            printf("%d %d\n", i, j);
            tab[i][j] = "";
            i = a + 3;
            j = b + 3;
          }
      if (i < a + 3) printf("-1 -1\n");
    }
  }
  return 0;
}
