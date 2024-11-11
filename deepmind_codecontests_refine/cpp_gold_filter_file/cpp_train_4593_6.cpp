#include <bits/stdc++.h>
using namespace std;
struct P {
  long long x, y;
  P() {}
  P(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  long long operator*(const P &a) const {
    return 1ll * x * a.y - 1ll * y * a.x;
  }
  long long operator^(const P &a) const {
    return 1ll * x * a.x + 1ll * y * a.y;
  }
  bool operator<(const P &a) const { return x ^ a.x ? x < a.x : y < a.y; }
};
long long Dis(P x, P y) { return (x - y) ^ (x - y); }
vector<P> init(vector<P> p) {
  vector<P> ans;
  int pos = min_element(p.begin(), p.end()) - p.begin();
  for (int i = (int)(0); i <= (int)(p.size() - 1); i++)
    ans.push_back(p[(i + pos) % p.size()]);
  return ans;
}
vector<P> merge(vector<P> p, vector<P> q) {
  p = init(p);
  q = init(q);
  int szp = p.size(), szq = q.size();
  vector<P> d1(szp), d2(szq);
  for (int i = (int)(0); i <= (int)(szp - 1); i++)
    d1[i] = p[(i + 1) % szp] - p[i];
  for (int i = (int)(0); i <= (int)(szq - 1); i++)
    d2[i] = q[(i + 1) % szq] - q[i];
  vector<P> ans;
  ans.push_back(p[0] + q[0]);
  int pos1 = 0, pos2 = 0;
  for (; pos1 < szp || pos2 < szq;)
    if (pos2 == szq)
      ans.push_back(ans.back() + d1[pos1++]);
    else if (pos1 == szp)
      ans.push_back(ans.back() + d2[pos2++]);
    else
      ans.push_back(ans.back() +
                    (d2[pos2] * d1[pos1] >= 0 ? d2[pos2++] : d1[pos1++]));
  return ans;
}
bool online(P p, P l, P r) {
  return (p - l) * (r - l) == 0 && ((l - p) ^ (r - p)) <= 0;
}
bool check(P p, long long r, vector<P> pp) {
  for (auto i : pp)
    if (Dis(p, i) < r * r) return 1;
  for (int i = (int)(0); i <= (int)(pp.size() - 1); i++) {
    P L = pp[i], R = pp[(i + 1) % pp.size()];
    if (((p - L) ^ (R - L)) > 0 && ((p - R) ^ (L - R)) > 0)
      if (((p - L) * (R - L)) * ((p - L) * (R - L)) < r * r * Dis(L, R))
        return 1;
  }
  for (int i = (int)(0); i <= (int)(pp.size() - 1); i++)
    if (online(p, pp[i], pp[(i + 1) % pp.size()])) return 1;
  bool flag = 1;
  for (int i = (int)(0); i <= (int)(pp.size() - 1); i++)
    flag &= ((p - pp[i]) * (pp[(i + 1) % pp.size()] - pp[i]) <= 0);
  return flag;
}
const int N = 255;
struct edge {
  int to, next, f;
} e[4 * N * N];
int head[N * 2], tot = 1, S, T;
int dis[N * 2], q[N * 2];
void add(int x, int y, int v) {
  e[++tot] = (edge){y, head[x], v};
  head[x] = tot;
  e[++tot] = (edge){x, head[y], 0};
  head[y] = tot;
}
bool bfs() {
  for (int i = (int)(1); i <= (int)(T); i++) dis[i] = -1;
  int t = 1;
  dis[q[1] = S] = 0;
  for (int h = (int)(1); h <= (int)(t); h++)
    for (int i = head[q[h]]; i; i = e[i].next)
      if (dis[e[i].to] == -1 && e[i].f) {
        dis[e[i].to] = dis[q[h]] + 1;
        if (e[i].to == T) return 1;
        q[++t] = e[i].to;
      }
  return 0;
}
int dfs(int x, int flow) {
  if (x == T) return flow;
  int k, rest = flow;
  for (int i = head[x]; i && rest; i = e[i].next)
    if (dis[e[i].to] == dis[x] + 1 && e[i].f) {
      k = dfs(e[i].to, min(flow, e[i].f));
      e[i].f -= k;
      e[i ^ 1].f += k;
      rest -= k;
    }
  if (rest) dis[x] = -1;
  return flow - rest;
}
int n, W, m;
struct circle {
  long long x, y, r;
} o[N];
int main() {
  scanf("%d%d", &n, &W);
  vector<P> p, q;
  p.resize(n);
  q.resize(n);
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    scanf("%lld%lld", &p[i].x, &p[i].y);
    q[i].x = -p[i].x;
    q[i].y = -p[i].y;
  }
  long long mn = p[0].x, mx = p[0].x;
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    mn = min(mn, p[i].x);
    mx = max(mx, p[i].x);
  }
  p = merge(p, q);
  scanf("%d", &m);
  S = 2 * m + 1;
  T = 2 * m + 2;
  for (int i = (int)(1); i <= (int)(m); i++)
    scanf("%lld%lld%lld", &o[i].x, &o[i].y, &o[i].r);
  for (int i = (int)(1); i <= (int)(m); i++) {
    add(i * 2 - 1, i * 2, 1);
    if (mx - mn > o[i].x - o[i].r) add(S, i * 2 - 1, 1 << 30);
    if (mx - mn > W - o[i].x - o[i].r) add(i * 2, T, 1 << 30);
  }
  for (int i = (int)(1); i <= (int)(m); i++)
    for (int j = (int)(i + 1); j <= (int)(m); j++)
      if (check(P(o[j].x - o[i].x, o[j].y - o[i].y), o[i].r + o[j].r, p)) {
        add(i * 2, j * 2 - 1, 1 << 30);
        add(j * 2, i * 2 - 1, 1 << 30);
      }
  int ans = 0;
  for (; bfs(); ans += dfs(S, 1 << 30))
    ;
  printf("%d\n", ans);
}
