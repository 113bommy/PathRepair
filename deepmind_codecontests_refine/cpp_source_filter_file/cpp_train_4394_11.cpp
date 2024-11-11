#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
char s[maxn * 3];
bool ok[maxn * 3];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == 'W') cnt++;
  if (cnt == 0 || cnt == n) return 0 * puts(s);
  bool flag = true;
  for (int i = 0; i < n; i++)
    if (s[i] == s[(i + 1) % n]) flag = false;
  if (flag) {
    if (k % 2)
      for (int i = 0; i < n; i++) s[i] = (s[i] == 'W' ? 'B' : 'W');
    return 0 * puts(s);
  }
  for (int i = 0; i < n; i++) s[n + i] = s[2 * n + i] = s[i];
  for (int i = 1; i < 3 * n - 1; i++)
    ok[i] = (s[i] != s[i - 1] && s[i] != s[i] + 1);
  for (int i = 0, j = 0; i < 3 * n; i = j) {
    if (!ok[i]) {
      j = i + 1;
      continue;
    }
    while (j < 3 * n && ok[j]) j++;
    int cnt = j - i;
    for (int x = 0; x < cnt; x++)
      if (k >= min(x + 1, cnt - x))
        s[i + x] = x < cnt / 2 ? s[i - 1] : s[j];
      else if (k % 2)
        s[i + k] = (s[i + k] == 'W' ? 'B' : 'W');
  }
  for (int i = n; i < 2 * n; i++) printf("%c", s[i]);
  return 0;
}
