#include <bits/stdc++.h>
const int N = 2000009;
int n;
char s[N], s2[N];
int nex[N];
inline void init() {
  scanf("%d", &n);
  scanf("%s%s", s + 1, s2 + 1);
}
inline char inv(char c) {
  if (c == 'N')
    return 'S';
  else if (c == 'S')
    return 'N';
  else if (c == 'E')
    return 'W';
  else
    return 'E';
}
inline void solve() {
  std::reverse(s + 1, s + n + 1);
  for (int i = 1; i <= n; ++i) s[i] = inv(s[i]);
  std::copy(s2 + 1, s2 + n + 1, s + n + 1);
  for (int i = 2; i <= 2 * n; ++i) {
    int j = nex[i - 1];
    while (j && s[i] != s[j + 1]) j = nex[j];
    if (s[i] == s[j + 1]) j++;
    nex[i] = j;
  }
  int cur = 2 * n;
  while (cur > n) cur = nex[cur];
  puts(cur ? "NO" : "YES");
}
int main() {
  init();
  solve();
  return 0;
}
