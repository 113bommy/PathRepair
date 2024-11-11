#include <bits/stdc++.h>
using namespace std;
struct node {
  int t, i;
  friend bool operator<(const node &a, const node &b) { return a.t < b.t; }
} res[100010];
int total[100010];
int number[100010], x[100010], y[100010], ans[100010], n;
int tt[100010][100];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
  for (int i = 1; i <= n; i++) {
    if (y[i] == 0)
      res[i].t = -1;
    else
      res[i].t = i - y[i] - 1;
    res[i].i = i;
  }
  sort(res + 1, res + n + 1);
  int head = 1;
  while (res[head].t <= 0) head++;
  for (int i = 1; i <= n; i++) {
    int tmp = x[i];
    int length = 0, p = (int)sqrt(tmp);
    for (int j = 1; j <= p; j++)
      if (tmp % j == 0) {
        number[++length] = j;
        if (j * j != tmp) number[++length] = tmp / j;
      }
    ans[i] += length;
    if (y[i] != 0)
      for (int j = 1; j <= length; j++) {
        if (total[number[j]]) {
          ans[i]--;
          if (tt[i][j] < total[number[j]] && tt[i][j] != 0) ans[i]--;
        }
        total[number[j]]++;
      }
    else
      for (int j = 1; j <= length; j++) total[number[j]]++;
    while (res[head].t == i && head <= n) {
      tmp = x[res[head].i];
      length = 0, p = (int)sqrt(tmp);
      for (int j = 1; j <= p; j++)
        if (tmp % j == 0) {
          number[++length] = j;
          if (j * j != tmp) number[++length] = tmp / j;
        }
      for (int j = 1; j <= length; j++)
        if (total[number[j]])
          ans[res[head].i]++, tt[res[head].i][j] = total[number[j]];
      head++;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
