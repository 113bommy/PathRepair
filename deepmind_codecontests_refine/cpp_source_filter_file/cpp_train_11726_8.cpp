#include <bits/stdc++.h>
using namespace std;
int n, flag, pos, maxn, tot, s[100005];
int main() {
  scanf("%d", &n);
  for (int i = 0, pre = 0; i <= n; pre = s[i], i++) {
    scanf("%d", &s[i]);
    if (pre > 1 && s[i] > 1) pos = i, flag = 1;
  }
  if (!flag)
    printf("perfect\n");
  else {
    printf("ambiguous\n");
    for (int i = 0, pre = 0; i <= n; pre = tot, i++)
      for (int j = 1; j <= s[i]; j++) printf("%d ", pre), tot++;
    printf("\n");
    tot = 0;
    for (int i = 0, pre = 0; i < pos; pre = tot, i++)
      for (int j = 1; j <= s[i]; j++) printf("%d ", pre), tot++;
    printf("%d ", tot - 1);
    for (int i = 2; i <= s[i]; i++) printf("%d ", tot);
    tot += s[pos];
    for (int i = pos + 1, pre = tot; i <= n; pre = tot, i++)
      for (int j = 1; j <= s[i]; j++) printf("%d ", pre), tot++;
    printf("\n");
  }
  return 0;
}
