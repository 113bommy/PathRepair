#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int oo = 0x3f3f3f3f;
const int maxn = 100;
char sa[maxn + 5], sb[maxn + 5], sc[maxn + 5];
int na, nb, nc;
int nxt[maxn + 5];
int dp[maxn + 5][maxn + 5][maxn + 5];
struct data {
  int i, j, k;
  data() {}
  data(int _i, int _j, int _k) : i(_i), j(_j), k(_k) {}
};
data pre[maxn + 5][maxn + 5][maxn + 5];
inline void get_nxt(char *a, int n, int *nxt) {
  int i = 1, j = 0;
  while (i < n) {
    while (j && a[i] != a[j]) j = nxt[j];
    if (a[i] == a[j]) ++j;
    ++i;
    nxt[i] = j;
  }
}
int main() {
  scanf("%s", sa), na = strlen(sa);
  scanf("%s", sb), nb = strlen(sb);
  scanf("%s", sc), nc = strlen(sc);
  memset(dp, -1, sizeof dp);
  get_nxt(sc, nc, nxt);
  dp[0][0][0] = 0;
  pre[0][0][0] = data(-1, -1, -1);
  for (int i = (0), _end_ = (na + 1); i < _end_; ++i)
    for (int j = (0), _end_ = (nb + 1); j < _end_; ++j)
      for (int k = (0), _end_ = (nc); k < _end_; ++k)
        if (dp[i][j][k] >= 0) {
          if (i < na && chkmax(dp[i + 1][j][k], dp[i][j][k]))
            pre[i + 1][j][k] = data(i, j, k);
          if (j < nb && chkmax(dp[i][j + 1][k], dp[i][j][k]))
            pre[i][j + 1][k] = data(i, j, k);
          if (i < na && j < nb && sa[i] == sb[j]) {
            int new_k = k;
            if (sa[i] == sc[k])
              ++new_k;
            else {
              while (new_k && sc[new_k] != sa[i]) new_k = nxt[new_k];
              if (sc[k] == sa[i]) ++new_k;
            }
            if (new_k < nc) {
              if (chkmax(dp[i + 1][j + 1][new_k], dp[i][j][k] + 1))
                pre[i + 1][j + 1][new_k] = data(i, j, k);
            }
          }
        }
  int ans = -1;
  data now = data(na, nb, -1);
  for (int i = (0), _end_ = (nc); i < _end_; ++i)
    if (chkmax(ans, dp[na][nb][i])) now = data(na, nb, i);
  if (ans == 0)
    printf("0\n");
  else {
    static char ret[maxn + 5];
    int retn = 0;
    while (now.i != -1) {
      data tmp = pre[now.i][now.j][now.k];
      if (tmp.i >= 0 && now.i != tmp.i && now.j != tmp.j)
        ret[retn++] = sa[tmp.i];
      now = tmp;
    }
    reverse(ret, ret + retn);
    ret[retn] = 0;
    printf("%s\n", ret);
  }
  return 0;
}
