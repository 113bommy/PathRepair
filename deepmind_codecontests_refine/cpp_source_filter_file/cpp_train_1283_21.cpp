#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005], x[100005];
int main() {
  int n, m, sumb = 0, i;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    if (x[i] > 0) {
      a[x[i]]++;
    } else {
      b[-x[i]]++;
      sumb++;
    }
  }
  int k = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] + sumb - b[i] == m) {
      c[i] = 1;
      k++;
    }
  }
  for (i = 1; i <= n; i++) {
    if (x[i] > 0) {
      if (c[x[i]] == 1 && k == 1) {
        printf("Truth\n");
      } else if (c[x[i]] == 0) {
        printf("Lie\n");
      } else
        printf("Not defined\n");
    } else {
      if (c[-x[i]] == 0) {
        printf("Truth\n");
      } else if (c[x[i]] == 1 && k == 1) {
        printf("Lie\n");
      } else
        printf("Not defined\n");
    }
  }
  return 0;
}
