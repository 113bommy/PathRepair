#include <bits/stdc++.h>
using namespace std;
pair<int, int> s[100010];
int n, m[26][26] = {0}, ans = 0, top = 0, vis[26];
char s1[100010], s2[100010];
int dfs(int x) {
  int tmp = 1;
  vis[x] = 1;
  for (int i = 0; i < 26; i++) {
    if (m[x][i] && !vis[i]) {
      s[++top] = make_pair(x, i);
      tmp += dfs(i);
    }
  }
  return tmp;
}
int main() {
  scanf("%d%s%s", &n, s1 + 1, s2 + 1);
  for (int i = 1; i <= n; i++)
    m[(int)(s1[i] - 'a')][(int)(s2[i] - 'a')] =
        m[(int)(s2[i] - 'a')][(int)(s1[i] - 'a')] = 1;
  for (int i = 0; i <= 26; i++)
    if (!vis[i]) ans += dfs(i) - 1;
  printf("%d\n", ans);
  while (top) {
    printf("%c %c\n", (char)(s[top].first + 'a'), (char)(s[top].second + 'a'));
    top--;
  }
  return 0;
}
