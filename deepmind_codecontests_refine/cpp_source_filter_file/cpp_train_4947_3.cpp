#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch[1000100];
  scanf("%s", ch);
  string s = ch;
  scanf("%s", ch);
  string v = ch, h = "";
  int l1 = s.size(), l2 = v.size(), chk = 0;
  for (int i = 0; abs(l1 - l2) > i; i++) h += '0';
  if (l1 > l2)
    v = h + v;
  else
    s = h + s;
  l1 = max(l1, l2);
  for (int i = 0; l1 > i; i++) {
    if (s[i] > v[i]) {
      chk = 1;
      break;
    } else if (s[i] < v[i]) {
      chk = -1;
      break;
    }
  }
  if (chk == 0)
    printf("=\n");
  else
    printf(chk == 1 ? "<\n" : ">\n");
  return 0;
}
