#include <bits/stdc++.h>
using namespace std;
int L, R, P, aa[25] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                       43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97},
             tot, lim, a[3000010];
int inf = 1e9, f[300010];
bool vis[300010];
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
void dfs(int step, int x) {
  if (step == 25) {
    a[++tot] = x;
    return;
  }
  dfs(step + 1, x);
  for (int i = 1;; i++) {
    if ((long long)x * aa[step] > lim) return;
    x *= aa[step];
    dfs(step + 1, x);
  }
}
int main() {
  read(L);
  read(R);
  read(P);
  lim = R;
  dfs(0, 1);
  sort(a + 1, a + tot + 1);
  for (int i = 2; i <= tot; i++) f[i] = inf;
  for (int i = 2; i <= 100; i++) {
    int now = 1;
    for (int j = 1; j <= tot; j++)
      if (f[j] + i <= P && (long long)a[j] * i <= R) {
        int tmp = a[j] * i;
        for (; now <= tot && tmp > a[now]; now++)
          ;
        f[now] = min(f[now], f[j] + 1);
      } else if ((long long)a[j] * i > R)
        break;
    for (int j = 1; j <= tot; j++)
      if (f[j] + i <= P) vis[j] = 1;
  }
  int cnt = 0;
  for (int i = 1; i <= tot; i++)
    if (a[i] >= L && a[i] <= R && vis[i]) cnt++;
  printf("%d\n", cnt);
  return 0;
}
