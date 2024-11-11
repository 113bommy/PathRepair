#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int Maxn = 1000 + 10;
int pre[Maxn * 2], Hash[Maxn * 2], in[Maxn * 2], u[Maxn * Maxn * 2];
vector<int> G[Maxn * 2];
char table[Maxn][Maxn];
int Find(int x) {
  if (pre[x] != x) pre[x] = Find(pre[x]);
  return pre[x];
}
void union_(int x, int y) {
  int xx = Find(x);
  int yy = Find(y);
  pre[xx] = yy;
}
int main(void) {
  int n, m;
  char op;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n + m; ++i) pre[i] = i;
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= n; ++i) scanf("%s", table[i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (table[i][j] == '=') union_(i, j + n);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x = Find(i), y = Find(j + n);
      u[cnt++] = x;
      u[cnt++] = y;
      if (table[i][j] == '=') continue;
      if (x == y) {
        printf("NO\n");
        return 0;
      }
      if (table[i][j] == '>') {
        G[y].push_back(x);
        in[x]++;
      } else if (table[i][j] == '<') {
        G[x].push_back(y);
        in[y]++;
      }
    }
  }
  sort(u, u + cnt);
  cnt = unique(u, u + cnt) - u;
  int p, num = 1, ct = cnt;
  while (ct) {
    p = -1;
    for (int j = 0; j < cnt; ++j) {
      if (in[u[j]] == 0) {
        p = u[j];
        in[p] = -1;
        ct--;
        Hash[p] = num;
      }
    }
    num++;
    if (p == -1 && ct != 0) {
      printf("NO\n");
      return 0;
    }
    for (int i = 0; i < cnt; ++i) {
      p = u[i];
      if (in[p] == -1) {
        in[p] = -2;
        for (int j = 0; j < G[p].size(); ++j) in[G[p][j]]--;
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; ++i) printf("%d ", Hash[pre[i]]);
  printf("\n");
  for (int i = n + 1; i <= n + m; ++i) printf("%d ", Hash[pre[i]]);
  printf("\n");
  return 0;
}
