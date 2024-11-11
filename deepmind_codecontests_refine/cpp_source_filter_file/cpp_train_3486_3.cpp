#include <bits/stdc++.h>
void dbg(const char* fmt, ...) {}
char ar[100][100];
int cnt[256];
int main() {
  int n, m;
  int ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", ar[i]);
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m - i; j++) {
      memset(cnt, 0, sizeof(cnt));
      cnt[ar[i][j]]++;
      cnt[ar[i + 1][j]]++;
      cnt[ar[i][j + 1]]++;
      cnt[ar[i + 1][j + 1]]++;
      if (cnt['f'] == 1 && cnt['a'] == 1 && cnt['c'] == 1 && cnt['e'] == 1)
        ans++;
    }
  printf("%d\n", ans);
  return 0;
}
