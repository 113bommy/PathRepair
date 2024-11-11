#include <bits/stdc++.h>
using namespace std;
const int N = 510;
char data[N][N];
int n, m, k;
bool a[N][N];
int s[N][N];
int go[5][2] = {0, 0, -1, 0, 0, 1, 1, 0, 0, -1};
bool judge(int x, int y) {
  for (int i = 0; i < 5; i++)
    if (data[x + go[i][0]][y + go[i][1]] != '1') return 0;
  return 1;
}
long long cal(int x1, int y1, int x2, int y2) {
  return s[x2][y2] - s[x1 - 1][y1] - s[x1][y1 - 1] + s[x1 - 1][y1 - 1];
}
int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    int i, j, p;
    for (i = 1; i <= n; i++) scanf("%s", data[i] + 1);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
        a[i][j] = judge(i, j);
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
      }
    long long ans = 0;
    for (i = 1; i <= n; i++) {
      for (j = i + 1; j <= n; j++) {
        if (cal(i + 1, 2, j - 1, m - 1) < k) continue;
        long long l = 1;
        for (p = 3; p <= m; p++) {
          while (l <= k && cal(i + 1, l + 2, j - 1, p - 1) >= k) l++;
          if (cal(i + 1, l + 1, j - 1, p - 1) >= k) ans += l;
        }
      }
    }
    printf("%d\n", ans);
  }
}
