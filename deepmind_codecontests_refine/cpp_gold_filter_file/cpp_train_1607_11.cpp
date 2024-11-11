#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4];
  int b[4];
  for (int i = 1; i <= 3; i++) {
    scanf("%d", &a[i]);
  }
  for (int j = 1; j <= 3; j++) {
    scanf("%d", &b[j]);
  }
  int l = ((a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2]) +
           (a[3] - b[3]) * (a[3] - b[3]));
  if (l == 3) {
    printf("NO");
  } else {
    printf("YES");
  }
}
