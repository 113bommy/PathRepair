#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
char a[1605][1605];
int u[1605][1605];
char b[1605][1605];
int c[1605][1605];
vector<int> res;
int nn, mm, mnx, mny, mxx, mxy;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
void dfs1(int x, int y) {
  int i, xx, yy;
  if (x < mnx) {
    mnx = x;
  }
  if (x > mxx) {
    mxx = x;
  }
  if (y < mny) {
    mny = y;
  }
  if (y > mxy) {
    mxy = y;
  }
  u[x][y] = 1;
  for (i = 0; i < 4; i++) {
    xx = x + dx[i];
    yy = y + dy[i];
    if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
      if (a[xx][yy] == 1 && u[xx][yy] == 0) {
        dfs1(xx, yy);
      }
    }
  }
}
void dfs2(int x, int y) {
  b[x - mnx][y - mny] = 1;
  u[x][y] = 2;
  int xx, yy, i;
  for (i = 0; i < 4; i++) {
    xx = x + dx[i];
    yy = y + dy[i];
    if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
      if (a[xx][yy] == 1 && u[xx][yy] == 1) {
        dfs2(xx, yy);
      }
    }
  }
}
void clr(int n, int m) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      b[i][j] = c[i][j] = 0;
    }
  }
}
void dfs3(int x, int y) {
  b[x][y] = 0;
  int xx, yy, i;
  for (i = 0; i < 4; i++) {
    xx = x + dx[i];
    yy = y + dy[i];
    if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
      if (b[xx][yy] == 1) {
        dfs3(xx, yy);
      }
    }
  }
}
int get() {
  int i, j, t, x, y, res;
  for (i = 0; i < nn; i++) {
    for (j = 0; j < mm; j++) {
      for (x = i - 2; x <= i + 2; x++) {
        for (y = j - 2; y <= j + 2; y++) {
          if (x >= 0 && x < nn && y >= 0 && y < mm) {
            if (b[x][y] == 1) {
              c[i][j]++;
            }
          }
        }
      }
    }
  }
  for (i = 0; i < nn; i++) {
    for (j = 0; j < mm; j++) {
      if (c[i][j] > 10) {
        b[i][j] = 0;
      }
    }
  }
  res = 0;
  for (i = 0; i < nn; i++) {
    for (j = 0; j < mm; j++) {
      if (b[i][j] == 1) {
        res++;
        dfs3(i, j);
      }
    }
  }
  return res;
}
int i, j, k, x, y, z, t;
int main() {
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &x);
      a[i][j] = x;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] == 1 && u[i][j] == 0) {
        mnx = mny = 1605;
        mxx = mxy = 0;
        dfs1(i, j);
        nn = mxx - mnx + 1;
        mm = mxy - mny + 1;
        clr(nn, mm);
        dfs2(i, j);
        if (nn * mm > 0) {
          t = get();
          res.push_back(t);
        }
      }
    }
  }
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (i = 0; i < res.size(); i++) {
    cout << res[i] << ' ';
  }
  cout << endl;
  return 0;
}
