#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y;
};
string a[302];
int main() {
  int n, m, k;
  pt rec[6];
  char sch[305];
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", sch);
    a[i] = string(sch);
  }
  int maxR = min(n, m), s = 0;
  for (int x = 1; x <= maxR / 2 && s != k; x++)
    for (int i = 1; i <= n && s != k; i++)
      for (int j = 0; j < m && s != k; j++)
        if (a[i][j] == '*' && i - x >= 0 && a[i - x][j] == '*' && j + x < m &&
            a[i][j + x] == '*' && i + x <= n && a[i + x][j] == '*' &&
            j - x >= 0 && a[i][j - x] == '*') {
          s++;
          rec[1].x = i;
          rec[1].y = j + 1;
          rec[2].x = i - x;
          rec[2].y = j + 1;
          rec[5].x = i;
          rec[5].y = j + x + 1;
          rec[3].x = i + x;
          rec[3].y = j + 1;
          rec[4].x = i;
          rec[4].y = j - x + 1;
        }
  if (s == k)
    for (int i = 1; i <= 5; i++) printf("%d %d\n", rec[i].x, rec[i].y);
  else
    printf("-1");
  return 0;
}
