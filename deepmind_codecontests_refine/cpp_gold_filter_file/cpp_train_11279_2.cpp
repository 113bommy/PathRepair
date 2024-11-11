#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n;
int len[N], S[N], T[N];
int g[26][26];
char s[100];
int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    gets(s);
    S[i] = s[0] - 'a';
    T[i] = s[(len[i] = strlen(s)) - 1] - 'a';
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j)
      if (g[j][S[i]]) g[j][T[i]] = max(g[j][T[i]], g[j][S[i]] + len[i]);
    g[S[i]][T[i]] = max(g[S[i]][T[i]], len[i]);
  }
  int ans = 0;
  for (int i = 0; i < 26; ++i) ans = max(ans, g[i][i]);
  printf("%d\n", ans);
  return 0;
}
