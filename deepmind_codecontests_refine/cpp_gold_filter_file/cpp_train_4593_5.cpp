#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  P() {}
  P(int _x, int _y) {
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
  bool operator<(const P &a) const { return x == a.x ? y < a.y : x < a.x; }
};
long long Dis(P x, P y) { return (x - y) ^ (x - y); }
vector<P> init(vector<P> p) {
  vector<P> ans;
  int pos = min_element(p.begin(), p.end()) - p.begin();
  for (int i = (int)(0); i <= (int)(p.size() - 1); i++)
    ans.push_back(p[(i + pos) % p.size()]);
  return ans;
}
vector<P> Mincowski(vector<P> a, vector<P> b) {
  a = init(a);
  b = init(b);
  int sza = a.size(), szb = b.size();
  vector<P> ans, A(sza), B(szb);
  for (int i = (int)(0); i <= (int)(sza - 1); i++)
    A[i] = a[(i + 1) % sza] - a[i];
  for (int i = (int)(0); i <= (int)(szb - 1); i++)
    B[i] = b[(i + 1) % szb] - b[i];
  int i = 0, j = 0;
  ans.push_back(a[0] + b[0]);
  for (; i < sza || j < szb;)
    if (j == szb)
      ans.push_back(ans.back() + A[i++]);
    else if (i == sza)
      ans.push_back(ans.back() + B[j++]);
    else
      ans.push_back(ans.back() + (A[i] * B[j] >= 0 ? A[i++] : B[j++]));
  ans.pop_back();
  return ans;
}
bool online(P p, P l, P r) {
  return ((p - l) * (p - r)) == 0 && ((p - l) ^ (p - r)) <= 0;
}
bool check(P p, long long R, vector<P> q) {
  for (auto i : q)
    if (Dis(i, p) < R * R) return 1;
  bool flag = 1;
  for (int i = (int)(0); i <= (int)(q.size() - 1); i++) {
    P l = q[i], r = q[(i + 1) % q.size()];
    if (online(p, l, r)) return 1;
    if (((p - l) ^ (r - l)) > 0 && ((p - r) ^ (l - r)) > 0) {
      long long x = abs((p - l) * (r - l));
      if (x * x < R * R * Dis(l, r)) return 1;
    }
    flag &= ((p - l) * (r - l) <= 0);
  }
  return flag;
}
const int N = 405;
struct edge {
  int to, next, f;
} e[N * N];
int head[N], dis[N], q[N];
int n, m, W, S, T, tot = 1;
void add(int x, int y, int v) {
  e[++tot] = (edge){y, head[x], v};
  head[x] = tot;
  e[++tot] = (edge){x, head[y], 0};
  head[y] = tot;
}
bool bfs() {
  for (int i = (int)(1); i <= (int)(T); i++) dis[i] = -1;
  int h = 0, t = 1;
  q[1] = S;
  dis[S] = 0;
  while (h != t) {
    int x = q[++h];
    for (int i = head[x]; i; i = e[i].next)
      if (dis[e[i].to] == -1 && e[i].f) {
        dis[e[i].to] = dis[x] + 1;
        if (e[i].to == T) return 1;
        q[++t] = e[i].to;
      }
  }
  return 0;
}
int dfs(int x, int flow) {
  if (x == T) return flow;
  int rest = flow;
  for (int i = head[x]; i && rest; i = e[i].next)
    if (dis[e[i].to] == dis[x] + 1 && e[i].f) {
      int k = dfs(e[i].to, min(rest, e[i].f));
      e[i].f -= k;
      e[i ^ 1].f += k;
      rest -= k;
    }
  if (rest) dis[x] = -1;
  return flow - rest;
}
int main() {
  scanf("%d%d", &n, &W);
  vector<P> p(n), q(n);
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = P(x, y);
    q[i] = P(-x, -y);
  }
  int mn = p[0].x, mx = p[0].x;
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    mn = min(mn, p[i].x);
    mx = max(mx, p[i].x);
  }
  p = Mincowski(p, q);
  scanf("%d", &m);
  vector<P> o(m + 1);
  vector<int> R(m + 1);
  for (int i = (int)(1); i <= (int)(m); i++)
    scanf("%d%d%d", &o[i].x, &o[i].y, &R[i]);
  S = m * 2 + 1;
  T = S + 1;
  for (int i = (int)(1); i <= (int)(m); i++) {
    add(i * 2 - 1, i * 2, 1);
    if (mx - mn > o[i].x - R[i]) add(S, 2 * i - 1, 1 << 30);
    if (mx - mn > W - o[i].x - R[i]) add(2 * i, T, 1 << 30);
  }
  for (int i = (int)(1); i <= (int)(m); i++)
    for (int j = (int)(i + 1); j <= (int)(m); j++)
      if (check(o[i] - o[j], R[i] + R[j], p)) {
        add(i * 2, j * 2 - 1, 1 << 30);
        add(j * 2, i * 2 - 1, 1 << 30);
      }
  int ans = 0;
  for (; bfs(); ans += dfs(S, 1 << 30))
    ;
  printf("%d\n", ans);
}
