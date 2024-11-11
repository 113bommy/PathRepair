#include <bits/stdc++.h>
using namespace std;
int n, m, cc[30];
char aa[10100], bb[10100];
bool Work(int now) {
  int i, j;
  for (; now >= 0; --now) {
    ++cc[aa[now] - 97];
    for (j = bb[now] - 96; j < 26; ++j)
      if (cc[j] > 0) break;
    if (j < 26) break;
  }
  if (now < 0) return false;
  for (j = bb[now] - 96; j < 26; ++j)
    if (cc[j] > 0) break;
  aa[now] = j + 97;
  --cc[j];
  for (i = now, j = 0; j < 26; ++j)
    for (; cc[j] > 0; --cc[j]) aa[++now] = j + 97;
  return true;
}
int main() {
  int i, j;
  scanf("%s", aa);
  n = strlen(aa);
  scanf("%s", bb);
  m = strlen(bb);
  memset(cc, 0, sizeof(cc));
  for (i = 0; i < n; ++i) ++cc[aa[i] - 97];
  bool flag = true;
  for (i = 0; i < m; ++i)
    if (i >= n) {
      if (!Work(i - 1)) {
        puts("-1");
        return 0;
      }
      flag = false;
      break;
    } else {
      if (cc[bb[i] - 97] > 0) {
        --cc[bb[i] - 97];
        aa[i] = bb[i];
      } else {
        flag = false;
        for (j = 0; j < 26; ++j)
          if (cc[j] > 0) break;
        aa[i] = j + 97;
        --cc[j];
        if (!Work(i)) {
          puts("-1");
          return 0;
        }
        break;
      }
    }
  if (flag) {
    if (n == m) {
      if (!Work(n - 1)) {
        puts("-1");
        return 0;
      }
    } else
      for (i = m, j = 0; j < 26; ++j)
        for (; cc[j] > 0; --cc[j]) aa[++i] = j + 97;
  }
  for (i = 0; i < n; ++i) printf("%c", aa[i]);
  puts("");
  return 0;
}
