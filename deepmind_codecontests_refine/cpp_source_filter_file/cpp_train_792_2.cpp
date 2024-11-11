#include <bits/stdc++.h>
using namespace std;
int n, m;
char str[100][100];
int cnt[300][26];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) scanf("%s", str[i]);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) ++cnt[i][str[i][j] - 'a'];
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) ++cnt[i + 100][str[j][i] - 'a'];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (cnt[i][str[i][j] - 'a'] > 1 || cnt[j + 100][str[i][j] - 'a'] > 1)
        ;
      else
        printf("%c", str[i][j]);
  printf("\n");
}
