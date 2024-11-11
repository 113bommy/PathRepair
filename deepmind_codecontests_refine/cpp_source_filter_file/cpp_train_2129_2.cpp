#include <bits/stdc++.h>
using namespace std;
struct data {
  int st[30];
  int step;
  int fac1, fac2;
};
queue<data> q;
char input[105][5];
bool flag[105];
int card[30];
int cnt;
bool ed(data d) {
  for (int i = 0; i < cnt; i++)
    for (int j = 0; j < i; j++)
      if (d.st[i] == d.st[j]) return false;
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", input[i]);
  memset(flag, 0, sizeof(flag));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (input[i][0] == input[j][0] && input[i][1] == input[j][1]) flag[i] = 1;
  cnt = 0;
  memset(card, 0, sizeof(card));
  for (int i = 0; i < n; i++)
    if (!flag[i]) {
      if (input[i][0] == 'R')
        card[cnt] = 1;
      else if (input[i][0] == 'G')
        card[cnt] = 2;
      else if (input[i][0] == 'B')
        card[cnt] = 3;
      else if (input[i][0] == 'Y')
        card[cnt] = 4;
      else if (input[i][0] == 'W')
        card[cnt] = 5;
      card[cnt] = card[cnt] * 10 + (input[i][1] - '0');
      cnt++;
    }
  data st0;
  memset(st0.st, 0, sizeof(st0.st));
  st0.fac1 = 0;
  st0.fac2 = 0;
  st0.step = 0;
  while (!q.empty()) q.pop();
  q.push(st0);
  int ans;
  while (!q.empty()) {
    data cur = q.front();
    q.pop();
    if (ed(cur)) {
      ans = cur.step;
      break;
    }
    bool qui = false;
    for (int f1 = cur.fac1 + 1; f1 < 5; f1++) {
      data next = cur;
      bool add = false;
      for (int i = 0; i < cnt; i++)
        if (card[i] / 10 == f1 && !(cur.st[i] / 10)) {
          next.st[i] = f1 * 10 + cur.st[i] % 10;
          add = true;
        }
      if (add) {
        next.fac1 = f1;
        next.step = cur.step + 1;
        q.push(next);
      }
    }
    if (qui) break;
    for (int f2 = cur.fac2 + 1; f2 < 5; f2++) {
      data next = cur;
      bool add = false;
      for (int i = 0; i < cnt; i++)
        if (card[i] % 10 == f2 && !(cur.st[i] % 10)) {
          next.st[i] = f2 + cur.st[i] / 10 * 10;
          add = true;
        }
      if (add) {
        next.fac2 = f2;
        next.step = cur.step + 1;
        q.push(next);
      }
    }
    if (qui) break;
  }
  printf("%d\n", ans);
}
