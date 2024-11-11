#include <bits/stdc++.h>
using namespace std;
int a[] = {0, 4, 8, 15, 16, 23, 42};
int ans[5];
int main() {
  for (int i = 1; i <= 4; i++) {
    printf("? %d %d\n", i, i + 1);
    fflush(stdout);
    scanf("%d", &ans[i]);
  }
  do {
    if (a[1] * a[2] == ans[1] && a[2] * a[3] == ans[2] &&
        a[3] * a[4] == ans[3] && a[4] * a[5] == ans[4])
      break;
  } while (next_permutation(a, a + 6));
  printf("!");
  for (int i = 1; i <= 6; i++) printf(" %d", a[i]);
  cout << endl;
  return 0;
}
