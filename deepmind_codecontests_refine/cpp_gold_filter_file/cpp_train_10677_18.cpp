#include <bits/stdc++.h>
using namespace std;
int need[3005], now[3005];
int n, m;
struct note {
  int x, id;
} a[3005];
bool cmp(note i, note j) { return i.x > j.x || i.x == j.x && i.id > j.id; }
int ans[3005][3005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", &need[i]), need[i] -= (n - 1);
  if (need[m] < 0)
    need[m + 1] = need[m];
  else
    need[m + 1] = 0;
  for (int i = 1; i <= m; i++) {
    if (n - i < need[i] - now[i]) {
      puts("no");
      return 0;
    }
    for (int j = i + 1; j <= m; j++) {
      a[j - i].id = j;
      a[j - i].x = now[j] - need[j];
    }
    for (int j = m + 1; j <= n; j++) {
      a[j - i].id = j;
      a[j - i].x = max(0, now[j] - need[j]);
    }
    sort(a + 1, a + n - i + 1, cmp);
    for (int j = 1; j <= need[i] - now[i]; j++) {
      int id = a[j].id;
      now[id]--;
      ans[i][id] = 1;
      ans[id][i] = -1;
    }
    now[i] = need[i];
  }
  for (int i = m + 1; i <= n; i++)
    if (now[i] > need[i]) {
      puts("no");
      return 0;
    }
  puts("yes");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (ans[i][j] == 1)
        putchar('W');
      else if (i == j)
        putchar('X');
      else if (ans[i][j] == 0)
        putchar('D');
      else
        putchar('L');
    }
    puts("");
  }
  return 0;
}
