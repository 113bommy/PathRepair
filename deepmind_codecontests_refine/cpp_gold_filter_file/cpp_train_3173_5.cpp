#include <bits/stdc++.h>
using namespace std;
struct node {
  int num, id;
  int a[110];
} p[110];
int vis[110];
int main() {
  int n, k, i, j, l, temp, num, flag;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &p[i].num);
    p[i].id = i;
    memset(p[i].a, 0, sizeof(p[i].a));
  }
  memset(vis, 0, sizeof(vis));
  temp = 1;
  while (1) {
    flag = 0;
    for (i = 0; i < n; i++) {
      if (p[i].num) {
        p[i].num--;
        p[i].a[temp]++;
      } else
        flag++;
    }
    if (flag == n) break;
    if (flag) vis[temp] = 1;
    flag = temp;
    temp++;
    if (temp == k + 1) temp = 1;
    while (vis[temp] == 1) {
      temp++;
      if (temp == k + 1) temp = 1;
      if (temp == flag) break;
    }
    if (vis[temp]) break;
  }
  for (i = 0; i < n; i++)
    if (p[i].num) break;
  if (i < n) {
    printf("NO\n");
  } else {
    printf("YES\n");
    for (i = 0; i < n; i++) {
      flag = 0;
      for (j = 1; j <= k; j++) {
        if (p[i].a[j]) {
          for (l = 0; l < p[i].a[j]; l++) {
            if (flag == 0) {
              printf("%d", j);
              flag = 1;
            } else {
              printf(" %d", j);
            }
          }
        }
      }
      printf("\n");
    }
  }
  return 0;
}
