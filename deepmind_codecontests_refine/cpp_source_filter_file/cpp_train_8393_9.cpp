#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, vis[26], cur[26];
char op[5], str[N];
void solve() {
  scanf("%d", &n);
  int ans = -1, tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s%s", op, str);
    if (i == n - 1) break;
    int l = strlen(str);
    if (op[0] == '.') {
      for (int j = 0; j < l; j++) {
        vis[str[j] - 'a'] = 1;
      }
    } else if (op[0] == '!') {
      if (ans != -1) {
        tot++;
        continue;
      }
      memset(cur, 0, sizeof(cur));
      for (int j = 0; j < l; j++) {
        cur[str[j] - 'a'] = 1;
      }
      for (int j = 0; j < 26; j++) {
        if (cur[j] != 1)
          vis[j] = 1;
        else if (vis[j] == 0)
          vis[j] = -1;
      }
    } else {
      if (ans != -1) {
        tot++;
        break;
      }
      vis[str[0] - 'a'] = 1;
    }
    int n0 = 0, n1 = 0, n2 = 0, f0, f1;
    for (int j = 0; j < 26; j++) {
      if (vis[j] == 0) n0++, f0 = j;
      if (vis[j] == -1) n1++, f1 = j;
      if (vis[j] == 1) n2++;
    }
    if (n0 == 0 && n1 == 1) ans = f1;
    if (n0 == 1 && n2 == 25) ans = f0;
  }
  printf("%d\n", tot);
}
int main() {
  solve();
  return 0;
}
