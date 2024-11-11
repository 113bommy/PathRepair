#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
char str1[200010], str2[200010];
int num[200010];
int vis[200010];
int main() {
  scanf("%s%s", str1 + 1, str2 + 1);
  int l1 = strlen(str1 + 1);
  int l2 = strlen(str2 + 1);
  for (int i = 1; i < l1; i++) scanf("%d", &num[i]);
  int l = 1, r = l1, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= mid; i++) vis[num[i]] = 1;
    int pos = 1;
    for (int i = 1; i <= l1; i++) {
      if (vis[i]) continue;
      if (str1[i] == str2[pos]) pos++;
      if (pos > l2) break;
    }
    if (pos > l2) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  printf("%d\n", ans);
  return 0;
}
