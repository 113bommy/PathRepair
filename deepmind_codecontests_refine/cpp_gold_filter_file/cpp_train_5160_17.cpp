#include <bits/stdc++.h>
const int maxn = 100010;
using namespace std;
int a[maxn];
int ask(int i, int j) {
  printf("? %d %d\n", i, j);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}
int main() {
  int N, M, i, j;
  scanf("%d", &N);
  int x = ask(1, 2);
  int y = ask(2, 3);
  int z = ask(1, 3);
  a[1] = (x + y + z) / 2 - y;
  a[2] = (x + y + z) / 2 - z;
  a[3] = (x + y + z) / 2 - x;
  for (i = 4; i <= N; i++) {
    a[i] = ask(1, i) - a[1];
  }
  printf("! ");
  for (i = 1; i <= N; i++) printf("%d ", a[i]);
  return 0;
}
