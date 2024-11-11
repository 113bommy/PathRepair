#include <bits/stdc++.h>
using namespace std;
int len, dep[105], height[105], emp[105], tot, from[105], to[105];
char buf[105], mp[605][605];
int main(void) {
  int cur = 0, mx = 0;
  scanf("%d%s", &len, buf + 1);
  dep[1] = 1;
  for (int i = 1; i <= len; ++i) {
    if (buf[i] == '[')
      ++cur, dep[i] = cur, mx = max(mx, cur);
    else {
      dep[i] = cur, --cur;
      if (buf[i - 1] == '[') emp[i - 1] = true;
    }
  }
  tot = mx * 2 + 1;
  for (int i = 1; i <= len; ++i) from[i] = dep[i], to[i] = tot - from[i] + 1;
  for (int i = 1; i <= len; ++i) {
    if (buf[i] == '[') {
      mp[from[i]][i + cur] = mp[to[i]][i + cur] = '+',
                      mp[to[i]][i + cur + 1] = mp[from[i]][i + cur + 1] = '-';
      for (int j = from[i] + 1; j < to[i]; ++j) mp[j][i + cur] = '|';
      if (emp[i]) cur += 3;
    } else {
      mp[from[i]][i + cur] = mp[to[i]][i + cur] = '+',
                      mp[to[i]][i + cur - 1] = mp[from[i]][i + cur - 1] = '-';
      for (int j = from[i] + 1; j < to[i]; ++j) mp[j][i + cur] = '|';
    }
  }
  int end = len + cur;
  for (int i = 1; i <= tot; ++i) {
    for (int j = 1; j <= end; ++j) putchar(mp[i][j] == '\0' ? ' ' : mp[i][j]);
    puts("");
  }
}
