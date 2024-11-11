#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
char s[MAXN], t[MAXN];
bool bo[MAXN], ff[MAXN];
int n, m, ans, cnt[MAXN];
int main() {
  scanf("%d%s%d", &n, s, &m);
  int tmpm = m;
  for (int i = 0; i < n; ++i)
    if (s[i] != '*') bo[s[i] - 'a'] = true;
  for (int i = 0; i < m; ++i) {
    scanf("%s", t);
    bool flag = true;
    for (int j = 0; j < n; ++j) {
      if (s[j] == '*' && bo[t[j] - 'a']) {
        flag = false;
        --tmpm;
        break;
      }
      if (s[j] != '*' && s[j] != t[j]) {
        flag = false;
        --tmpm;
        break;
      }
    }
    if (!flag) continue;
    for (int i = 0; i < 26; ++i) ff[i] = false;
    for (int j = 0; j < n; ++j)
      if (s[j] == '*') ff[t[j] - 'a'] = true;
    for (int i = 0; i < 26; ++i)
      if (ff[i]) ++cnt[i];
  }
  for (int i = 0; i < 26; ++i)
    if (!bo[i] && cnt[i] == tmpm) ++ans;
  printf("%d\n", ans);
  return 0;
}
