#include <bits/stdc++.h>
using namespace std;
int used[600][600], x, y, r, c;
char com[1000000];
int main() {
  scanf("%d %d %d %d", &x, &y, &r, &c);
  scanf("%s", com);
  int uz = strlen(com);
  int con = x * y;
  for (int i = 0; i < uz; i++) {
    if (!used[r][c]) {
      used[r][c] = 1;
      con--;
      printf("1 ");
    } else
      printf("0 ");
    if (com[i] == 'U') r = max(1, r - 1);
    if (com[i] == 'R') c = min(y, c + 1);
    if (com[i] == 'D') r = min(x, r + 1);
    if (com[i] == 'L') c = max(1, c - 1);
  }
  printf("%d\n", con);
  return 0;
}
