#include <bits/stdc++.h>
using namespace std;
int n, f[1000010];
char s[1000010], t[1000010];
int main() {
  scanf("%d", &n);
  n--;
  scanf("%s", s);
  scanf("%s", t);
  reverse(s, s + n);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N' or s[i] == 'S')
      s[i] = s[i] == 'N' ? 'S' : 'N';
    else
      s[i] = s[i] == 'W' ? 'E' : 'W';
  }
  int k = -1;
  f[0] = -1;
  for (int i = 1; i <= n - 1; i++) {
    while (k >= 0 && s[i] != s[k + 1]) k = f[k];
    if (s[i] == s[k + 1]) k++;
    f[i] = k;
  }
  k = -1;
  for (int i = 0; i < n; i++) {
    while (k >= 0 && t[i] != s[k + 1]) k = f[k];
    if (t[i] == s[k + 1]) k++;
  }
  if (k != -1)
    puts("NO");
  else
    puts("YES");
  return 0;
}
