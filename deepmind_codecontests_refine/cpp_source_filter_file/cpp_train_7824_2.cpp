#include <bits/stdc++.h>
using namespace std;
struct Vec {
  long long a[64];
  Vec() { memset(this, 0, sizeof(Vec)); }
};
struct Matrix {
  long long a[64][64];
  Matrix operator*(const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 64; i++) {
      for (int j = 0; j < 64; j++) {
        c.a[i][j] = 0;
        for (int k = 0; k < 64; k++) {
          c.a[i][j] += a[i][k] * b.a[k][j];
          c.a[i][j] > 1ll * 998244353 * 998244353
              ? c.a[i][j] -= 1ll * 998244353 * 998244353
              : 0;
        }
        c.a[i][j] %= 998244353;
      }
    }
    return c;
  }
  Vec operator*(const Vec &b) {
    Vec c;
    for (int i = 0; i < 64; i++) {
      for (int j = 0; j < 64; j++) {
        c.a[i] += a[i][j] * b.a[j];
        c.a[i] > 1ll * 998244353 * 998244353
            ? c.a[j] -= 1ll * 998244353 * 998244353
            : 0;
      }
      c.a[i] %= 998244353;
    }
    return c;
  }
} tr[30], trc[3];
int a[1005], f[3][3];
int n, m, x, y, z;
vector<pair<int, int> > v[1005];
inline void add(int x, int y, int z) { v[x].push_back(make_pair(y, z)); }
void read() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%d%d%d", &x, &y, &z), add(x, y, z - 1);
  for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) scanf("%d", f[i] + j);
}
void prework() {
  for (int i = 0; i < 64; i++) {
    int pos[3];
    for (int j = 0; j < 3; j++) pos[j] = (i >> (j << 1)) & 3;
    for (int col = 0; col < 3; col++) {
      bool vis[4] = {0};
      for (int j = 0; j < 3; j++)
        if (f[col][j]) vis[pos[j]] = 1;
      int sg;
      for (int j = 0; j < 4; j++)
        if (!vis[j]) {
          sg = j;
          break;
        }
      int w = sg + pos[0] * 4 + pos[1] * 16;
      tr[0].a[w][i] += 1, trc[col].a[w][i] += 1;
    }
  }
  for (int i = 1; i < 30; i++) {
    tr[i] = tr[i - 1] * tr[i - 1];
  }
}
inline void cal(Vec &a, int k) {
  for (int i = 0; i < 30; i++)
    if (k & (1 << i)) a = tr[i] * a;
}
long long num[1005][4], ans[1005][4];
int main() {
  read();
  prework();
  ans[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    Vec now;
    int la = 0;
    now.a[63] = 1;
    for (auto j : v[i]) {
      cal(now, j.first - la - 1);
      now = trc[j.second] * now;
      la = j.first;
    }
    cal(now, a[i] - la);
    for (int j = 0; j < 64; j++) (num[i][j & 3] += now.a[j]) %= 998244353;
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        (ans[i][j ^ k] += ans[i - 1][j] * num[i][k]) %= 998244353;
      }
    }
  }
  printf("%d\n", ans[n][0]);
  return 0;
}
