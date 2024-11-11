#include <bits/stdc++.h>
using namespace std;
int n;
inline bool check(int cur) {
  if (cur == 1)
    return 0;
  else if (cur == 2)
    return 1;
  int tmp = sqrt(cur);
  if (tmp * tmp == cur) return 0;
  for (int i = 2; i <= tmp; i++) {
    if (cur % i == 0) {
      return 0;
    }
  }
  return 1;
}
signed main() {
  scanf("%d", &n);
  if (n == 1) {
    printf("%d\n", -1);
    return 0;
  }
  int s = (1 + n) * n / 2;
  if (check(s)) {
    for (int i = 1; i <= n; i++) printf("1 ");
  } else if (s % 2 == 0) {
    for (int i = 1; i <= n; i++) {
      if (check(i) && check(s - i)) {
        for (int j = 1; j < i; j++) printf("1 ");
        printf("2 ");
        for (int j = i + 1; j <= n; j++) printf("1 ");
        return 0;
      }
    }
  } else {
    if (check(s - 2)) {
      printf("1 2 ");
      for (int i = 3; i <= n; i++) printf("1 ");
    } else {
      s = s - 3;
      for (int i = 1; i <= n; i++) {
        if (i == 3) continue;
        if (check(i) && check(s - i)) {
          for (int j = 1; j < i; j++) {
            if (j == 3)
              printf("3");
            else
              printf("1 ");
          }
          printf("2 ");
          for (int j = i + 1; j <= n; j++) {
            if (j == 3)
              printf("3");
            else
              printf("1 ");
          }
          return 0;
        }
      }
    }
  }
  return 0;
}
