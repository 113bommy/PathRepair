#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
char s[MAXN];
int main() {
  scanf("%s", s);
  int n = strlen(s), cnt1 = 0, pos = n;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      s[i] = '#';
      cnt1++;
    }
    if (s[i] == '2') pos = i;
  }
  for (int i = 0; i < pos; i++)
    if (s[i] != '#') putchar(s[i]);
  for (int i = 0; i < cnt1; i++) putchar('1');
  for (int i = pos; i < n; i++)
    if (s[i] != '#') putchar(s[i]);
  putchar('\n');
  return 0;
}
