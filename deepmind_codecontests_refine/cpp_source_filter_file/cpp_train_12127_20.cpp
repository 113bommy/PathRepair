#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int mol = 1e9 + 7;
char p[N + 5];
bool vis[N + 5];
int y[N + 5];
int q[N + 5];
int f[N + 5];
int nxt[N + 5];
void get_nxt(char p[], int l) {
  int pos = 0;
  nxt[1] = 0;
  for (int i = 2; i <= l; i++) {
    while (pos > 0 && p[pos + 1] != p[i]) pos = nxt[pos];
    if (p[pos + 1] == p[i]) pos += 1;
    nxt[i] = pos;
  }
}
int main() {
  int n, m;
  while (~scanf("%d %d", &n, &m)) {
    scanf("%s", p + 1);
    int l = strlen(p + 1);
    get_nxt(p, l);
    int flag = 1;
    for (int i = 1; i <= m; i++) scanf("%d", &y[i]);
    long long s = y[1];
    long long e;
    e = s + l - 1;
    int i = l;
    while (i) {
      int x = l - nxt[i];
      f[l - nxt[i]] = 1;
      i = nxt[i];
    }
    for (i = 2; i <= m; i++)
      if ((y[i] - y[i - 1] > l) || (f[y[i] - y[i - 1]]))
        continue;
      else
        flag = 0;
    if (flag == 0)
      printf("0\n");
    else {
      long long ans = 1;
      for (int i = 1; i <= m; i++) q[y[i]] = 1;
      int j = 0;
      for (int i = 1; i <= n; i++) {
        if (q[i] == 1)
          j = l;
        else if (q[i] == 0)
          j--;
        if (j == 0) ans = ans * 26 % mol;
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
