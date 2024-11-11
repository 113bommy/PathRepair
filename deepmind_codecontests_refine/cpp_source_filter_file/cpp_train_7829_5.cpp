#include <bits/stdc++.h>
using namespace std;
char a[3][3];
int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char b = getchar();
      a[i][j] = b;
    }
    getchar();
  }
  if (a[1][0] == a[1][2] && a[2][0] == a[0][2] && a[0][1] == a[2][1] ||
      (a[1][0] == a[1][2] && a[0][0] == a[2][2] && a[0][1] == a[2][1])) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
