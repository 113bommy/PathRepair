#include <bits/stdc++.h>
using namespace std;
const int eps = 1e5 + 5;
const double pi = acos(-1.0);
struct s {
  char name[20];
  int re;
  int score;
} pre[eps];
bool cmp(s a, s b) {
  if (a.re == b.re) return a.score > b.score;
  return a.re < b.re;
}
int main() {
  int n, m;
  int j;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) {
      scanf("%s%d%d", pre[i].name, &pre[i].re, &pre[i].score);
    }
    sort(pre + 1, pre + 1 + n, cmp);
    int p = 1;
    for (int i = 1; i <= m; i++) {
      int cnt = 0;
      for (j = p; j <= n; j++) {
        if (pre[j].re == i) {
          cnt++;
        } else {
          break;
        }
      }
      p = j;
      int t = p - cnt;
      if (cnt == 2) {
        printf("%s %s\n", pre[t].name, pre[t + 1].name);
        continue;
      }
      if (cnt > 2 && pre[t].score == pre[t + 1].score)
        printf("?\n");
      else
        printf("%s %s\n", pre[t].name, pre[t + 1].name);
    }
  }
  return 0;
}
