#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : (-x);
}
template <class T>
T sqr(T x) {
  return x * x;
}
const int maxn = 5010;
char a[maxn][maxn];
int st[maxn];
int ss = 0;
int u[maxn];
int n;
void dfs(int x) {
  u[x] = 1;
  st[ss++] = x;
  for (int i = 0; i < n; ++i)
    if (a[x][i] == '1') {
      if (u[i] == 2) continue;
      if (u[i] == 0)
        dfs(i);
      else {
        while (a[i][st[ss - 2]] != '1') --ss;
        printf("%d %d %d\n", i + 1, st[ss - 1] + 1, st[ss - 2] + 1);
        exit(0);
      }
    }
  u[x] = 2;
  --ss;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%s", a[i]);
  memset(u, 0, sizeof(u));
  for (int i = 0; i < n; ++i)
    if (!u[i]) {
      ss = 0;
      dfs(i);
    }
  printf("-1\n");
  return 0;
}
