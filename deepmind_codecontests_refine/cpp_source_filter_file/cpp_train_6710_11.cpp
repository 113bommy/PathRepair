#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0, i = 0;
  scanf("%d\n", &n);
  char c[101];
  gets(c);
  string s(c);
  for (int j = 0; j < n; j++)
    if (s[i] == 0)
      break;
    else if (j + 1 == n) {
      printf("%d", n);
      return 0;
    }
  while (i < n && s[i] != '0') {
    ans++;
    i++;
  }
  printf("%d", ans + 1);
  return 0;
}
