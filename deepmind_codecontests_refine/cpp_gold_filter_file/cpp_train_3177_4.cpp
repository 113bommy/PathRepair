#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5], b[5];
  while (~scanf("%d%d%d", &a[0], &a[1], &a[2])) {
    scanf("%d%d%d", &b[0], &b[1], &b[2]);
    int sum = 0;
    for (int i = 0; i < 3; i++) {
      if (a[i] > b[i]) {
        sum += (a[i] - b[i]) / 2;
      } else {
        sum += a[i] - b[i];
      }
    }
    if (sum >= 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
