#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 50;
char st1[30], st2[30], st[30];
int a[30], b[30], len;
int main() {
  while (~scanf("%s", st1)) {
    scanf("%s", st2);
    scanf("%s", st);
    len = strlen(st);
    for (int i = 0; i < 26; i++) {
      a[st1[i] - 'a'] = i;
      b[i] = st2[i] - 'a';
    }
    for (int i = 0; i < len; i++) {
      if (st[i] >= 'A' && st[i] <= 'Z')
        putchar(b[a[st[i] - 'A']] + 'A');
      else if (st[i] >= 'a' && st[i] <= 'z')
        putchar(b[a[st[i] - 'a']] + 'a');
      else
        putchar(st[i]);
    }
    putchar('\n');
  }
  return 0;
}
