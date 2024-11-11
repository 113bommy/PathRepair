#include <bits/stdc++.h>
using namespace std;
bool exitInput = false;
int ntest = 1, itest = 1;
const int dx[4] = {+0, +1, +0, -1};
const int dy[4] = {+1, +0, -1, +0};
const long long Mod = 1e9 + 7;
const int maxn = 200000 + 5;
const int maxv = 11;
const int maxe = 10000 + 5;
const char X = 'X', blank = '.';
int n, m, vision[2 * maxn], P[2 * maxn][20], LP[2 * maxn][20], LogN;
char s[2][maxn];
bool station[2 * maxn];
int leftStation[2 * maxn];
pair<int, int> toRC(int x) {
  pair<int, int> ret;
  ret.first = x / n;
  ret.second = x % n;
  return ret;
}
void build_vision() {
  int i, j;
  for (i = 0; i <= 1; ++i) {
    for (j = n; j >= 0; --j) {
      if (s[i][j] == blank)
        vision[i * n + j] = vision[i * n + j + 1] + 1;
      else
        vision[i * n + j] = -1;
    }
  }
}
void build_station() {
  int i, j;
  for (i = 0; i <= 1; ++i) {
    for (j = 0; j < n; ++j) {
      if (s[i][j] == blank && j + 1 <= n && s[i][j + 1] == X)
        station[i * n + j] = true;
      else
        station[i * n + j] = false;
    }
  }
}
void build_P() {
  int i, j, x, k, y;
  memset(P, -1, sizeof(P));
  for (i = 0; i <= 1; ++i) {
    for (j = 0; j < n; ++j) {
      x = i * n + j;
      if (station[x]) {
        y = (i ^ 1) * n + j;
        if (s[i ^ 1][j] == blank) {
          P[x][0] = y + vision[y];
          LP[x][0] = 1 + vision[y];
        }
      }
    }
  }
  for (k = 1; k <= LogN; ++k) {
    for (i = 0; i <= 1; ++i) {
      for (j = 0; j < n; ++j) {
        x = i * n + j;
        if (station[x]) {
          y = P[x][k - 1];
          if (y != -1 && P[y][k - 1] != x) {
            P[x][k] = P[y][k - 1];
            LP[x][k] = LP[x][k - 1] + LP[y][k - 1];
          }
        }
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  int i;
  for (i = 0; i <= 1; ++i) {
    scanf("%s", s[i]);
    s[i][n] = X;
  }
  for (LogN = 1; (1 << LogN) <= n; ++LogN)
    ;
  --LogN;
  build_vision();
  build_station();
  build_P();
  while (m--) {
    int u, v, cost = 0;
    scanf("%d %d", &u, &v);
    --u;
    --v;
    int ru, cu, rv, cv;
    rv = v / n;
    cv = v % n;
    ru = u / n;
    cu = u % n;
    if (cu > cv) {
      swap(u, v);
      swap(ru, rv);
      swap(cu, cv);
    }
    if (cu + vision[u] >= cv) {
      cost += cv - cu + (ru != rv);
      u = v;
    } else {
      if (!station[u]) {
        cost += vision[u];
        u += vision[u];
      }
      for (i = LogN; i >= 0; --i) {
        ru = u / n;
        cu = u % n;
        if (P[u][i] != -1 && P[u][i] % n <= cv) {
          cost += LP[u][i];
          u = P[u][i];
        }
      }
      if (u != v) {
        ru = u / n;
        cu = u % n;
        i = ru ^ 1;
        if (s[i][cu] == blank) {
          if (ru == 0)
            u += n;
          else
            u -= n;
          ru = i;
          if (cu + vision[u] >= cv) {
            cost += 1 + (cv - cu) + (rv != ru);
            u = v;
          }
        }
      }
    }
    if (u == v)
      printf("%d\n", cost);
    else
      printf("-1\n");
  }
  fclose(stdout);
  fclose(stdin);
  return 0;
}
