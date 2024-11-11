#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v1(n);
  int a[101][101] = {{0}};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      if (i != j) {
        if (a[i][j] == 1) {
          v1[i] = 1;
        } else if (a[i][j] == 2) {
          v1[j] = 1;
        } else if (a[i][j]) {
          v1[i] = 1;
          v1[j] = 1;
        }
      }
    }
  }
  int c = 0;
  int f = 0;
  for (int i = 1; i <= n; i++) {
    if (v1[i] == 0) c++;
  }
  printf("%d\n", c);
  if (c == 0) f = 1;
  if (f == 0) {
    for (int i = 1; i <= n; i++) {
      if (v1[i] == 0) {
        printf("%d ", i);
      }
    }
    printf("\n");
  }
  return 0;
}
