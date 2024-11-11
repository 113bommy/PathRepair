#include <bits/stdc++.h>
using namespace std;
char str[4][10005];
int k;
bool isV(char ch) {
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
  return 0;
}
int get_type() {
  int len[4], i, j, st[4], x;
  for (i = 0; i < 4; i++) {
    len[i] = strlen(str[i]);
    if (len[i] < k) return 0;
    for (j = len[i] - 1, x = 0; j >= 0 && x < k; j--)
      if (isV(str[i][j])) x++;
    if (x < k) return 0;
    st[i] = j + 1;
  }
  bool r[4][4];
  int y;
  for (i = 0; i < 4; i++)
    for (j = i + 1; j < 4; j++) {
      if (len[i] - st[i] == len[j] - st[j]) {
        for (x = st[i], y = st[j]; x < len[i]; x++, y++)
          if (str[i][x] != str[j][y]) break;
        if (x == len[i])
          r[i][j] = 1;
        else
          r[i][j] = 0;
      } else
        r[i][j] = 0;
    }
  if (r[0][1] && r[1][2] && r[2][3]) return 1;
  if (r[0][1] && r[2][3]) return 2;
  if (r[0][2] && r[1][3]) return 3;
  if (r[0][3] && r[1][2]) return 4;
  return 0;
}
int main() {
  int n, i, j, t, type;
  char s[5][8] = {"NO", "aaaa", "aabb", "abab", "abba"};
  while (2 == scanf("%d%d", &n, &k)) {
    type = 1;
    for (i = 0; i < n; i++) {
      for (j = 0; j < 4; j++) scanf("%s", str[j]);
      if (type) t = get_type();
      if (i == 0)
        type = t;
      else if (type && t != 1) {
        if (type == 1)
          type = t;
        else if (type != t)
          type = 0;
      }
    }
    puts(s[type]);
  }
  return 0;
}
