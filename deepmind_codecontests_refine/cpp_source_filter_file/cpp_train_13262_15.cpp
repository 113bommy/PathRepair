#include <bits/stdc++.h>
using namespace std;
char s[201];
int a[10], b[10];
int main() {
  int n, i, ret = INT_MAX;
  scanf("%s", s);
  n = strlen(s);
  for (i = 0; i < n; i++) a[s[i] - '0']++;
  a[2] += a[5];
  a[6] += a[9];
  a[5] = a[6] = 0;
  scanf("%s", s);
  n = strlen(s);
  for (i = 0; i < n; i++) b[s[i] - '0']++;
  b[2] += b[5];
  b[6] += b[9];
  b[5] = b[6] = 0;
  for (i = 0; i < 10; i++)
    if (a[i]) ret = min(ret, b[i] / a[i]);
  printf("%d", ret);
  return 0;
}
