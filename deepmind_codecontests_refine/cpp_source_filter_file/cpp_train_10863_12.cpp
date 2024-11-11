#include <bits/stdc++.h>
using namespace std;
int n;
char s[200010], t[200010];
double s1[200010][26], s2[200010][26];
double ans = 0.0;
int main() {
  scanf("%d\n", &n);
  memset(s1, 0, sizeof(s1));
  memset(s2, 0, sizeof(s2));
  for (int i = 1; i <= n; i++) {
    scanf("%c", &s[i]);
    for (int c = 0; c < 26; c++) s1[i][c] = s1[i - 1][c];
    s1[i][s[i] - 'A'] += i;
  }
  scanf("\n");
  for (int i = 1; i <= n; i++) {
    scanf("%c", &t[i]);
    for (int c = 0; c < 26; c++) s2[i][c] = s2[i - 1][c];
    s2[i][t[i] - 'A'] += i;
  }
  scanf("\n");
  double total = 0.0;
  for (int i = 1; i <= n; i++) {
    total += i * i * 1.0;
    ans += 1.0 * (s2[i - 1][s[i] - 'A']) * (n - i + 1);
    ans += 1.0 * (s1[i - 1][t[i] - 'A']) * (n - i + 1);
    if (t[i] == s[i]) ans += 1.0 * i * (n - i + 1);
  }
  double ret = double(ans) / total;
  printf("%.9lf\n", ret);
  return 0;
}
