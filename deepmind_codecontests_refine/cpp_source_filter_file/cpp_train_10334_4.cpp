#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[4][11111];
bool vow[555];
bool c(int id1, int id2) {
  int len1 = strlen(s[id1]), len2 = strlen(s[id2]);
  int _k = k;
  for (int i = 1; _k && i <= min(len1, len2); i++) {
    if (s[id1][len1 - i] != s[id2][len2 - i]) return false;
    if (vow[s[id1][len1 - i]]) _k--;
  }
  return true;
}
void upd(int &x, int y) {
  if (x == -2 || y == -1)
    x = y;
  else if (x != y) {
    if (x == 3)
      x = y;
    else if (y != 3 && x != 3 && x != y)
      x = -1;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  int res = -2;
  vow['a'] = vow['e'] = vow['i'] = vow['o'] = vow['u'] = true;
  for (int i = 0; i < n && res != -1; i++) {
    for (int j = 0; j < 4; j++) scanf("%s", s[j]);
    bool chk[3];
    chk[0] = c(0, 1) && c(2, 3);
    chk[1] = c(0, 2) && c(1, 3);
    chk[2] = c(0, 3) && c(1, 2);
    if (chk[0] && chk[1] && chk[2])
      upd(res, 3);
    else {
      int x = -1;
      for (int j = 0; j < 3; j++)
        if (chk[j]) x = j;
      upd(res, x);
    }
  }
  if (res == -1)
    puts("NO");
  else if (res == 3)
    puts("aaaa");
  else if (res == 0)
    puts("aabb");
  else if (res == 1)
    puts("abab");
  else
    puts("abba");
  return 0;
}
