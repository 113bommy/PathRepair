#include <bits/stdc++.h>
using namespace std;
int fixed_row[500005], fixed_col[500005];
int left_on[] = {1, 1, -1, -1};
int top_on[] = {1, -1, -1, 1};
char line[500005];
int main() {
  int n, m;
  scanf("%d %d ", &n, &m);
  int rows = n, cols = m;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    gets(line);
    for (int j = 0; j < m; j++) {
      if (line[j] == '.') continue;
      int type = line[j] - '1';
      int left = left_on[type];
      if (j % 2 == 1) left *= -1;
      int top = top_on[type];
      if (i % 2 == 1) top *= -1;
      if (fixed_row[i] == 0) {
        rows--;
        fixed_row[i] = left;
      } else if (fixed_row[i] != left)
        ok = false;
      if (fixed_col[j] == 0) {
        cols--;
        fixed_col[j] = top;
      } else if (fixed_col[j] != top)
        ok = false;
    }
  }
  if (!ok)
    printf("0\n");
  else {
    int x = 1;
    for (int i = 0; i < rows + cols; i++) x = (x * 2) % 1000003;
    printf("%d\n", x);
  }
  return 0;
}
