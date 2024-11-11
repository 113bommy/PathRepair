#include <bits/stdc++.h>
int sg[6010];
char s[6010];
bool bb[6010];
using namespace std;
int dfs(int l, int r) {
  int tt = 1, ans = 0;
  bb[r] = 0;
  for (int i = l + 1; i <= r; i++) {
    tt++;
    if (!bb[i]) {
      ans ^= sg[tt];
      tt = 1;
    }
  }
  if (s[r + 1] == s[r - 1]) bb[r] = true;
  return ans;
}
int ans;
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 3; i <= n; i++) {
    memset(bb, 0, (i + 3) * sizeof(int));
    int p = 0;
    for (int j = 2; j < i; j++) {
      bb[sg[j - 1] ^ sg[i - j]] = 1;
    }
    while (bb[p]) ++p;
    sg[i] = p;
  }
  memset(bb, 0, sizeof(bb));
  ans = 0;
  for (int i = 2; i < n; i++)
    if (s[i - 1] == s[i + 1]) bb[i] = true;
  for (int i = 2; i < n; i++)
    if (bb[i]) {
      if ((dfs(1, i - 1) ^ dfs(i + 1, n)) == 0) {
        ans = i;
        break;
      }
    }
  if (ans)
    printf("First\n%d\n", ans);
  else
    printf("Second");
  return 0;
}
