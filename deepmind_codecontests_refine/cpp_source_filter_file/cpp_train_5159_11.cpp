#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
inline bool Equal(const double& a, const double& b) {
  return a + eps >= b && b + eps >= a;
}
inline bool Below(const double& a, const double& b) { return b + eps >= a; }
inline int Abs(const int& a) { return a > 0 ? a : -a; }
void Read(int& x) {
  char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    ;
  x = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}
int n, m;
struct EDGE {
  int to, next;
} edge[200010];
int head[100010], tot = 0;
inline void AddEdge(int a, int b) {
  edge[++tot].to = b;
  edge[tot].next = head[a];
  head[a] = tot;
}
int size[100010], prt[100010], son[100010], deep[100010];
int dfn[100010], ufn[100010], ti = 0, top[100010], Id[100010];
void Dfs1(int rt) {
  size[rt] = 1;
  for (int x = head[rt]; x; x = edge[x].next) {
    if (size[(edge[x].to)]) continue;
    deep[(edge[x].to)] = deep[rt] + 1;
    prt[(edge[x].to)] = rt;
    Dfs1((edge[x].to));
    size[rt] += size[(edge[x].to)];
    if (size[(edge[x].to)] > size[son[rt]]) son[rt] = (edge[x].to);
  }
}
void Dfs2(int rt, int tp, int k) {
  dfn[rt] = ++ti;
  ufn[ti] = rt;
  top[rt] = tp;
  Id[rt] = k;
  if (son[rt]) Dfs2(son[rt], tp, k + 1);
  for (int x = head[rt]; x; x = edge[x].next)
    if (prt[(edge[x].to)] == rt && son[rt] != (edge[x].to))
      Dfs2((edge[x].to), (edge[x].to), 1);
}
int Lca(int a, int b) {
  while (top[a] != top[b]) {
    if (deep[top[a]] > deep[top[b]])
      a = prt[top[a]];
    else
      b = prt[top[b]];
  }
  if (deep[a] < deep[b]) return a;
  return b;
}
int Dis(int a, int b) {
  int c = Lca(a, b);
  return deep[a] + deep[b] - 2 * deep[c];
}
double TIM;
struct Node {
  double tim;
  int fr, to, spd, id;
  bool Dir;
  Node() {}
  Node(double a, int b, int c, int d, int e) {
    tim = a, fr = b, to = c, spd = d, id = e;
    if (fr <= to)
      Dir = 1;
    else
      Dir = 0;
  }
  bool operator<(const Node& a) const {
    double x1 = (TIM - tim) * spd;
    double x2 = (TIM - a.tim) * a.spd;
    if (Dir == 0)
      x1 = fr - x1;
    else
      x1 = fr + x1;
    if (a.Dir == 0)
      x2 = a.fr - x2;
    else
      x2 = a.fr + x2;
    if (Equal(x1, x2))
      return id < a.id;
    else
      return Below(x1, x2);
  }
};
vector<Node> sta[100010];
double Query(Node a, Node b) {
  int u1 = a.fr, v1 = a.to, u2 = b.fr, v2 = b.to;
  if (u1 > v1) swap(u1, v1);
  if (u2 > v2) swap(u2, v2);
  u1 = max(u1, u2), v1 = min(v1, v2);
  double t1, t2, x;
  if (u1 <= v1) {
    if (a.Dir == b.Dir) {
      if (a.Dir == 1 && b.Dir == 1)
        t1 = a.tim + (double)Abs(u1 - a.fr) / a.spd,
        t2 = b.tim + (double)Abs(u1 - b.fr) / b.spd;
      else
        t1 = a.tim + (double)Abs(a.fr - v1) / a.spd,
        t2 = b.tim + (double)Abs(b.fr - v1) / b.spd;
      if (a.spd == b.spd) {
        if (!Equal(t1, t2))
          return 1e100;
        else
          return t1;
      } else {
        x = (t1 - t2) * b.spd * a.spd / (a.spd - b.spd);
        if (Below(0, x) && Below(x, v1 - u1))
          return t1 + x / a.spd;
        else
          return 1e100;
      }
    } else {
      if (a.Dir == 0 && b.Dir == 1)
        t1 = a.tim + (double)Abs(a.fr - v1) / a.spd,
        t2 = b.tim + (double)Abs(u1 - b.fr) / b.spd;
      else
        t1 = a.tim + (double)Abs(u1 - a.fr) / a.spd,
        t2 = b.tim + (double)Abs(b.fr - v1) / b.spd;
      x = a.spd * (v1 - u1 - b.spd * t1 + b.spd * t2) / (a.spd + b.spd);
      if (Below(0, x) && Below(x, v1 - u1))
        return t1 + x / a.spd;
      else
        return 1e100;
    }
  } else
    return 1e100;
}
struct Things {
  double tim;
  bool Ty;
  int id;
  Things(double a = 0, bool b = false, int d = 0) { tim = a, Ty = b, id = d; }
  bool operator<(const Things& a) const {
    return Equal(tim, a.tim) ? (Ty != a.Ty ? Ty < a.Ty : id < a.id)
                             : tim < a.tim;
  }
} B[200010];
int cnt = 0;
double Work(vector<Node>& p) {
  vector<Node>::iterator it;
  cnt = 0;
  int i, x;
  for (it = p.begin(), i = 0; it != p.end(); ++it, ++i) {
    B[++cnt] = Things(it->tim, 0, i);
    B[++cnt] = Things(it->tim + (double)Abs(it->to - it->fr) / it->spd, 1, i);
  }
  set<Node> S;
  TIM = 0;
  sort(B + 1, B + 1 + cnt);
  Node q;
  double ans = 1e100;
  for (int i = 1; i <= cnt; ++i) {
    TIM = B[i].tim;
    if (Below(ans, TIM)) {
      return ans;
    }
    if (B[i].Ty == 0) {
      q = p[B[i].id];
      set<Node>::iterator iter = S.lower_bound(q);
      if (iter != S.end()) ans = min(ans, Query(*iter, q));
      if (Below(ans, TIM)) return ans;
      if (iter != S.begin()) --iter, ans = min(ans, Query(*iter, q));
      if (Below(ans, TIM)) return ans;
      S.insert(q);
    } else {
      q = p[B[i].id];
      if (S.find(q) == S.end()) {
        puts("mdzz");
        exit(0);
      }
      S.erase(S.find(q));
      set<Node>::iterator iter = S.lower_bound(q);
      if (iter != S.end() && iter != S.begin()) {
        set<Node>::iterator iter2 = iter;
        iter2--;
        ans = min(ans, Query(*iter, *iter2));
        if (Below(ans, TIM)) return ans;
      }
    }
  }
  return ans;
}
signed main() {
  scanf("%d%d", &n, &m);
  int a, b;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &a, &b);
    AddEdge(a, b);
    AddEdge(b, a);
  }
  Dfs1(1);
  Dfs2(1, 1, 1);
  double t1, t2;
  int t, c, u, v;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &t, &c, &u, &v);
    a = u, b = v;
    t2 = t + (double)Dis(a, b) / c;
    while (top[a] != top[b]) {
      if (deep[top[a]] > deep[top[b]]) {
        sta[top[a]].push_back(
            Node(t + (double)(deep[u] - deep[a]) / c, Id[a], 0, c, i));
        a = prt[top[a]];
      } else {
        sta[top[b]].push_back(Node(
            t2 - (double)(deep[v] - deep[prt[top[b]]]) / c, 0, Id[b], c, i));
        b = prt[top[b]];
      }
    }
    sta[top[a]].push_back(
        Node(t + (double)(deep[u] - deep[a]) / c, Id[a], Id[b], c, i));
  }
  double ans = (double)1e100;
  for (int i = 1; i <= n; ++i) {
    if (sta[i].empty()) continue;
    ans = min(ans, Work(sta[i]));
  }
  if (Equal(ans, 1e100))
    puts("-1");
  else
    printf("%.10f\n", (double)ans);
  return 0;
}
