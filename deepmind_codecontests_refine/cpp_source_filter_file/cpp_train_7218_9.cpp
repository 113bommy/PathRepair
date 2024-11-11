#include <bits/stdc++.h>
using namespace std;
char ans[11111111];
char str[11111111];
int pos = 0, ansl = 0;
bool func() {
  if (str[pos] != 'i' && str[pos] != 'p') return false;
  if (str[pos] == 'i') {
    for (int i = 0; i < 3; i++) ans[ansl++] = str[pos++];
    if (str[pos] == ' ') pos++;
  } else {
    for (int i = 0; i < 4; i++) ans[ansl++] = str[pos++];
    ans[ansl++] = '<';
    if (str[pos] == ' ') pos++;
    if (!func()) return false;
    ans[ansl++] = ',';
    if (!func()) return false;
    ans[ansl++] = '>';
    if (str[pos] == ' ') pos++;
  }
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  getchar();
  gets(str);
  if (!func() && str[pos] != 0)
    puts("Error occurred");
  else
    puts(ans);
  return 0;
}
