#include <bits/stdc++.h>
using namespace std;
char s[10000100];
int z[10000100], f[10000100];
int main(void) {
  gets(s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    s[i + n] = s[n - i - 1];
  }
  int l = 0;
  for (int i = 1; i < n + n; i++) {
    z[i] = l + z[l] > i ? min(l + z[l] - i, z[i - l]) : 0;
    while (s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > l + z[l]) {
      l = i;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += (f[i] = (z[2 * n - i] == i) ? f[i / 2] + 1 : 0);
  }
  printf("%d\n", res);
  return 0;
}
