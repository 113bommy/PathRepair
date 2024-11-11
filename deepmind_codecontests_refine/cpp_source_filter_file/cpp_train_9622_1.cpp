#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int i;
  int array[101];
  int ans[100];
  int k = 0;
  int start = 1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &array[i]);
  for (i = 1; i <= n; i++) {
    if (array[i] == start) {
      start++;
      k++;
      ans[k] = start + 2000;
    }
  }
  printf("%d\n", k);
  for (i = 1; i <= k; i++) printf("%d ", ans[i]);
  if (k > 0) printf("\n");
  return 0;
}
