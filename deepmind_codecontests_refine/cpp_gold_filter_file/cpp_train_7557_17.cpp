#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
char str[maxn];
char msc[maxn];
int vis[26];
int main() {
  memset(vis, 0, sizeof(vis));
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; i++) vis[str[i] - 'a'] = 1;
  scanf("%s", str);
  len = strlen(str);
  int pos = -1;
  for (int i = 0; i < len; i++)
    if (str[i] == '*') pos = i;
  int m;
  scanf("%d", &m);
  while (m--) {
    scanf("%s", msc);
    int len_m = strlen(msc);
    int flag = 1;
    if (pos == -1) {
      if (len_m != len)
        flag = 0;
      else {
        for (int i = 0; i < len; i++) {
          if (str[i] != '?') {
            if (str[i] != msc[i]) {
              flag = 0;
              break;
            }
          } else {
            if (vis[msc[i] - 'a'] == 0) {
              flag = 0;
              break;
            }
          }
        }
      }
    } else {
      int l, r;
      for (int i = 0; i < pos; i++) {
        if (str[i] != '?') {
          if (str[i] != msc[i]) {
            flag = 0;
            break;
          }
        } else {
          if (vis[msc[i] - 'a'] == 0) {
            flag = 0;
            break;
          }
        }
      }
      l = pos;
      r = len_m - 1;
      for (int i = len - 1, j = len_m - 1; i > pos; i--, j--) {
        if (str[i] != '?') {
          if (str[i] != msc[j]) {
            flag = 0;
            break;
          }
        } else {
          if (vis[msc[j] - 'a'] == 0) {
            flag = 0;
            break;
          }
        }
        r = j - 1;
      }
      if (r + 1 < l) flag = 0;
      for (int i = l; i <= r; i++)
        if (vis[msc[i] - 'a'] == 1) flag = 0;
    }
    if (flag == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
