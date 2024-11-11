#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double pi = 3.1415926535897932384626;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int maxn = 1e2 + 5;
int t, n, vis[maxn], ans[maxn][2];
char s1[maxn], s2[maxn];
int main() {
  t = read();
  while (t--) {
    memset(vis, 0, sizeof(vis));
    n = read();
    scanf("%s%s", s1, s2);
    for (int i = 0; i < n; ++i) {
      ++vis[s1[i] - 'a'];
      ++vis[s2[i] - 'a'];
    }
    int flag = 1;
    for (int i = 0; i < n; ++i) {
      if (vis[s1[i] - 'a'] & 1 || vis[s2[i] - 'a'] & 1) {
        flag = 0;
        break;
      }
    }
    if (!flag)
      printf("No\n");
    else {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        flag = 1;
        if (s1[i] != s2[i]) {
          for (int j = i + 1; j < n; ++j) {
            if (s1[i] == s1[j]) {
              swap(s2[i], s1[j]);
              ans[++cnt][0] = j;
              ans[cnt][1] = i;
              flag = 0;
              break;
            }
          }
          for (int j = i + 1; j < n && flag; ++j) {
            if (s1[i] == s2[j]) {
              swap(s1[j], s2[j]);
              ans[++cnt][0] = j;
              ans[cnt][1] = j;
              swap(s2[i], s1[j]);
              ans[++cnt][0] = j;
              ans[cnt][1] = i;
              break;
            }
          }
        }
      }
      printf("Yes\n%d\n", cnt);
      for (int i = 1; i <= cnt; ++i)
        printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
    }
  }
  return 0;
}
