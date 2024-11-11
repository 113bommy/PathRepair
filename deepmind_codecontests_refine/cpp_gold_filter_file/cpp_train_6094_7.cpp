#include <bits/stdc++.h>
using namespace std;
inline void rd(int &x) {
  char ch;
  x = 0;
  bool fl = false;
  while (!isdigit(ch = getchar())) (ch == '-') && (fl = true);
  for (x = (ch ^ '0'); isdigit(ch = getchar()); x = x * 10 + (ch ^ '0'))
    ;
  (fl == true) && (x = -x);
}
namespace Miracle {
const int N = 5e5 + 5;
const int M = 1e5 + 5;
int n, m;
char s[N], a[M];
pair<int, int> cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first < b.first ? a : b;
  }
  return a.second > b.second ? a : b;
}
struct SAM {
  int f[2 * M][20], ch[2 * M][26], len[2 * M];
  int nd, cnt;
  void init() { nd = cnt = 1; }
  struct node {
    int ls, rs;
    int mx, id;
  } t[4 * M * 20];
  int rt[2 * M];
  int pos[N];
  int pi[N];
  int num;
  void pushup(int x) {
    if (t[t[x].ls].mx > t[t[x].rs].mx ||
        (t[t[x].ls].mx == t[t[x].rs].mx && t[t[x].ls].id < t[t[x].rs].id)) {
      t[x].mx = t[t[x].ls].mx;
      t[x].id = t[t[x].ls].id;
    } else {
      t[x].mx = t[t[x].rs].mx;
      t[x].id = t[t[x].rs].id;
    }
  }
  void upda(int &x, int l, int r, int to, int c) {
    if (!x) x = ++num;
    if (l == r) {
      t[x].mx += c;
      t[x].id = l;
      return;
    }
    if (to <= ((l + r) >> 1))
      upda(t[x].ls, l, ((l + r) >> 1), to, c);
    else
      upda(t[x].rs, ((l + r) >> 1) + 1, r, to, c);
    pushup(x);
  }
  int merge(int x, int y, int l, int r) {
    if (!x || !y) return x + y;
    int ret = ++num;
    if (l == r) {
      t[ret].mx = t[x].mx + t[y].mx;
      t[ret].id = t[x].id;
      return ret;
    }
    t[ret].ls = merge(t[x].ls, t[y].ls, l, ((l + r) >> 1));
    t[ret].rs = merge(t[x].rs, t[y].rs, ((l + r) >> 1) + 1, r);
    pushup(ret);
    return ret;
  }
  pair<int, int> query(int x, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
      return make_pair(t[x].id, t[x].mx);
    }
    pair<int, int> ret;
    ret.first = 0, ret.second = -2333;
    if (L <= ((l + r) >> 1))
      ret = cmp(ret, query(t[x].ls, l, ((l + r) >> 1), L, R));
    if (((l + r) >> 1) < R)
      ret = cmp(ret, query(t[x].rs, ((l + r) >> 1) + 1, r, L, R));
    return ret;
  }
  void ins(int l, int c, int d) {
    int p = nd;
    nd = ++cnt;
    len[nd] = l;
    for (; p && ch[p][c] == 0; p = f[p][0]) ch[p][c] = cnt;
    int q;
    if (!p) {
      f[nd][0] = 1;
      goto abc;
    }
    q = ch[p][c];
    if (len[q] == len[p] + 1) {
      f[nd][0] = q;
      goto abc;
    }
    len[++cnt] = len[p] + 1;
    f[cnt][0] = f[q][0];
    f[q][0] = f[nd][0] = cnt;
    for (register int i = 0; i < 26; ++i) ch[cnt][i] = ch[q][i];
    for (; p && ch[p][c] == q; p = f[p][0]) ch[p][c] = cnt;
  abc:;
    upda(rt[nd], 1, m, d, 1);
  }
  void wrk(char *s) {
    int lth = strlen(s + 1);
    int now = 1;
    int l = 0;
    for (register int i = 1; i <= lth; ++i) {
      int x = s[i] - 'a';
      if (ch[now][x] == 0) {
        while (now && ch[now][x] == 0) now = f[now][0];
        if (!now) {
          l = 0;
          pos[i] = 1;
          now = 1;
          pi[i] = 0;
        } else {
          l = len[now] + 1;
          now = ch[now][x];
          pi[i] = l;
          pos[i] = now;
        }
      } else {
        ++l;
        now = ch[now][x];
        pi[i] = l;
        pos[i] = now;
      }
    }
  }
  struct edge {
    int nxt, to;
  } e[2 * M];
  int hd[2 * M], tot;
  void add(int x, int y) {
    e[++tot].nxt = hd[x];
    e[tot].to = y;
    hd[x] = tot;
  }
  void dfs(int x) {
    for (register int i = hd[x]; i; i = e[i].nxt) {
      int y = e[i].to;
      dfs(y);
      rt[x] = merge(rt[x], rt[y], 1, m);
    }
  }
  void build() {
    for (register int i = 2; i <= cnt; ++i) add(f[i][0], i);
    dfs(1);
    for (register int j = 1; j <= 19; ++j) {
      for (register int i = 1; i <= cnt; ++i) {
        f[i][j] = f[f[i][j - 1]][j - 1];
      }
    }
  }
  pair<int, int> sol(int p, int l, int L, int R, int lp) {
    if (pi[p] < l) return make_pair(L, 0);
    p = pos[p];
    for (register int j = 19; j >= 0; --j) {
      if (len[f[p][j]] >= l) p = f[p][j];
    }
    pair<int, int> ret = query(rt[p], 1, m, L, R);
    if (ret.first == 0) ret.first = L;
    return ret;
  }
  void main() {
    scanf("%s", s + 1);
    rd(m);
    init();
    for (register int i = 1; i <= m; ++i) {
      int now = 0;
      scanf("%s", a + 1);
      now = strlen(a + 1);
      nd = 1;
      for (register int j = 1; j <= now; ++j) {
        ins(j, a[j] - 'a', i);
      }
    }
    wrk(s);
    build();
    int q;
    rd(q);
    int l, r, pl, pr;
    int o = 0;
    while (q--) {
      rd(l);
      rd(r);
      rd(pl);
      rd(pr);
      pair<int, int> ans = sol(pr, pr - pl + 1, l, r, ++o);
      printf("%d %d\n", ans.first, ans.second);
    }
  }
} sam;
int main() {
  sam.main();
  return 0;
}
}  // namespace Miracle
signed main() {
  Miracle::main();
  return 0;
}
