#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
const int N = 200005;
int n, m;
char _g[N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dirid[300];
int check(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }
void IN() {
  static char s[N];
  n = read(), m = read();
  for (int i = (1); i <= (n); i++) {
    scanf("%s", s + 1);
    for (int j = (1); j <= (m); j++) _g[(i - 1) * m + j] = s[j];
  }
}
vector<int> e[N], rts;
int t0 = 0, t1 = 0;
int I[N], O[N], tp[N], id[N];
void dfs(int x, int &Time) {
  I[x] = ++Time;
  if (tp[x] == 0) id[Time] = x;
  for (auto y : e[x]) dfs(y, Time);
  O[x] = Time;
}
namespace seg {
const int S = N * 4;
int mi[S], cnt[S], add[S];
void build(int rt, int L, int R) {
  mi[rt] = 0, cnt[rt] = R - L + 1, add[rt] = 0;
  if (L == R) return;
  int mid = (L + R) >> 1, ls = rt << 1, rs = ls | 1;
  build(ls, L, mid);
  build(rs, mid + 1, R);
}
void pushup(int rt) {
  int ls = rt << 1, rs = ls | 1;
  mi[rt] = min(mi[ls], mi[rs]);
  cnt[rt] = (mi[rt] == mi[ls] ? cnt[ls] : 0) + (mi[rt] == mi[rs] ? cnt[rs] : 0);
}
void pushdown(int rt) {
  if (!add[rt]) return;
  int ls = rt << 1, rs = ls | 1;
  add[ls] += add[rt], add[rs] += add[rt];
  mi[ls] += add[rt], mi[rs] += add[rt];
  add[rt] = 0;
}
void update(int rt, int L, int R, int xL, int xR, int v) {
  if (R < xL || L > xR) return;
  if (xL <= L && R <= xR) {
    add[rt] += v, mi[rt] += v;
    return;
  }
  pushdown(rt);
  int mid = (L + R) >> 1, ls = rt << 1, rs = ls | 1;
  update(ls, L, mid, xL, xR, v);
  update(rs, mid + 1, R, xL, xR, v);
  pushup(rt);
}
}  // namespace seg
vector<pair<int, int> > add[N], rem[N];
int main() {
  IN();
  dirid['D'] = 0;
  dirid['U'] = 1;
  dirid['R'] = 2;
  dirid['L'] = 3;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) {
      int d = dirid[(int)_g[(i - 1) * m + j]];
      tp[((i - 1) * m + j)] = (i + j) & 1;
      int x = i + dx[d] * 2;
      int y = j + dy[d] * 2;
      if (check(x, y))
        e[((x - 1) * m + y)].push_back(((i - 1) * m + j));
      else
        rts.push_back(((i - 1) * m + j));
    }
  for (auto i : rts) dfs(i, tp[i] ? t1 : t0);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) {
      if (tp[((i - 1) * m + j)] == 1) continue;
      int d = dirid[(int)_g[(i - 1) * m + j]];
      int x = i + dx[d], y = j + dy[d];
      int a = ((i - 1) * m + j), b = ((x - 1) * m + y);
      add[I[a]].push_back(make_pair(I[b], O[b]));
      rem[O[a]].push_back(make_pair(I[b], O[b]));
    }
  seg::build(1, 1, t1);
  long long ans = 0;
  for (int i = (1); i <= (t0); i++) {
    for (auto v : add[i]) seg::update(1, 1, t1, v.first, v.second, 1);
    ans += seg::mi[1] ? t1 : t1 - seg::cnt[1];
    for (auto v : rem[i]) seg::update(1, 1, t1, v.first, v.second, -1);
  }
  cout << ans << endl;
  return 0;
}
