#include <bits/stdc++.h>
using namespace std;
char s1[200005], s2[200005];
int mark[200005], a[200005], n, m;
bool check(int len) {
  memset(mark, 0, sizeof(mark));
  for (int i = 1; i <= len; i++) mark[a[i]] = 1;
  int id = 1;
  for (int i = 1; i <= n; i++) {
    if (mark[i]) continue;
    if (s1[i] == s2[id]) id++;
  }
  return id > m;
}
int main() {
  scanf("%s %s", s1 + 1, s2 + 1);
  n = strlen(s1 + 1);
  m = strlen(s2 + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 1, r = n, res = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      res = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  printf("%d\n", res);
  return 0;
}
