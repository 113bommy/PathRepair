#include <bits/stdc++.h>
using namespace std;
char ch[1000010];
int A[1000010], B[1000010], n, m, s[1000010][3][3];
long long ans(0);
int Get(char ch) {
  if (ch == 'G') return 0;
  if (ch == 'R') return 1;
  if (ch == 'B') return 2;
}
void trans(int len, char *ch, int *a) {
  for (int i = 1; i <= len; i++) a[i] = Get(ch[i]);
}
int main() {
  scanf("%s", ch + 1), n = strlen(ch + 1);
  trans(n, ch, A);
  scanf("%s", ch + 1), m = strlen(ch + 1);
  trans(m, ch, B);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) s[i][j][k] = s[i - 1][j][k];
    s[i][A[i - 1]][A[i]]++;
  }
  for (int i = 1, l, r; i <= m; i++)
    if (i == 1) {
      l = 1, r = 1;
      while (r < n && A[r] != B[i]) r++;
      ans += r - l + 1;
    } else {
      for (r++; r < n && A[r] != B[i];) r++;
      if (r > n) r--;
      if (A[l] == B[i - 1]) l++;
      if (l > n) break;
      ans += r - l + 1;
      if (B[i - 1] != B[i]) ans -= s[r][B[i]][B[i - 1]] - s[l][B[i]][B[i - 1]];
    }
  printf("%lld", ans);
  return 0;
}
