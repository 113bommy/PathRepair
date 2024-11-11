#include <bits/stdc++.h>
using namespace std;
int n, m, f[300000];
char s[300000];
int main() {
  scanf("%s", s);
  n = strlen(s);
  f[m = 2 * n] = 1;
  for (int i = 0; i < n; i++)
    if (s[i] < '0')
      if (s[i] == '+' || s[i] == '-' || (i && s[i - 1] >= '0'))
        m--;
      else
        return puts("0"), 0;
    else if (s[i + 1] < '0')
      for (int j = m + n; j > m; j--) f[j - 1] = (f[j - 1] + f[j]) % 1000003;
  printf("%d\n", f[m]);
  return 0;
}
