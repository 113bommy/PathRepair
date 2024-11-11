#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m1, m2, t, p[2000005][2], f[2000005][2], x1[2000005], x2[2000005],
    pre[2000005][2], all[2000005], tot;
vector<int> ans1;
vector<pair<int, int> > ans2;
int main() {
  n = read();
  m1 = read();
  m2 = read();
  t = read();
  for (int i = 1; i <= m1; i++)
    x1[i] = read(), all[++tot] = x1[i], all[++tot] = x1[i] + 1;
  for (int i = 1; i <= m2; i++)
    x2[i] = read(), all[++tot] = x2[i], all[++tot] = x2[i] + 1;
  all[++tot] = 0;
  all[++tot] = n + 1;
  sort(all + 1, all + 1 + tot);
  tot = unique(all + 1, all + 1 + tot) - all - 1;
  for (int i = 1; i <= m1; i++)
    p[lower_bound(all + 1, all + 1 + tot, x1[i]) - all][0] = 1;
  for (int i = 1; i <= m2; i++)
    p[lower_bound(all + 1, all + 1 + tot, x2[i]) - all][1] = 1;
  memset(f, -1, sizeof(f));
  f[0][1] = f[1][1] = 0;
  pre[1][1] = 0;
  for (int i = 1; i <= tot; i++) {
    for (int j = 0; j < 2; j++) {
      if (f[i][j] != -1 && !p[i][j ^ 1] && f[i][j ^ 1] < min(t, f[i][j])) {
        f[i][j ^ 1] = min(t, f[i][j]);
        pre[i][j ^ 1] = 0;
      }
    }
    for (int j = 0; j < 2; j++) {
      if (f[i][j] != -1 &&
          f[i][j] + all[i + 1] - all[i] - 1 >= t * p[i + 1][j] &&
          f[i][j] + all[i + 1] - all[i] - t * p[i + 1][j] >= f[i + 1][j]) {
        f[i + 1][j] = f[i][j] + all[i + 1] - all[i] - t * p[i + 1][j];
        pre[i + 1][j] = 1;
      }
    }
  }
  int ansx = tot, ansy;
  if (f[tot][0] > f[tot][1])
    ansy = 0;
  else
    ansy = 1;
  if (f[ansx][ansy] < 0) return puts("No"), 0;
  int lst = 1e9;
  for (; ansx != 1 || ansy;) {
    if (pre[ansx][ansy] == 0)
      ans1.push_back(all[ansx]), ansy ^= 1;
    else {
      if (p[ansx][ansy]) {
        lst = min(lst, all[ansx] - 1);
        ans2.push_back(make_pair(lst, ansy));
      }
      ansx--;
    }
  }
  puts("Yes");
  printf("%d\n", ans1.size());
  for (int i = ans1.size() - 1; i >= 0; i--) printf("%d ", ans1[i]);
  puts("");
  printf("%d\n", ans2.size());
  for (int i = ans2.size() - 1; i >= 0; i--)
    printf("%d %d\n", ans2[i].first, ans2[i].second + 1);
  return 0;
}
