#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  int l;
  for (l = 0; l < t; l++) {
    int n;
    int m;
    int sum = 0;
    scanf("%d %d", &n, &m);
    int size = n + 1;
    int a[size];
    for (int index = 1; index < n + 1; index++) {
      scanf("%d", &a[index]);
    }
    int i, j;
    for (i = 1; i < n + 1; i++) {
      sum = sum + a[i];
    }
    if (m == sum) {
      printf("YES");
    } else {
      printf("NO");
    }
  }
}
