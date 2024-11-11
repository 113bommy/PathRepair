#include <bits/stdc++.h>
using namespace std;
int n;
int len[110];
char s[110][110];
bool ok[200];
int main() {
  scanf("%d", &n);
  ok['a'] = ok['e'] = ok['i'] = ok['o'] = ok['u'] = ok['y'] = true;
  for (int i = 1; i <= n; i++) scanf("%d", &len[i]);
  char ch = getchar();
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    gets(s[i]);
    int m = strlen(s[i]), cnt = 0;
    for (int j = 0; j < m; j++) {
      if (ok[s[i][j]]) cnt++;
    }
    if (cnt < len[i]) flag = false;
  }
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
