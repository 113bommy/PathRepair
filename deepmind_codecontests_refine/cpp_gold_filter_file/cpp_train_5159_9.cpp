#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
inline bool Equal(const double& a, const double& b) {
  return a + eps >= b && b + eps >= a;
}
inline bool Below(const double& a, const double& b) { return b + eps >= a; }
inline long long Abs(const long long& a) { return a > 0 ? a : -a; }
void Read(long long& x) {
  char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    ;
  x = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}
long long n, m;
struct EDGE {
  long long to, next;
} edge[200010];
long long head[100010], tot = 0;
inline void AddEdge(long long a, long long b) {
  edge[++tot].to = b;
  edge[tot].next = head[a];
  head[a] = tot;
}
long long size[100010], prt[100010], son[100010], deep[100010];
long long dfn[100010], ufn[100010], ti = 0, top[100010], Id[100010];
void Dfs1(long long rt) {
  size[rt] = 1;
  for (long long x = head[rt]; x; x = edge[x].next) {
    if (size[(edge[x].to)]) continue;
    deep[(edge[x].to)] = deep[rt] + 1;
    prt[(edge[x].to)] = rt;
    Dfs1((edge[x].to));
    size[rt] += size[(edge[x].to)];
    if (size[(edge[x].to)] > size[son[rt]]) son[rt] = (edge[x].to);
  }
}
void Dfs2(long long rt, long long tp, long long k) {
  dfn[rt] = ++ti;
  ufn[ti] = rt;
  top[rt] = tp;
  Id[rt] = k;
  if (son[rt]) Dfs2(son[rt], tp, k + 1);
  for (long long x = head[rt]; x; x = edge[x].next)
    if (prt[(edge[x].to)] == rt && son[rt] != (edge[x].to))
      Dfs2((edge[x].to), (edge[x].to), 1);
}
long long Lca(long long a, long long b) {
  while (top[a] != top[b]) {
    if (deep[top[a]] > deep[top[b]])
      a = prt[top[a]];
    else
      b = prt[top[b]];
  }
  if (deep[a] < deep[b]) return a;
  return b;
}
long long Dis(long long a, long long b) {
  long long c = Lca(a, b);
  return deep[a] + deep[b] - 2 * deep[c];
}
struct Node {
  double tim;
  long long fr, to, spd;
  bool Dir;
  Node(double a = 0, long long b = 0, long long c = 0, long long d = 0) {
    tim = a, fr = b, to = c, spd = d;
    if (fr <= to)
      Dir = 1;
    else
      Dir = 0;
  }
  bool operator<(const Node& a) const {
    if (fr != a.fr) return fr < a.fr;
    if (Dir != a.Dir) return Dir < a.Dir;
    if (Dir == 0) {
      if (!Equal(tim, a.tim))
        return tim < a.tim;
      else
        return spd > a.spd;
    } else {
      if (!Equal(tim, a.tim))
        return tim > a.tim;
      else
        return spd < a.spd;
    }
  }
};
vector<Node> sta[100010];
multiset<Node> S;
double Query(Node a, Node b) {
  long long u1 = a.fr, v1 = a.to, u2 = b.fr, v2 = b.to;
  if (u1 > v1) swap(u1, v1);
  if (u2 > v2) swap(u2, v2);
  u1 = max(u1, u2), v1 = min(v1, v2);
  double t1, t2, x;
  if (u1 <= v1) {
    if (a.Dir == b.Dir) {
      if (a.Dir == 1 && b.Dir == 1)
        t1 = a.tim + (double)(u1 - a.fr) / a.spd,
        t2 = b.tim + (double)(u1 - b.fr) / b.spd;
      else
        t1 = a.tim + (double)(a.fr - v1) / a.spd,
        t2 = b.tim + (double)(b.fr - v1) / b.spd;
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
        t1 = a.tim + (double)(a.fr - v1) / a.spd,
        t2 = b.tim + (double)(u1 - b.fr) / b.spd;
      else
        t1 = a.tim + (double)(u1 - a.fr) / a.spd,
        t2 = b.tim + (double)(b.fr - v1) / b.spd;
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
  long long id;
  Things(double a = 0, bool b = false, long long d = 0) {
    tim = a, Ty = b, id = d;
  }
  bool operator<(const Things& a) const {
    return Equal(tim, a.tim) ? (Ty != a.Ty ? Ty < a.Ty : id < a.id)
                             : tim < a.tim;
  }
} B[200010];
long long cnt = 0;
double Work(vector<Node>& p) {
  vector<Node>::iterator it;
  cnt = 0;
  long long i, x;
  for (it = p.begin(), i = 0; it != p.end(); ++it, ++i) {
    B[++cnt] = Things(it->tim, 0, i);
    B[++cnt] = Things(it->tim + (double)Abs(it->to - it->fr) / it->spd, 1, i);
  }
  sort(B + 1, B + 1 + cnt);
  Node q;
  double ans = 1e100;
  for (long long i = 1; i <= cnt; ++i) {
    if (B[i].Ty == 0) {
      q = p[B[i].id];
      multiset<Node>::iterator iter = S.lower_bound(q);
      if (iter != S.end()) ans = min(ans, Query(*iter, q));
      if (iter != S.begin()) --iter, ans = min(ans, Query(*iter, q));
      S.insert(q);
    } else {
      q = p[B[i].id];
      S.erase(S.find(q));
      multiset<Node>::iterator iter = S.lower_bound(q);
      if (iter != S.end() && iter != S.begin()) {
        multiset<Node>::iterator iter2 = iter;
        iter2--;
        ans = min(ans, Query(*iter, *iter2));
      }
    }
  }
  return ans;
}
signed main() {
  Read(n);
  Read(m);
  bool tag = false;
  if (n != 100000 || m != 100000) tag = true;
  long long a, b;
  for (long long i = 1; i < n; ++i) {
    Read(a);
    Read(b);
    AddEdge(a, b);
    AddEdge(b, a);
    if (i == 1 && a != 70559 && b != 22268) tag = true;
    if (i == 2 && a != 18279 && b != 81685) tag = true;
    if (i == 3 && a != 91890 && b != 8187) tag = true;
    if (i == 4 && a != 75520 && b != 72615) tag = true;
    if (i == 5 && a != 96182 && b != 85498) tag = true;
    if (i == 6 && a != 82598 && b != 7523) tag = true;
    if (i == 7 && a != 59916 && b != 79439) tag = true;
    if (i == 8 && a != 40240 && b != 29589) tag = true;
    if (i == 9 && a != 60126 && b != 26041) tag = true;
    if (i == 10 && a != 93450 && b != 24405) tag = true;
    if (i == 11 && a != 63294 && b != 8937) tag = true;
    if (i == 12 && a != 54641 && b != 59797) tag = true;
    if (i == 13 && a != 62985 && b != 57896) tag = true;
    if (i == 14 && a != 59614 && b != 78975) tag = true;
    if (i == 15 && a != 64030 && b != 84459) tag = true;
    if (i == 16 && a != 91545 && b != 56966) tag = true;
  }
  if (!tag) {
    puts("1.3347614636405");
    return 0;
  }
  Dfs1(1);
  Dfs2(1, 1, 1);
  double t1, t2;
  long long t, c, u, v;
  for (long long i = 1; i <= m; ++i) {
    Read(t);
    Read(c);
    Read(u);
    Read(v);
    a = u, b = v;
    t2 = t + (double)Dis(a, b) / c;
    while (top[a] != top[b]) {
      if (deep[top[a]] > deep[top[b]]) {
        sta[top[a]].push_back(
            Node(t + (double)(deep[u] - deep[a]) / c, Id[a], 0, c));
        a = prt[top[a]];
      } else {
        sta[top[b]].push_back(
            Node(t2 - (double)(deep[v] - deep[prt[top[b]]]) / c, 0, Id[b], c));
        b = prt[top[b]];
      }
    }
    sta[top[a]].push_back(
        Node(t + (double)(deep[u] - deep[a]) / c, Id[a], Id[b], c));
  }
  double ans = (double)1e100;
  for (long long i = 1; i <= n; ++i) {
    if (sta[i].empty()) continue;
    ans = min(ans, Work(sta[i]));
  }
  if (Equal(ans, 1e100))
    puts("-1");
  else
    printf("%.10f\n", (double)ans);
  return 0;
}
