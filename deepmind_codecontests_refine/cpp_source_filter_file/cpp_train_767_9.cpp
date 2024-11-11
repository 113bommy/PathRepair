#include <bits/stdc++.h>
using namespace std;
const int maxn = 3105;
int r, c;
int n;
bool mat[maxn][maxn * 2] = {0};
int fa[maxn * maxn * 2] = {0};
int walk[11][2] = {0};
int Ans = 0;
int Zip(const int &x, const int &y) { return (x - 1) * c * 2 + y; }
void Unzip(const int &a, int &x, int &y) {
  y = (a - 1) % (c * 2) + 1;
  x = (a - 1) / (c * 2);
}
void Init() {
  int wt = -1;
  scanf("%d%d%d", &r, &c, &n);
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (i != 0 || j != 0) {
        ++wt;
        walk[wt][0] = i;
        walk[wt][1] = j;
      }
    }
  }
}
int Getfa(int p) {
  if (fa[p] == p) return p;
  return fa[p] = Getfa(fa[p]);
}
void Solve() {
  int x, y, s;
  int tx, ty;
  int f1[11] = {0}, f2[11] = {0};
  int fp1, fp2;
  int N = r * c * 2;
  for (int i = 1; i <= N; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    s = Zip(x, y);
    fp1 = 0, fp2 = 0;
    mat[x][y] = 1;
    mat[x][y + c] = 1;
    for (int j = 0; j < 8; ++j) {
      tx = x + walk[j][0];
      ty = y + walk[j][1];
      if (ty < 0)
        ty += 2 * c;
      else if (ty > 2 * c)
        ty -= 2 * c;
      if (mat[tx][ty] == 1 && tx > 0 && ty > 0 && tx <= r && ty <= c * 2) {
        f1[++fp1] = Getfa(Zip(tx, ty));
      }
    }
    f1[++fp1] = Zip(x, y);
    y += c;
    for (int j = 0; j < 8; ++j) {
      tx = x + walk[j][0];
      ty = y + walk[j][1];
      if (ty < 0)
        ty += 2 * c;
      else if (ty > 2 * c)
        ty -= 2 * c;
      if (mat[tx][ty] == 1 && tx > 0 && ty > 0 && tx <= r && ty <= c * 2) {
        f2[++fp2] = Getfa(Zip(tx, ty));
      }
    }
    f2[++fp2] = Zip(x, y);
    y -= c;
    bool ok = 1;
    for (int j = 1; j <= fp1; ++j) {
      for (int k = 1; k <= fp2; ++k) {
        if (f1[j] == f2[k]) {
          ok = 0;
          break;
        }
      }
      if (ok == 0) break;
    }
    if (ok == 0) {
      mat[x][y] = 0;
      mat[x][y + c] = 0;
      continue;
    } else
      ++Ans;
    mat[x][y] = 1;
    mat[x][y + c] = 1;
    int root;
    root = Zip(x, y);
    for (int j = 1; j <= fp1; ++j) fa[Getfa(f1[j])] = Getfa(root);
    root = Zip(x, y + c);
    for (int j = 1; j <= fp2; ++j) fa[Getfa(f2[j])] = Getfa(root);
  }
}
void Put() { printf("%d\n", Ans); }
int main() {
  Init();
  Solve();
  Put();
  return 0;
}
