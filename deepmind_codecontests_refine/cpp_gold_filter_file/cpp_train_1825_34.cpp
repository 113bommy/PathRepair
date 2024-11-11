#include <bits/stdc++.h>
using namespace std;
int n, m, n2, m2, len;
long long str1[200010], str2[200010], str3[200010], f[200010];
long long ans;
char s[10];
void find() {
  int i, j = 0, l, r;
  for (i = 0; i < n; i++) {
    while (j && str3[j] != str1[i]) j = f[j];
    if (str3[j] == str1[i]) j++;
    if (j == len) {
      l = i - len + 1 - 1;
      r = l + m - 1;
      if (l >= 0 && r < n && str1[l] % 100 == str2[0] % 100 &&
          str1[l] / 100 >= str2[0] / 100 &&
          str1[r] % 100 == str2[m - 1] % 100 &&
          str1[r] / 100 >= str2[m - 1] / 100)
        ans++;
    }
  }
}
void getfail() {
  int i, j;
  memset(f, 0, sizeof(f));
  for (i = 1; i < len; i++) {
    j = f[i];
    while (j && str3[j] != str3[i]) j = f[j];
    if (str3[j] == str3[i])
      f[i + 1] = j + 1;
    else
      f[i + 1] = 0;
  }
}
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d%s", &k, s);
    str1[i] = k * 100 + s[1] - 97;
  }
  for (i = 1; i < n; i++) {
    if (str1[n2] % 100 == str1[i] % 100)
      str1[n2] += str1[i] / 100 * 100;
    else
      str1[++n2] = str1[i];
  }
  n = n2 + 1;
  for (i = 0; i < m; i++) {
    scanf("%d%s", &k, s);
    str2[i] = k * 100 + s[1] - 97;
  }
  for (i = 1; i < m; i++)
    if (str2[m2] % 100 == str2[i] % 100)
      str2[m2] += str2[i] / 100 * 100;
    else
      str2[++m2] = str2[i];
  m = m2 + 1;
  if (m == 1) {
    for (i = 0; i < n; i++)
      if (str1[i] % 100 == str2[0] % 100 && str1[i] / 100 >= str2[0] / 100)
        ans += str1[i] / 100 - str2[0] / 100 + 1;
  } else if (m == 2) {
    for (i = 0; i < n - 1; i++)
      if (str1[i] % 100 == str2[0] % 100 && str1[i] / 100 >= str2[0] / 100 &&
          str1[i + 1] % 100 == str2[1] % 100 &&
          str1[i + 1] / 100 >= str2[1] / 100)
        ans++;
  } else {
    len = m - 2;
    for (i = 1; i <= len; i++) str3[i - 1] = str2[i];
    getfail();
    find();
  }
  printf("%I64d\n", ans);
}
