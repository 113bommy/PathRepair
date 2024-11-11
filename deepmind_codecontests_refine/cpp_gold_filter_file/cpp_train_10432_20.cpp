#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
const int UP = 2050;
char xx[MAXN][UP], yy[MAXN][UP];
int lim;
int N;
char ori[MAXN][MAXN];
vector<pair<int, int> > seq;
void flip(int x, int c, char a[][UP]) {
  x++, c++;
  for (int p = x; p > 0; p -= p & (-p)) a[c][p] ^= 1;
}
void flip(int x1, int x2, int c, char a[][UP]) {
  flip(x2, c, a);
  flip(x1 - 1, c, a);
}
char query(int x, int c, char a[][UP]) {
  x++, c++;
  char r = 0;
  for (int p = x; p < lim; p += p & (-p)) r ^= a[c][p];
  return r;
}
char query(int x, int y) {
  char r = ori[y][x];
  r ^= query(x, y, xx);
  r ^= query(y, x, yy);
  return r;
}
int solve() {
  int ans = 0;
  for (int i = 0; i < N; i++) {
    vector<int> sx, sy;
    for (int j = i + 1; j < N; j++) {
      if (query(j, i) != query(j + 1, i)) sx.push_back(j);
      if (query(i, j) != query(i, j + 1)) sy.push_back(j);
    }
    ans += sx.size() + sy.size();
    if ((sx.size() % 2) ^ (sy.size() % 2) ^ (query(i, i) % 2)) {
      ans++;
    }
    for (int j = 0; j < sx.size(); j++) {
      flip(i, sx[j], sx[j], yy);
    }
    for (int j = 0; j < sy.size(); j++) {
      flip(i, sy[j], sy[j], xx);
    }
  }
  return ans;
}
int main() {
  while (~scanf("%d", &N)) {
    memset(ori, 0, sizeof(ori));
    memset(xx, 0, sizeof(xx));
    memset(yy, 0, sizeof(yy));
    for (lim = 1; lim < N + 4; lim <<= 1)
      ;
    for (int i = 0; i < N; i++) {
      scanf("%s", ori[i]);
      for (int j = 0; j < N; j++) {
        ori[i][j] -= '0';
      }
    }
    printf("%d\n", solve());
  }
  return 0;
}
