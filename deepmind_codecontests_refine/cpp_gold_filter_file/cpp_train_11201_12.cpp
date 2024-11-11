#include <bits/stdc++.h>
using namespace std;
int v1[1010], v2[1010];
int main() {
  int n;
  scanf("%d", &n);
  int p = 0;
  for (int i = 1; i <= n; i++) scanf("%d%d", &v1[i], &v2[i]);
  for (int i = 1; i <= n; i++) {
    if (v1[i] != v2[i]) {
      printf("rated");
      return 0;
    }
    if (v1[i] < v1[i + 1]) p = 1;
  }
  if (p == 1)
    printf("unrated");
  else
    printf("maybe");
  return 0;
}
