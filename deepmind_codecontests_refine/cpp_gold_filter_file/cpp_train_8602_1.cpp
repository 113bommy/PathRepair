#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 2;
char A[N];
int main() {
  scanf("%s", A + 1);
  int ans = 0;
  int i, j;
  int n = strlen(A + 1);
  for (i = 1; i <= n; i++) {
    int b = 0, x = 0, y = 0;
    for (j = i; j <= n; j++) {
      if (A[j] == '(') {
        x++;
        y++;
      }
      if (A[j] == ')') {
        x--;
        y--;
        if (y < 0) {
          y += 2;
        }
      }
      if (A[j] == '?') {
        x++;
        y--;
        if (y < 0) {
          y += 2;
        }
      }
      if (y > x) {
        break;
      } else {
        if (y == 0) {
          ans++;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
