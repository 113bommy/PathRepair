#include <bits/stdc++.h>
using namespace std;
const int MAXN = 60;
bool book[MAXN][MAXN][MAXN][MAXN];
int card[MAXN + 10], *p = card + 10;
bool ok;
int m1[200];
void dfs(int len, int a, int b, int c) {
  if (ok || book[len][a][b][c]) return;
  book[len][a][b][c] = 1;
  if (len == 1) {
    ok = 1;
    return;
  }
  if (b / 13 == c / 13 || b % 13 == c % 13) dfs(len - 1, p[len - 3], a, c);
  if (len > 3 && (p[len - 3] / 13 == c / 13 || p[len - 3] % 13 == c % 13))
    dfs(len - 1, c, a, b);
  return;
}
int main() {
  m1['A'] = 0;
  for (char c = '2'; c <= '9'; c++) m1[c] = c - '1';
  m1['T'] = 9, m1['J'] = 10, m1['Q'] = 11, m1['K'] = 12;
  m1['S'] = 0, m1['D'] = 1, m1['H'] = 2, m1['C'] = 3;
  for (int i = 1; i <= 10; i++) card[i] = 55;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char s[10];
    scanf("%s", s);
    p[i] = m1[s[1]] * 13 + m1[s[0]];
  }
  ok = 0;
  dfs(n, p[n - 2], p[n - 1], p[n]);
  printf("%s\n", ok ? "YES" : "NO");
  return 0;
}
