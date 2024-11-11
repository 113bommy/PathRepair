#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  int flag;
} no[1000000 / 2 + 5];
int main() {
  for (int i = 1; i <= 1000000 / 2; i++) {
    no[i].x = i;
    no[i].y = 1000000 + 1 - i;
    no[i].flag = 0;
  }
  int n, x, cnt = 0;
  scanf("%d", &n);
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x > 1000000 / 2) {
      x = (1000000 + 1 - x);
      no[x].flag += 2;
    } else
      no[x].flag += 1;
  }
  for (int i = 1; i <= 1000000 / 2; i++) {
    if (no[i].flag == 3)
      cnt++;
    else if (no[i].flag == 1)
      printf("%d ", no[i].y);
    else if (no[i].flag == 2)
      printf("%d ", no[i].x);
  }
  for (int i = 1; i <= 1000000 / 2 && cnt; i++) {
    if (no[i].flag == 0) {
      printf("%d %d ", no[i].x, no[i].y);
      cnt--;
    }
  }
  return 0;
}
