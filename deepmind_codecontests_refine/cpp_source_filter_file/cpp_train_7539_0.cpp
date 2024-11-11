#include <bits/stdc++.h>
using namespace std;
int ans;
char a[1005], b[1005];
int sa[30], sb[30];
int min(int x, int y) {
  if (x < y)
    return x;
  else
    return y;
}
int main() {
  int i, la, lb;
  scanf("%s", a);
  scanf("%s", b);
  la = strlen(a);
  lb = strlen(b);
  memset(sa, 0, sizeof(sa));
  memset(sb, 0, sizeof(sb));
  for (i = 0; i < la; i++) sa[a[i] - 'a']++;
  for (i = 0; i < lb; i++) sb[b[i] - 'a']++;
  ans = 0;
  for (i = 0; i < 26; i++) {
    if (a[i] == 0 && b[i] > 0) {
      ans = -1;
      break;
    } else
      ans += min(a[i], b[i]);
  }
  if (ans == 0)
    printf("-1\n");
  else
    printf("%d\n", ans);
  return 0;
}
