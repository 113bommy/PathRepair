#include <bits/stdc++.h>
using namespace std;
const int xx[4] = {-1, 0, 1, 0};
const int yy[4] = {0, 1, 0, -1};
const int maxn = 300 + 2;
const int maxq = 2200000 + 10;
const int maxc = 2000000 + 10;
const int N = 150000 + 10;
const int DEBUG = 1;
const int S = (1 << 20) + 5;
char buf[S], *H, *T;
inline char Get() {
  if (H == T) T = (H = buf) + fread(buf, 1, S, stdin);
  if (H == T) return -1;
  return *H++;
}
inline void rd(int &x) {
  x = 0;
  int f = 1;
  char c = Get();
  while (!isdigit(c) && c != '-') c = Get();
  if (c == '-') f = -1, c = Get();
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = Get();
  }
  x = f * x;
}
int n, m, Sc, lst[maxc];
map<int, int> mp;
vector<int> vec[maxn][maxn];
struct anode {
  int x, y;
  anode() {}
  anode(int _x, int _y) : x(_x), y(_y) {}
} a[maxq];
int Ans[maxq];
int sfa[N], QNUM;
inline int encode(int x, int y) { return x * maxn + y; }
inline void decode(int w, int &x, int &y) {
  y = w % maxn;
  x = w / maxn;
}
int findfa(int u) { return (sfa[u] == u) ? (u) : (sfa[u] = findfa(sfa[u])); }
int col[maxn][maxn], COL;
inline int merge(int u, int v) {
  int f1 = findfa(u), f2 = findfa(v);
  if (f1 == f2) return 0;
  sfa[f1] = f2;
  return 1;
}
inline int Add(int x, int y) {
  int now = 1, u = encode(x, y);
  int used[10], ucnt = 0;
  for (int i = 0; i < 4; i++) {
    int dx = x + xx[i];
    int dy = y + yy[i];
    if (dx < 1 || dy < 1 || dx > n || dy > m) continue;
    if (col[dx][dy] == col[x][y]) {
      int v = encode(dx, dy);
      used[++ucnt] = findfa(v);
    }
  }
  sort(used + 1, used + ucnt + 1);
  int num = unique(used + 1, used + ucnt + 1) - used - 1;
  now -= num;
  for (int i = 0; i < 4; i++) {
    int dx = x + xx[i];
    int dy = y + yy[i];
    if (dx < 1 || dy < 1 || dx > n || dy > m) continue;
    if (col[dx][dy] == col[x][y]) {
      int v = encode(dx, dy);
      merge(u, v);
    }
  }
  return now;
}
inline void Clear(int sl, int sr) {
  for (int i = sl; i <= sr; i++) {
    int x = a[i].x, y = a[i].y;
    int p = encode(x, y);
    sfa[p] = p;
    col[x][y] = 0;
  }
}
pair<int, int> lis[maxq];
int Ans2[maxq];
inline void work(int sl, int sr) {
  if (sl > sr) return;
  COL++;
  int sum = 0, res = 0;
  Clear(sl, sr);
  for (int i = sl; i <= sr; i++) {
    int x = a[i].x, y = a[i].y;
    if (col[x][y] == COL)
      continue;
    else
      col[x][y] = COL;
    int now = Add(x, y);
    sum += now;
    Ans[i] += now;
  }
  Ans[sr + 1] -= sum;
  Clear(sl, sr);
  int lcnt = 0;
  for (int i = sl; i <= sr; i++) {
    int x = a[i].x, y = a[i].y;
    int nxt = *upper_bound(vec[x][y].begin(), vec[x][y].end(), i);
    if (i == vec[x][y].back()) {
      col[x][y] = COL;
      res += Add(x, y);
      continue;
    }
    if (nxt <= sr) continue;
    lis[++lcnt] = make_pair(nxt, i);
  }
  sort(lis + 1, lis + lcnt + 1);
  Ans2[QNUM + 1] += res;
  Ans2[sr] -= res;
  lis[0].first = sr + 1;
  int tagsum = 0;
  for (int i = lcnt; i >= 1; i--) {
    int t = lis[i].first, id = lis[i].second;
    int x = a[id].x, y = a[id].y;
    col[x][y] = COL;
    int now = Add(x, y);
    Ans2[t - 1] += now;
    t = lis[i - 1].first;
    tagsum += now;
  }
  Ans2[sr] -= tagsum;
}
int main() {
  int q, del = 0;
  Sc = 1;
  rd(n);
  rd(m);
  rd(q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      del++;
      vec[i][j].push_back(del);
      a[del] = anode(i, j);
    }
  }
  lst[1] = del;
  int Ccnt = 1;
  for (int i = 1 + del, llst = 1, lstnum = 1; i <= q + del; i++) {
    int x, y, c, p;
    rd(x);
    rd(y);
    rd(c);
    c++;
    if (c == llst)
      p = lstnum;
    else
      llst = c, lstnum = p = ++Ccnt;
    vec[x][y].push_back(i);
    a[i] = anode(x, y);
    lst[p] = i;
    Sc = max(Sc, p);
  }
  q += del;
  QNUM = q;
  for (int i = 1; i <= Sc; i++) {
    work(lst[i - 1] + 1, lst[i]);
  }
  Ans[0] = Ans[q + 1] = 0;
  for (int i = 1; i <= q; i++) Ans[i] += Ans[i - 1];
  for (int i = q; i >= 1; i--) Ans2[i] += Ans2[i + 1];
  for (int i = 1; i <= q; i++) Ans[i] += Ans2[i];
  for (int i = 1 + del; i <= q; i++) printf("%d\n", Ans[i]);
  return 0;
}
