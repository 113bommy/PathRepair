#include <bits/stdc++.h>
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') {
      f = -f;
    }
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 200000;
int n, son[2][maxn + 10], size[maxn * 2 + 10], f[maxn + 10][2][3],
    val[maxn + 10];
int getsize(int u) {
  return size[u] =
             ((val[u] != -1) ? 0
                             : (getsize(son[0][u]) + getsize(son[1][u]) + 1));
}
int merge(int a, int b, int k) {
  return (a == -1) ? b : ((b == -1) ? a : (((a > b) ^ k) ? a : b));
}
int search(int u, int p, int s) {
  if (!size[u]) {
    return val[u];
  }
  if (~f[u][p][s]) {
    return f[u][p][s];
  }
  int &res = f[u][p][s];
  if (size[u] == 1) {
    return res = merge(val[son[0][u]], val[son[1][u]], p ^ (s == 2));
  }
  if (s) {
    if (s == 1) {
      res = search(u, !p, 0);
    }
    if (size[u] & 1) {
      if (size[son[0][u]] & 1) {
        res = merge(res,
                    merge(search(son[0][u], p, 0),
                          search(son[1][u], !p,
                                 ((size[son[0][u]] == 1) && (s == 1)) + 1),
                          !p),
                    p);
        res = merge(res,
                    merge(search(son[1][u], p, 0),
                          search(son[0][u], !p,
                                 ((size[son[1][u]] == 1) && (s == 1)) + 1),
                          !p),
                    p);
      } else {
        if (size[son[1][u]]) {
          res = merge(
              res,
              merge(search(son[0][u], !p, 0),
                    search(son[1][u], p, ((!size[son[0][u]]) && (s == 1)) + 1),
                    !p),
              p);
        }
        if (size[son[0][u]]) {
          res = merge(
              res,
              merge(search(son[1][u], !p, 0),
                    search(son[0][u], p, ((!size[son[1][u]]) && (s == 1)) + 1),
                    !p),
              p);
        }
      }
    } else {
      res = merge(
          res,
          merge(search(son[1][u], p, 0),
                search(son[0][u], p, ((!size[son[1][u]]) && (s == 1)) + 1), p),
          p);
    }
  } else {
    if (size[u] & 1) {
      if (size[son[0][u]] & 1) {
        res = merge(search(son[0][u], p, 1), search(son[1][u], p, 1), p);
      } else {
        res = merge(search(son[0][u], p, 0), search(son[1][u], p, 0), p);
      }
    } else {
      res = merge(merge(search(son[0][u], p, 0), search(son[1][u], !p, 0), !p),
                  merge(search(son[0][u], !p, 1), search(son[1][u], p, 1), !p),
                  p);
    }
  }
  return res;
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = 0; i < n; ++i) {
      int fl = read();
      if (fl == -1) {
        son[0][i] = read();
        son[1][i] = read();
      } else {
        son[0][i] = 0;
        son[1][i] = 0;
      }
      val[i] = fl;
    }
    getsize(0);
    memset(f, -1, sizeof f);
    for (int i = 0; i < n; ++i) {
      if (size[son[1][i]] & 1) {
        std::swap(son[0][i], son[1][i]);
      }
    }
    printf("%d\n", search(0, 0, 0));
  }
  return 0;
}
