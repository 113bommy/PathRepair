#include <bits/stdc++.h>
using namespace std;
int a[4];
int main() {
  scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
  bool ok1, ok2;
  ok1 = ok2 = false;
  int n = 4;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++) {
        if (((a[i] + a[j]) > a[k]) && ((a[j] + a[k]) > a[i]) &&
            (a[i] + a[k] > a[j]))
          ok1 = true;
        if (((a[i] + a[j]) == a[k]) || ((a[j] + a[k]) == a[i]) ||
            (a[i] + a[k] > a[j]))
          ok2 = true;
      }
  if (ok1)
    printf("TRIANGLE\n");
  else if (ok2)
    printf("SEGMENT\n");
  else
    printf("IMPOSSIBLE\n");
}
