#include <bits/stdc++.h>
using namespace std;
const int maxn = 1111;
int N, M, aa, bb, A[maxn][maxn], B[maxn][maxn], C[maxn][maxn], Q[maxn];
long long S[maxn][maxn];
bool vis[maxn][maxn];
struct hhh {
  long long a;
  int b, c;
} stk[maxn * maxn], ans[maxn * maxn];
bool cmp(const hhh &x, const hhh &y) {
  if (x.a != y.a) return x.a < y.a;
  if (x.b != y.b) return x.b < y.b;
  return x.c < y.c;
}
void color(int x, int y) {
  for (int i = max(1, x - aa + 1); i < x + aa; ++i)
    for (int j = max(1, y - aa + 1); j < y + bb; ++j) vis[i][j] = true;
}
int main() {
  scanf("%d%d%d%d", &N, &M, &aa, &bb);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      scanf("%d", &A[i][j]),
          S[i][j] = S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1] + A[i][j];
  for (int i = 1; i <= N; ++i) {
    int l = 1, r = 0;
    for (int j = 1; j <= M; ++j) {
      while (l <= r && j - Q[l] >= bb) ++l;
      while (l <= r && A[i][j] <= A[i][Q[r]]) --r;
      Q[++r] = j;
      B[i][j] = A[i][Q[l]];
    }
  }
  for (int j = 1; j <= M; ++j) {
    int l = 1, r = 0;
    for (int i = 1; i <= N; ++i) {
      while (l <= r && i - Q[l] >= aa) ++l;
      while (l <= r && B[i][j] <= B[Q[r]][j]) --r;
      Q[++r] = i;
      C[i][j] = B[Q[l]][j];
    }
  }
  int T1 = 0;
  for (int i = aa; i <= N; ++i) {
    for (int j = bb; j <= M; ++j) {
      int xx = i - aa + 1, yy = j - bb + 1;
      stk[++T1] = (hhh){S[i][j] - S[i][yy - 1] - S[xx - 1][j] +
                            S[xx - 1][yy - 1] - (long long)C[i][j] * aa * bb,
                        xx, yy};
    }
  }
  sort(stk + 1, stk + 1 + T1, cmp);
  int T2 = 0;
  for (int i = 1; i <= T1; ++i) {
    int xx = stk[i].b, yy = stk[i].c;
    if (!vis[xx][yy]) {
      ans[++T2] = stk[i];
      color(xx, yy);
    }
  }
  printf("%d\n", T2);
  for (int i = 1; i <= T2; ++i)
    printf("%d %d %lld\n", ans[i].b, ans[i].c, ans[i].a);
  return 0;
}
