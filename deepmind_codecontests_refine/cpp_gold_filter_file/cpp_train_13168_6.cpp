#include <bits/stdc++.h>
int cmpfunc(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int main() {
  int n, s, p[1009], q[1009], i, j, k, m, buy[100009] = {0}, sell[100009] = {0},
                                          count;
  char d[1009];
  scanf("%d %d", &n, &s);
  for (i = 1; i <= n; i++) {
    getchar();
    scanf("%c %d %d", &d[i], &p[i], &q[i]);
  }
  for (i = 1; i <= n; i++) {
    if (d[i] == 'B') {
      buy[p[i]] += q[i];
    } else {
      sell[p[i]] += q[i];
    }
  }
  count = s;
  for (i = 0; i <= 100000 && count; i++) {
    if (sell[i] > 0) {
      count--;
    }
  }
  for (i = i - 1; i >= 1; i--) {
    if (sell[i] > 0) {
      printf("S %d %d\n", i, sell[i]);
    }
  }
  count = s;
  for (i = 100000; i >= 0 && count; i--) {
    if (buy[i] > 0) {
      printf("B %d %d\n", i, buy[i]);
      count--;
    }
  }
  return 0;
}
