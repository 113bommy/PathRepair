#include <bits/stdc++.h>
using namespace std;
int s[101][101];
int n;
int main() {
  int x1, y1, x2, y2;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int i = x1; i <= x2; i++) {
      for (int j = y1; j <= y2; j++) {
        s[i][j]++;
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      sum += s[i][j];
    }
  }
  printf("%d\n", sum);
  return 0;
}
