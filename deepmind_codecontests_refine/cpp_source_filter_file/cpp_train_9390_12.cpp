#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
const int MAXM = 100010;
const int INF = ~0U >> 2;
struct node {
  int a, b, w;
} e[MAXM];
int n, m, k;
int len[MAXN][MAXN];
int r[MAXN], rc;
int p[MAXN];
int tem[MAXN][MAXN], cnt[MAXN];
int dp[MAXN][3];
bool used[MAXN];
map<pair<int, int>, int> id;
bool operator<(const node &x, const node &y) { return x.w < y.w; }
int find_set(int x) {
  if (p[x] != x) p[x] = find_set(p[x]);
  return p[x];
}
void init() {
  scanf("%d%d%d", &n, &m, &k);
  rc = 0;
  for (int i = 0, a, b, w; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &w);
    e[i].a = a, e[i].b = b, e[i].w = w;
    len[a][b] = len[b][a] = w;
    id[make_pair(a, b)] = id[make_pair(b, a)] = i + 1;
    if (a == 1) r[rc++] = b;
    if (b == 1) r[rc++] = a;
  }
}
void add(int a, int b) {
  tem[a][cnt[a]++] = b;
  tem[b][cnt[b]++] = a;
}
int MDMST() {
  sort(e, e + m);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) p[i] = i;
  for (int i = 0; i < m; ++i) {
    if (e[i].a == 1 || e[i].b == 1) continue;
    int a = find_set(e[i].a), b = find_set(e[i].b);
    if (a != b) p[a] = b, add(e[i].a, e[i].b);
  }
  int m = 0;
  for (int i = 2; i <= n; ++i)
    if (p[i] == i) m++;
  for (int i = 0; i < m; ++i) {
    if (e[i].a != 1 && e[i].b != 1) continue;
    int a = find_set(e[i].a), b = find_set(e[i].b);
    if (a != b) p[a] = b, add(e[i].a, e[i].b);
  }
  memset(used, false, sizeof(used));
  for (int i = 0; i < cnt[1]; ++i) used[tem[1][i]] = true;
  return m;
}
void DP(int x, int father) {
  for (int i = 0; i < cnt[x]; ++i)
    if (tem[x][i] != father) {
      if (len[x][tem[x][i]] > dp[x][0]) {
        dp[tem[x][i]][0] = len[x][tem[x][i]];
        dp[tem[x][i]][1] = x;
        dp[tem[x][i]][2] = tem[x][i];
      } else {
        dp[tem[x][i]][0] = dp[x][0];
        dp[tem[x][i]][1] = dp[x][1];
        dp[tem[x][i]][2] = dp[x][2];
      }
      DP(tem[x][i], x);
    }
}
void inc_deg() {
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < cnt[1]; ++i) DP(tem[1][i], 1);
  int id, mn = INF, i1, i2;
  for (int i = 0; i < rc; ++i)
    if (!used[r[i]] && len[1][r[i]] - dp[r[i]][0] < mn) {
      mn = len[1][r[i]] - dp[r[i]][0];
      id = r[i];
      i1 = dp[r[i]][1], i2 = dp[r[i]][2];
    }
  tem[1][cnt[1]++] = id;
  tem[id][cnt[id]++] = 1;
  used[id] = true;
  int i;
  for (i = 0; i < cnt[i1] && tem[i1][i] != i2; ++i)
    ;
  tem[i1][i] = tem[i1][--cnt[i1]];
  for (i = 0; i < cnt[i2] && tem[i2][i] != i1; ++i)
    ;
  tem[i2][i] = tem[i2][--cnt[i2]];
}
void KDMST() {
  int M = MDMST();
  if (k < M || k > rc) {
    puts("-1");
    return;
  }
  for (int i = 0; i < k - M; ++i) inc_deg();
  printf("%d\n", n - 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < cnt[i]; ++j)
      if (i < tem[i][j]) printf("%d ", id[make_pair(i, tem[i][j])]);
  printf("\n");
}
int main() {
  init();
  KDMST();
  return 0;
}
