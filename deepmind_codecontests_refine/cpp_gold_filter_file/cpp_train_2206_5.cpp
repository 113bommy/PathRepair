#include <bits/stdc++.h>
using namespace std;
int n;
int h[30], p[30][110], lst[30];
int sz[30];
char s[110];
char t[110];
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    memset(p, 0, sizeof(p));
    memset(lst, 0, sizeof(lst));
    memset(sz, 0, sizeof(sz));
    scanf("%d", &n);
    scanf("%s%s", s, t);
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      p[c][lst[c]++] = i;
    }
    for (int i = 0; i < n; i++) {
      sz[t[i] - 'a']++;
    }
    int flag = 1;
    for (int i = 0; i < 26; i++) {
      if (sz[i] != lst[i]) flag = 0;
    }
    if (!flag)
      printf("-1\n");
    else {
      int ans = 500;
      for (int i = 0; i < n; i++) {
        int now = i;
        int R = -1;
        memset(h, 0, sizeof(h));
        while (true) {
          int c = t[now] - 'a';
          while (h[c] < lst[c] && p[c][h[c]] <= R) h[c]++;
          if (h[c] >= lst[c]) break;
          R = p[c][h[c]];
          now++;
          if (now == n) break;
        }
        ans = min(ans, n - now + i);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
