#include <bits/stdc++.h>
int q, l, r, pre[1000005], nxt[1000005], vis[200005][27];
char s[1000005];
int count(int l, int r) {
  int cnt = 0;
  for (int i = 0; i < 26; ++i)
    if (vis[r][i] - vis[l - 1][i]) cnt++;
  return cnt;
}
int main() {
  scanf("%s", s + 1);
  int n = std::strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) vis[i - 1][j] = vis[i][j];
    vis[i][s[i] - 'a']++;
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &l, &r);
    if (l == r)
      printf("Yes\n");
    else {
      if (s[l] != s[r]) {
        printf("Yes\n");
        continue;
      }
      if (count(l, r) >= 3)
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  return 0;
}
