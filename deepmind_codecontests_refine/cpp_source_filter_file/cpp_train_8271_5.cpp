#include <bits/stdc++.h>
using namespace std;
inline void chk_mx(int &x, int y) {
  if (x < y) x = y;
}
const int M = 4005;
const int N = 10005;
int n, p, q;
int dp[M][M], Dp[M][M], Id[N], id[N];
struct node {
  int c, v;
};
vector<node> E[N];
void merge(int *A, const node &x) {
  for (int i = (M - x.c - 1), i_END = (0); i >= i_END; --i)
    chk_mx(A[i + x.c], A[i] + x.v);
}
int main() {
  int c, h, t, i1 = 0, i2 = 0;
  scanf("%d%d", &n, &p);
  for (int i = (1), i_END = (n); i <= i_END; ++i) {
    scanf("%d%d%d", &c, &h, &t);
    E[t - 1].push_back((node){c, h});
  }
  for (int i = (0), i_END = (N - 1); i <= i_END; ++i) {
    if (i % p != 0) {
      if (E[i].size()) {
        Id[i] = ++i1;
        memcpy(dp[Id[i]], dp[Id[i - 1]], sizeof dp[Id[i]]);
      } else
        Id[i] = Id[i - 1];
    } else
      Id[i] = E[i].size() ? ++i1 : 0;
    for (int j = (0), j_END = (E[i].size() - 1); j <= j_END; ++j)
      merge(dp[Id[i]], E[i][j]);
  }
  for (int i = (N - 1), i_END = (0); i >= i_END; --i) {
    if (i % p != 0) {
      if (E[i].size()) {
        id[i] = ++i2;
        memcpy(Dp[id[i]], Dp[id[i + 1]], sizeof Dp[id[i]]);
      } else
        id[i] = id[i + 1];
    } else {
      id[i] = E[i].size() ? ++i2 : 0;
      continue;
    }
    for (int j = (0), j_END = (E[i].size() - 1); j <= j_END; ++j)
      merge(Dp[id[i]], E[i][j]);
  }
  scanf("%d", &q);
  for (int i = (1), i_END = (q); i <= i_END; ++i) {
    int t, c;
    scanf("%d%d", &t, &c);
    --t;
    if ((t < p) || t % p == p - 1)
      printf("%d\n", dp[Id[t]][c]);
    else {
      int ans = 0;
      int *A = Dp[id[t - p + 1]], *B = dp[Id[t]];
      for (int i = (0), i_END = (c); i <= i_END; ++i) {
        chk_mx(ans, A[c - i] + B[i]);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
