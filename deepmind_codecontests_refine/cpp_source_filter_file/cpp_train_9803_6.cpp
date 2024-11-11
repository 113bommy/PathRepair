#include <bits/stdc++.h>
using namespace std;
int a[1000010] = {0};
int main() {
  int n, tot = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    if (a[i] == 1) {
      continue;
    }
    tot++;
    for (int j = i; j <= n; j += i) {
      if (a[j] == 0) {
        a[j] = tot;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
