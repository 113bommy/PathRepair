#include <bits/stdc++.h>
using namespace std;
const int q[19] = {2,  3,  4,  5,  7,  9,  11, 13, 17, 19,
                   23, 25, 29, 31, 37, 41, 43, 47, 49};
int main() {
  char ret[5];
  int cnt = 0;
  for (int i = 0; i < 19; i++) {
    printf("%d\n", q[i]);
    fflush(stdout);
    scanf("%s", ret);
    if (ret[0] == 'y') cnt++;
    if (cnt >= 2) {
      printf("composite\n");
      return 0;
    }
  }
  printf("prime\n");
  return 0;
}
