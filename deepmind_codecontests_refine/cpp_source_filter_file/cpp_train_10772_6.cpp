#include <bits/stdc++.h>
using namespace std;
char s[200005], t[200005];
int m[26][26];
int pos[26];
int main() {
  int i, k, j, n, ans = 0, t1, t2;
  scanf("%d%s%s", &n, s, t);
  memset(m, 0, sizeof(m));
  int flag = 0;
  for (i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      ++ans;
      m[s[i] - 'a'][t[i] - 'a'] = i + 1;
      pos[s[i] - 'a'] = i;
    }
  }
  for (i = 0; i < 26 && flag != 1; ++i)
    for (j = 0; j < 26 && flag != 1; ++j) {
      if (m[i][j] && m[j][i]) {
        flag = 1;
        t1 = m[i][j], t2 = m[j][i];
      }
      if (m[i][j] && !flag && pos[i]) {
        flag = 2;
        t1 = m[i][j];
        t2 = pos[i];
        break;
      }
    }
  if (!flag)
    printf("%d\n-1 -1\n", ans);
  else
    printf("%d\n%d %d\n", ans - 3 + flag, t1, t2);
  return 0;
}
