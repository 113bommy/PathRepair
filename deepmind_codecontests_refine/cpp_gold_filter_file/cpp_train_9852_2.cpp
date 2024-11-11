#include <bits/stdc++.h>
using namespace std;
int n, m, c, sol, p[1100], l, r, a, flag;
int main() {
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 0; i < n + 1; i++) {
    p[i] = -1;
  }
  l = 0;
  r = n - 1;
  for (int i = 0; i < m; i++) {
    scanf("%d", &a);
    if (a > c / 2) {
      int j = 0;
      while (j < n && (a > p[j] || p[j] == -1)) {
        j++;
      }
      p[j - 1] = a;
      printf("%d\n", j);
      fflush(stdout);
    } else {
      int j = n - 1;
      while (j >= 0 && (a < p[j] || p[j] == -1)) {
        j--;
      }
      p[j + 1] = a;
      printf("%d\n", j + 2);
      fflush(stdout);
    }
    flag = 1;
    for (int j = 0; j < n - 1; j++) {
      if (p[j] == -1 || p[j] > p[j + 1]) {
        flag = 0;
      }
    }
    if (flag) {
      return 0;
    }
  }
  return 0;
}
