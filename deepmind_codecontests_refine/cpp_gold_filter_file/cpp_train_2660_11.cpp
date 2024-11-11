#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4], i, j, k, l, max = 0;
  for (i = 0; i < 4; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + 4);
  if (a[0] + a[1] > a[2] || a[0] + a[1] > a[3] || a[1] + a[2] > a[3])
    printf("TRIANGLE\n");
  else if (a[0] + a[1] == a[2] || a[0] + a[1] == a[3] || a[1] + a[2] == a[3])
    printf("SEGMENT\n");
  else
    printf("IMPOSSIBLE\n");
}
