#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int MAX_N = (int)1e5 + 10;
int n, m;
int dp[MAX_N];
char a[MAX_N], b[MAX_N], op[MAX_N];
int f[26][26];
int main() {
  for (int i = 0; i < 26; ++i)
    for (int j = 0; j < 26; ++j) f[i][j] = i == j ? 0 : INF;
  scanf("%s%s", a, b);
  n = strlen(a);
  m = strlen(b);
  if (n != m) return puts("-1"), 0;
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    char u, v;
    int x;
    scanf(" %c %c %d", &u, &v, &x);
    u -= 'a';
    v -= 'a';
    f[u][v] = min(f[u][v], x);
  }
  for (int k = 0; k < 26; ++k)
    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  for (int i = 0; i < n; ++i) {
    int value = i ? dp[i - 1] : 0;
    dp[i] = INF;
    for (int j = 0; j < 26; ++j)
      if (f[a[i] - 'a'][j] + f[b[i] - 'a'][j] + value < dp[i]) {
        dp[i] = f[a[i] - 'a'][j] + f[b[i] - 'a'][j] + value;
        op[i] = j + 'a';
      }
  }
  if (dp[n - 1] == INF)
    puts("-1");
  else {
    printf("%d\n", dp[n - 1]);
    for (int i = 0; i < n; ++i) putchar(op[i]);
    puts("");
  }
}
