#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a, b, v, i, j;
  scanf("%d%d%d%d", &k, &a, &b, &v);
  int sec;
  sec = a / v;
  if (a % v != 0) {
    sec++;
  }
  int nb = b / (k - 1);
  int nsec = nb * k;
  int tmp = 0;
  if (b % (k - 1) != 0) {
    nb++;
    tmp = b % (k - 1) + 1;
    nsec += tmp;
  }
  if (sec <= nsec) {
    j = nsec - sec;
    if (j < tmp) {
      printf("%d\n", nb);
    } else if (j == tmp) {
      nb--;
      printf("%d\n", nb);
    } else {
      if (tmp != 0) {
        j -= tmp;
        nb--;
      }
      nb -= j / k;
      printf("%d\n", nb);
    }
  } else {
    nb += sec - nsec;
    printf("%d\n", nb);
  }
  return 0;
}
