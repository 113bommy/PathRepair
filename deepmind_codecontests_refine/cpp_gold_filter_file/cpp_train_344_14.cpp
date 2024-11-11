#include <bits/stdc++.h>
using namespace std;
const int maxn = 5100, inf = 0x3f3f3f3f;
char s[maxn], tt[maxn];
int num[30], len, n, t[maxn], ans[maxn];
bool dfs(int p) {
  if (p == len) {
    if (len > n)
      return 1;
    else
      return 0;
  }
  if (p == n) {
    if (len == n) return 0;
    int cur = 0;
    for (int j = p; j < len; j++) {
      while (!num[cur]) cur++;
      ans[j] = cur;
      num[cur]--;
    }
    return 1;
  }
  if (num[t[p]]) {
    num[t[p]]--;
    ans[p] = t[p];
    if (dfs(p + 1)) return 1;
    num[t[p]]++;
  }
  int i;
  for (i = t[p] + 1; i < 26; i++)
    if (num[i]) break;
  if (i == 26) return 0;
  ans[p] = i;
  num[i]--;
  int cur = 0;
  for (int j = p + 1; j < len; j++) {
    while (!num[cur]) cur++;
    ans[j] = cur;
    num[cur]--;
  }
  return 1;
}
int main() {
  while (cin >> s >> tt) {
    memset(num, 0, sizeof(num));
    len = strlen(s);
    for (int i = 0; i < len; i++) num[s[i] - 'a']++;
    n = strlen(tt);
    for (int i = 0; i < n; i++) t[i] = tt[i] - 'a';
    if (!dfs(0))
      puts("-1");
    else {
      for (int i = 0; i < len; i++) printf("%c", ans[i] + 'a');
      cout << endl;
    }
  }
}
