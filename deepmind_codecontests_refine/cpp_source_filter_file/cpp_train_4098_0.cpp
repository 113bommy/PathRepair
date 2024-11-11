#include <bits/stdc++.h>
using namespace std;
char c[200];
int cn, ci;
bool flag = true;
int main() {
  scanf("%s", c);
  cn = strlen(c);
  int cnt, _cnt;
  cnt = 0;
  for (; ci < cn && c[ci] != '@'; cnt++, ci++)
    if ('a' <= c[ci] && c[ci] <= 'z' || 'A' <= c[ci] && c[ci] <= 'Z' ||
        '0' <= c[ci] && c[ci] <= '9' || c[ci] == '_')
      ;
    else
      flag = false;
  if (cnt < 1 || cnt > 16) flag = false;
  cnt = _cnt = 0;
  ci++;
  for (; ci < cn && c[ci] != '/'; cnt++, _cnt++, ci++) {
    if (c[ci] == '.') {
      if (cnt < 1 || cnt > 16) flag = false;
      cnt = 0;
    } else if ('a' <= c[ci] && c[ci] <= 'z' || 'A' <= c[ci] && c[ci] <= 'Z' ||
               '0' <= c[ci] && c[ci] <= '9' || c[ci] == '_')
      ;
    else
      flag = false;
  }
  if (cnt < 1 || cnt > 16) flag = false;
  if (_cnt < 1 || _cnt > 32) flag = false;
  if (ci == cn) goto f1;
  cnt = _cnt = 0;
  ci++;
  for (; ci < cn; cnt++, ci++) {
    if (c[ci] == '/') {
      if (cnt < 1 || cnt > 16) flag = false;
      cnt = 0;
    } else if ('a' <= c[ci] && c[ci] <= 'z' || 'A' <= c[ci] && c[ci] <= 'Z' ||
               '0' <= c[ci] && c[ci] <= '9' || c[ci] == '_')
      ;
    else
      flag = false;
  }
  if (cnt < 1 || cnt > 16) flag = false;
f1:;
  if (flag)
    puts("YES");
  else
    puts("NO");
}
