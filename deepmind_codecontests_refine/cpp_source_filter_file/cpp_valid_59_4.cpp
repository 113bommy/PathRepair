#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
int N, M;
int a[1005], b[1005];
vector<int> nei[1005];
bool lgl[1005];
bool in[1005];
long long nhp;
bool dfs(int now, int lst, long long hp) {
  if (hp < a[now]) return 0;
  lgl[now] = 1;
  for (int i = 0; i < (((int)(nei[now]).size())); ++i) {
    int to = nei[now][i];
    if (to == lst) continue;
    if (lgl[to] || in[to]) return nhp = hp + b[now], in[now] = 1, 1;
    if (dfs(to, now, hp + b[now])) {
      in[now] = 1;
      return 1;
    }
  }
  return 0;
}
bool check(long long hp) {
  memset(in, 0, sizeof(in));
  in[1] = 1;
  while (1) {
    memset(lgl, 0, sizeof(lgl));
    bool fnd = 0;
    for (int i = 1; i <= (N); ++i)
      if (in[i]) {
        for (int j = 0; j < (((int)(nei[i]).size())); ++j) {
          int to = nei[i][j];
          if (in[to]) continue;
          if (dfs(to, i, hp)) {
            fnd = 1;
            hp = nhp;
            goto Brk;
          }
        }
      }
  Brk:
    if (!fnd) break;
  }
  for (int i = 1; i <= (N); ++i)
    if (!in[i]) return 0;
  return 1;
}
void solve() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= (N); ++i) nei[i].clear();
  for (int i = 1; i <= (N - 1); ++i) scanf("%d", a + i + 1), ++a[i];
  for (int i = 1; i <= (N - 1); ++i) scanf("%d", b + i + 1);
  for (int i = 0; i < (M); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    nei[u].push_back(v);
    nei[v].push_back(u);
  }
  int L = -1, R = 1e9 + 1;
  while (R - L > 1) {
    int m = (L + R) >> 1;
    if (check(m))
      R = m;
    else
      L = m;
  }
  printf("%d\n", R);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
