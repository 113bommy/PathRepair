#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char tp = getchar();
  int ans = 0;
  while (tp > '9' || tp < '0') tp = getchar();
  while (tp <= '9' && tp >= '0') {
    ans = ans * 10 + tp - '0';
    tp = getchar();
  }
  return ans;
}
const int mx = 2000, s = 1, t = 2;
int n, a[11], ma[mx][mx], tot = 2, pre[35][2];
void add(int num) {
  if (num == 1) {
    int x1 = ++tot;
    ma[s][x1] = ma[x1][s] = 1;
    for (int i = 2; i <= 33; i++) {
      int l1 = x1;
      x1 = ++tot;
      ma[l1][x1] = ma[x1][l1] = 1;
    }
    ma[x1][t] = ma[t][x1] = 1;
  }
  int l1 = pre[num][0];
  int x1 = ++tot;
  ma[x1][l1] = ma[l1][x1] = 1;
  for (int i = num + 3; i <= 33; i++) {
    l1 = x1;
    x1 = ++tot;
    ma[l1][x1] = ma[x1][l1] = 1;
  }
  ma[x1][t] = ma[t][x1] = 1;
}
char ch[2] = {'N', 'Y'};
int main() {
  n = read();
  int cu = 1;
  pre[1][0] = ++tot;
  pre[1][1] = ++tot;
  ma[pre[1][0]][s] = ma[s][pre[1][0]] = 1;
  ma[pre[1][1]][s] = ma[s][pre[1][1]] = 1;
  for (int i = 2; i <= 33; i++) {
    pre[i][0] = ++tot;
    pre[i][1] = ++tot;
    ma[pre[i][0]][pre[i - 1][0]] = ma[pre[i - 1][0]][pre[i][0]] = 1;
    ma[pre[i][1]][pre[i - 1][1]] = ma[pre[i - 1][1]][pre[i][1]] = 1;
    ma[pre[i][0]][pre[i - 1][1]] = ma[pre[i - 1][1]][pre[i][0]] = 1;
    ma[pre[i][1]][pre[i - 1][0]] = ma[pre[i - 1][0]][pre[i][1]] = 1;
  }
  while (n) {
    if (n & 1) add(cu);
    n >>= 1;
    cu++;
  }
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) {
    for (int j = 1; j <= tot; j++) printf("%c", ch[ma[i][j]]);
    printf("\n");
  }
  return 0;
}
