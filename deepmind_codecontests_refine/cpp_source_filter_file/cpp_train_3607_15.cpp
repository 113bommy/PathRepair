#include <bits/stdc++.h>
using namespace std;
char s1[2005], s2[2005], s3[2005];
int n, ans[2005], len;
void work(int x) {
  int l = x, r = n;
  while (l <= r) swap(s1[l], s1[r]), l++, r--;
  for (int i = 1, j = x; j <= n; i++, j++) s3[i] = s1[j];
  for (int i = n - x + 2, j = 1; i <= n; i++, j++) s3[i] = s1[j];
  for (int i = 1; i <= n; i++) s1[i] = s3[i];
  ans[++len] = n - x + 1;
}
int main(void) {
  int i, j;
  scanf("%d", &n);
  scanf("%s%s", s1 + 1, s2 + 1);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n - i + 1; j++)
      if (s1[j] == s2[i]) break;
    if (j == n - i + 2) {
      printf("-1\n");
      return 0;
    }
    work(j + 1);
    work(n);
    work(2);
  }
  printf("%d\n", len);
  for (int i = 1; i <= len; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
