#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;
const double eqs = 1e-8;
char s[52][53], s1[52][53];
int a, b;
int qans = 0;
int main() {
  int i, n, m, n1, m1, j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%s", s + i);
  scanf("%d%d", &n1, &m1);
  for (i = 0; i < n1; i++) scanf("%s", s1 + i);
  for (int k = -50; k < 50; k++)
    for (int l = -50; l < 50; l++) {
      int tmp = 0;
      for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
          if (i + k >= 0 && i + k < n && j + l >= 0 && j + l < m)
            tmp += (s[i][j] - '0') * (s1[i + k][j + l] - '0');
      if (tmp > qans) {
        qans = tmp;
        a = k;
        b = l;
      }
    }
  printf("%d %d\n", a, b);
  return 0;
}
