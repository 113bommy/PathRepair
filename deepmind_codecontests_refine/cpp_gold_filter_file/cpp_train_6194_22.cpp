#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1005];
  scanf("%d", &n);
  int i, flag = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (a[i] == 1) flag = 1;
  }
  if (flag) {
    printf("-1\n");
  } else {
    printf("1\n");
  }
  return 0;
}
