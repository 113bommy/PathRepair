#include <bits/stdc++.h>
using namespace std;
char str[1000];
int cc(int tt) {
  printf("%d\n", tt);
  fflush(stdout);
  scanf("%s", str);
  if (str[0] == 'y') {
    if (tt <= 9) {
      printf("%d\n", tt * tt);
      fflush(stdout);
      scanf("%s", str);
      if (str[0] == 'y') {
        return 2;
      } else
        return 1;
    } else
      return 1;
  }
  return 0;
}
int main() {
  int a[150] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
  int count = 0;
  for (int i = 0; i < 15; ++i) {
    int num = cc(a[i]);
    count += num;
  }
  if (count < 2)
    printf("prime\n");
  else
    printf("composite\n");
  fflush(stdout);
  return 0;
}
