#include <bits/stdc++.h>
using namespace std;
const int N = 1000500;
int n, nh, ans;
int s[1200][26];
bool ok[60], p[60];
char st[60], s1[60];
int main() {
  scanf("%d", &n);
  scanf("%s", s1);
  for (int i = 0; i < n; i++)
    if (s1[i] != '*')
      s[0][s1[i] - 'a']++;
    else
      p[i] = 1;
  scanf("%d", &nh);
  ans = 0;
  for (int j = 1; j <= nh; j++) {
    scanf("%s", st);
    for (int i = 0; i < n; i++)
      if (p[i]) {
        s[j][st[i] - 'a']++;
        if (s[0][st[i] - 'a']) ok[j] = 1;
      } else if (s1[i] != st[i])
        ok[j] = 1;
  }
  for (int i = 0; i < 26; i++)
    if (!s[0][i]) {
      bool fl = 1;
      for (int j = 1; j <= nh; j++)
        if (!s[j][i] && !ok[j]) {
          fl = 0;
          break;
        }
      if (fl) ans++;
    }
  printf("%d\n", ans);
  return 0;
}
