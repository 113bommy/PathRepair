#include <bits/stdc++.h>
using namespace std;
int n, k;
char a[1000];
int Next[1000];
void make_next() {
  Next[0] = -1;
  int k = -1, j = 0;
  while (j < n) {
    if (k == -1 || a[j] == a[k]) {
      k++;
      j++;
      Next[j] = k;
    } else {
      k = Next[k];
    }
  }
}
int main() {
  int i;
  scanf("%d %d %s", &n, &k, a);
  make_next();
  printf("%s", a);
  int p = Next[n - 1];
  while (p > -1 && a[n - 1] != a[p]) {
    p = Next[p];
  }
  for (i = 2; i <= k; i++) {
    printf("%s", a + p + 1);
  }
  printf("\n");
  return 0;
}
