#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
template <class T>
T sqr(T x) {
  return x * x;
}
char s[3000000], s1[3000000];
int n;
double calc(char *s) {
  double res = 0;
  int rx = 0;
  for (int i = 0; i < (int)(n); i++)
    if (s[i] != 'X') rx++;
  if (n % 2 == 0)
    res = (double)rx / (n + 1) / 2.;
  else
    res = (double)rx / n / 2.;
  int dp = 0;
  int ry = 0;
  int len = 0;
  int i = 0;
  int l1 = 0;
  while (i < n) {
    if ((s[i] == 'L' && ((dp + i) & 1) == 1) ||
        (s[i] == 'R' && ((dp + i) & 1) == 0))
      len++;
    else if ((s[i] == 'L' && ((dp + i) & 1) == 0) ||
             (s[i] == 'R' && ((dp + i) & 1) == 1)) {
      if (len > 1) {
        dp++;
        ry += len;
        len = 0;
        continue;
      } else if (len == 1) {
        l1++;
        len = 0;
      }
      ry++;
    }
    i++;
  }
  if (len > 1) {
    ry += len;
    dp++;
    len = 0;
  }
  if (((n + dp) & 1) == 1) {
    dp++;
    if (len == 1) ry++;
  } else if (len == 1)
    l1++;
  while (l1 > 0 && dp + n >= ry * 2) {
    ry++;
    l1--;
    dp += 2;
  }
  res = max(res, (double)ry / (n + dp));
  return res;
}
int main() {
  scanf("%s", s1);
  n = strlen(s1);
  int p = 0;
  memset(s, 0, sizeof(s));
  s[p++] = s1[0];
  for (int i = 1; i < n; i++) {
    if (s1[i] == s1[i - 1] && s1[i] != 'X') s[p++] = 'X';
    s[p++] = s1[i];
  }
  double res = 0;
  n = strlen(s);
  if (s[0] == s[n - 1] && s[0] != 'X') {
    s[n++] = 'X';
    double res1 = calc(s);
    for (int i = n - 1; i > 0; i--) s[i] = s[i - 1];
    s[0] = 'X';
    double res2 = calc(s);
    res = max(res1, res2);
  } else
    res = calc(s);
  res = res * 100;
  res = floor(res * 1e6) / 1e6;
  printf("%.6lf\n", res);
  return 0;
}
