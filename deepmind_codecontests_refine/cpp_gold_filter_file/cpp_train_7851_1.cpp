#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 101007;
const int MAXK = 107;
const int MOD = 1e9 + 7;
int n, m;
int l, r, k;
int a[MAXN];
int C[MAXN][MAXK], del[MAXK][MAXN], ans[MAXN], nd[MAXK];
void init();
void input();
void inputq();
void work();
void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int vadd(int x, int y) {
  int ans = x + y;
  if (ans >= MOD) ans -= MOD;
  return ans;
}
void dec(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
int main() {
  init();
  input();
  work();
}
void init() {
  ios::sync_with_stdio(false);
  int ub;
  for (int i = 0; i < MAXN; ++i) {
    C[i][0] = 1;
    if (i < MAXK) C[i][i] = 1;
    ub = (((MAXK) < (i)) ? (MAXK) : (i));
    for (int j = 1; j < ub; ++j) C[i][j] = vadd(C[i - 1][j], C[i - 1][j - 1]);
  }
}
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
}
void inputq() { scanf("%d%d%d", &l, &r, &k); }
void work() {
  for (int i = 1; i <= n; ++i) add(del[0][i], a[i]), dec(del[0][i + 1], a[i]);
  for (int i = 0; i < m; ++i) {
    inputq();
    memset(nd, 0, sizeof(nd));
    for (int i = k; i >= 0; --i) {
      nd[0] = C[r - l + i][i];
      for (int j = k - i + 1; j > 0; --j) dec(nd[j], nd[j - 1]);
    }
    add(del[k][l], 1);
    for (int i = 1; i <= k + 1; ++i) add(del[k][r + i], nd[i]);
  }
  for (int i = MAXK - 2; i >= 0; --i) {
    for (int j = 1; j <= n; ++j) {
      add(ans[j], vadd(ans[j - 1], del[i][j]));
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  putchar('\n');
}
