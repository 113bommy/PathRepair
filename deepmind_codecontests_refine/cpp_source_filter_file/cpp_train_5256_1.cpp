#include <bits/stdc++.h>
using namespace std;
char s[200100], t[200100];
char ss[200100], tt[200100];
bool ok[200100][26];
int f[200100];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  for (char x = 'a'; x <= 'z'; x++) {
    for (char y = x; y <= 'z'; y++) {
      for (int i = 1; i <= n; i++)
        if (s[i] == x || s[i] == y)
          ss[i] = s[i];
        else
          ss[i] = '#';
      for (int i = 1; i <= m; i++)
        if (t[i] == x)
          tt[i] = y;
        else if (t[i] == y)
          tt[i] = x;
        else
          tt[i] = '#';
      for (int i = 2, j = 0; i <= m; i++) {
        while (j && tt[j + 1] != tt[i]) j = f[j];
        if (tt[j + 1] == tt[i]) j++;
        f[i] = j;
      }
      for (int i = 1, j = 0; i <= n; i++) {
        while (j && ss[i] != tt[j + 1]) j = f[j];
        if (ss[i] == tt[j + 1]) j++;
        if (j == m) {
          ok[i - m + 1][x - 'a'] = 1;
          ok[i - m + 1][y - 'a'] = 1;
          j = f[j];
        }
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool f = true;
    for (int j = 0; j < 26; j++) {
      if (!ok[i][j]) {
        f = false;
        break;
      }
    }
    if (f) ans.push_back(i);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
