#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main() {
  int k, i, odd;
  int a[30];
  scanf("%s", s);
  k = strlen(s);
  memset(a, 0, sizeof(a));
  for (i = 0; i < k; i++) a[s[i] - 'a']++;
  odd = 0;
  for (i = 0; i < 26; i++) {
    if ((a[i] % 2) == 1) odd++;
  }
  if ((odd % 2) == 1 || odd == 0)
    printf("First\n");
  else
    printf("Second\n");
  return 0;
}
