#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
char s[maxn];
int n;
bool t[maxn][maxn];
int v[maxn];
void solve() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) t[i][j] = 0;
  int cnt = 0;
  scanf("%s", s + 1);
  for (int i = (1); i <= (n); ++i) {
    if (s[i] == '2') v[++cnt] = i;
  }
  if (cnt >= 3) {
    puts("YES");
    for (int i = (2); i <= (cnt); ++i) t[v[i - 1]][v[i]] = 1;
    t[v[cnt]][v[1]] = 1;
    for (int i = (1); i <= (n); ++i) {
      for (int j = (1); j <= (n); ++j) {
        if (i == j)
          putchar('X');
        else if (t[i][j])
          putchar('+');
        else if (t[j][i])
          putchar('-');
        else
          putchar('=');
      }
      putchar('\n');
    }
  } else if (cnt == 0) {
    puts("YES");
    for (int i = (1); i <= (n); ++i) {
      for (int j = (1); j <= (n); ++j) {
        if (i == j)
          putchar('X');
        else
          putchar('=');
      }
      putchar('\n');
    }
  } else
    puts("NO");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
