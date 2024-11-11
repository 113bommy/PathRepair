#include <bits/stdc++.h>
using namespace std;
int n, mn[30][2200], sum[30][2200];
char c;
string s;
int main() {
  cin >> n >> s;
  s = "#" + s;
  for (int i = 1; i <= n; i++) sum[s[i] - 'a'][i] = 1;
  for (int i = 0; i < 26; i++) {
    for (int j = 2; j <= n; j++) sum[i][j] += sum[i][j - 1];
  }
  for (int i = 0; i < 26; i++) {
    for (int l = 1; l <= n; l++)
      for (int r = l; r <= n; r++) {
        mn[i][r - l + 1 - sum[i][r] + sum[i][l - 1]] =
            max(mn[i][r - l + 1 - sum[i][r] + sum[i][l - 1]], r - l + 1);
      }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j <= n; j++) mn[i][j] = max(mn[i][j], mn[i][j - 1]);
  }
  int q, m;
  cin >> q;
  for (int i = 0; i < q; i++) {
    scanf("%d %c", &m, &c);
    printf("%d\n", mn[c - 'a'][m]);
  }
  return 0;
}
