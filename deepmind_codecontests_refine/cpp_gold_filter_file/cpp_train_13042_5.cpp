#include <bits/stdc++.h>
using namespace std;
int T, n, m, a[102][102], k;
char s[102];
struct node {
  int x1, y1, x2, y2, x3, y3;
} op[10002];
bool vis[2][2];
vector<int> v;
int count(int i, int j) {
  int res = 0;
  for (int t1 = 0; t1 <= 1; ++t1) {
    for (int t2 = 0; t2 <= 1; ++t2) {
      if (a[t1 + i][t2 + j] == 1) {
        res++;
      }
    }
  }
  return res;
}
void solve1(int ti, int tj) {
  int i, j;
  for (int t1 = ti; t1 <= ti + 1; ++t1) {
    for (int t2 = tj; t2 <= tj + 1; ++t2) {
      if (a[t1][t2] == 1) {
        i = t1;
        j = t2;
        break;
      }
    }
  }
  if (i == ti && j == tj) {
    op[++k] = {i, j, i + 1, j, i + 1, j + 1};
    op[++k] = {i, j, i + 1, j, i, j + 1};
    op[++k] = {i, j + 1, i + 1, j + 1, i, j};
  } else if (i == ti + 1 && j == tj) {
    op[++k] = {i, j, i - 1, j, i - 1, j + 1};
    op[++k] = {i, j, i - 1, j, i, j + 1};
    op[++k] = {i, j, i - 1, j + 1, i, j + 1};
  } else if (j == tj + 1 && i == ti) {
    op[++k] = {i, j, i, j - 1, i + 1, j};
    op[++k] = {i, j, i + 1, j, i + 1, j - 1};
    op[++k] = {i, j - 1, i + 1, j - 1, i, j};
  } else {
    op[++k] = {i, j, i, j - 1, i - 1, j};
    op[++k] = {i, j, i, j - 1, i - 1, j - 1};
    op[++k] = {i - 1, j - 1, i - 1, j, i, j};
  }
}
void solve3(int i, int j) {
  ++k;
  for (int ti = i; ti <= i + 1; ++ti) {
    for (int tj = j; tj <= j + 1; ++tj) {
      if (a[ti][tj] == 1) {
        v.push_back(ti);
        v.push_back(tj);
      }
    }
  }
  op[k].x1 = v[0];
  op[k].y1 = v[1];
  op[k].x2 = v[2];
  op[k].y2 = v[3];
  op[k].x3 = v[4];
  op[k].y3 = v[5];
  v.clear();
}
void solve2(int i, int j) {
  ++k;
  for (int t1 = 0; t1 <= 1; ++t1) {
    for (int t2 = 0; t2 <= 1; ++t2) {
      if (a[t1 + i][t2 + j] == 0) {
        v.push_back(t1 + i);
        v.push_back(t2 + j);
        vis[t1][t2] = 1;
        a[t1 + i][t2 + j] ^= 1;
      }
    }
  }
  bool f = 1;
  for (int t1 = 0; t1 <= 1; ++t1) {
    if (f == 0) break;
    for (int t2 = 0; t2 <= 1; ++t2) {
      if (!vis[t1][t2]) {
        v.push_back(t1 + i);
        v.push_back(t2 + j);
        a[t1 + i][t2 + j] ^= 1;
        f = 0;
        break;
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  op[k].x1 = v[0];
  op[k].y1 = v[1];
  op[k].x2 = v[2];
  op[k].y2 = v[3];
  op[k].x3 = v[4];
  op[k].y3 = v[5];
  v.clear();
  solve3(i, j);
}
void solve4(int i, int j) {
  op[++k] = {i + 1, j, i + 1, j + 1, i, j + 1};
  a[i + 1][j] ^= 1;
  a[i + 1][j + 1] ^= 1;
  a[i][j + 1] ^= 1;
  solve1(i, j);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    k = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s + 1);
      for (int j = 1; j <= m; ++j) {
        a[i][j] = s[j] - '0';
      }
    }
    if (n & 1) {
      for (int j = 1; j <= m; ++j) {
        if (a[n][j] == 1) {
          if (j == 1) {
            op[++k] = {n, j, n - 1, j, n - 1, j + 1};
            a[n][j] ^= 1;
            a[n - 1][j] ^= 1;
            a[n - 1][j + 1] ^= 1;
          } else {
            op[++k] = {n, j, n - 1, j, n - 1, j - 1};
            a[n][j] ^= 1;
            a[n - 1][j] ^= 1;
            a[n - 1][j - 1] ^= 1;
          }
        }
      }
      --n;
    }
    if (m & 1) {
      for (int i = 1; i <= n; ++i) {
        if (a[i][m] == 1) {
          if (i == 1) {
            op[++k] = {i, m, i, m - 1, i + 1, m - 1};
            a[i][m] ^= 1;
            a[i][m - 1] ^= 1;
            a[i + 1][m - 1] ^= 1;
          } else {
            op[++k] = {i, m, i, m - 1, i - 1, m - 1};
            a[i][m] ^= 1;
            a[i][m - 1] ^= 1;
            a[i - 1][m - 1] ^= 1;
          }
        }
      }
      --m;
    }
    for (int i = 1; i <= n; i += 2) {
      for (int j = 1; j <= m; j += 2) {
        int cnt = count(i, j);
        if (cnt == 0)
          continue;
        else if (cnt == 1)
          solve1(i, j);
        else if (cnt == 2)
          solve2(i, j);
        else if (cnt == 3)
          solve3(i, j);
        else
          solve4(i, j);
      }
    }
    printf("%d\n", k);
    for (int i = 1; i <= k; ++i) {
      printf("%d %d %d %d %d %d\n", op[i].x1, op[i].y1, op[i].x2, op[i].y2,
             op[i].x3, op[i].y3);
    }
  }
  return 0;
}
