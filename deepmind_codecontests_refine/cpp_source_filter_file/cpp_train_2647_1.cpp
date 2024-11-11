#include <bits/stdc++.h>
using namespace std;
int x;
int y;
int xx[105], yy[105];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    xx[x] = 1;
    yy[y] = 1;
  }
  int n1 = 0, n2 = 0;
  for (int i = 0; i < 100; i++) {
    if (xx[i] == 1) n1++;
    if (yy[i] == 1) n2++;
  }
  printf("%d\n", min(n1, n2));
  return 0;
}
