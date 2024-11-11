#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  friend bool operator<(const node& n1, const node& n2);
};
bool operator<(const node& n1, const node& n2) {
  if (n1.y > n2.y)
    return true;
  else if (n1.y == n2.y && n1.x < n2.x)
    return true;
  else
    return false;
}
int n;
node pos[1000005];
int a[1000005];
int main() {
  int i, j, k;
  int x, y, z;
  scanf("%d", &n);
  x = 0;
  y = 0;
  pos[0].y = 0;
  pos[0].x = 0;
  a[0] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &z);
    for (j = x + 1; j <= x + z; j++) {
      pos[j].x = j;
      if (i % 2 == 1)
        pos[j].y = pos[j - 1].y + 1;
      else
        pos[j].y = pos[j - 1].y - 1;
      a[j] = pos[j].y;
    }
    x += z;
    if (i % 2 == 1)
      y += z;
    else
      y -= z;
  }
  sort(pos, pos + x + 1);
  for (i = 0; i < x; i++) {
    if (i == 0 || pos[i - 1].y != pos[i].y)
      j = 0;
    else
      j = pos[i - 1].x + 1;
    for (; j < pos[i].x - 1; j++) {
      printf(" ");
    }
    if (pos[i].x != 0) {
      if (a[pos[i].x] > a[pos[i].x - 1]) {
        printf("/");
      } else
        printf(" ");
    }
    if (pos[i].x != x) {
      if (a[pos[i].x] > a[pos[i].x + 1]) {
        printf("\\");
      } else
        printf(" ");
    }
    if (i != x && pos[i].y != pos[i + 1].y) {
      for (j = pos[i].x + 2; j <= x; j++) printf(" ");
      printf("\n");
    }
  }
  return 0;
}
