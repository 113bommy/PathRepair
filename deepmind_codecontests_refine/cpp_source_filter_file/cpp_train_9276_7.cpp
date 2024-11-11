#include <bits/stdc++.h>
using namespace std;
int bus[105];
int main() {
  int n, t, k;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    for (int j = 0; j < t; j++) {
      scanf("%d", &k);
      bus[k]++;
    }
  }
  int first = 1;
  for (int i = 1; i <= 100; i++) {
    if (bus[i] == n) {
      if (first)
        printf("%d", i), first = 0;
      else
        printf(", %d", i);
    }
  }
  putchar('\n');
  return 0;
}
