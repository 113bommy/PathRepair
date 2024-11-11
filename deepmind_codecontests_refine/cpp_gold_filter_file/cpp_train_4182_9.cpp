#include <bits/stdc++.h>
using namespace std;
struct IO_Tp {
  static const int _Buf_Size = 1 << 26;
  char _Buf_I[_Buf_Size], *_Buf_I_Pos;
  char _Buf_O[_Buf_Size], *_Buf_O_Pos;
  int _val;
  char _str[20], *_pos;
  IO_Tp() : _Buf_I_Pos(_Buf_I), _Buf_O_Pos(_Buf_O), _pos(_str) {
    fread(_Buf_I, 1, _Buf_Size, stdin);
  }
  ~IO_Tp() { fwrite(_Buf_O, 1, _Buf_O_Pos - _Buf_O, stdout); }
  template <class Type>
  inline IO_Tp& operator>>(Type& res) {
    res = 0;
    _val = 1;
    while (!isdigit(*_Buf_I_Pos))
      _val = (*_Buf_I_Pos == '-' ? -1 : 1), ++_Buf_I_Pos;
    do (res *= 10) += (*_Buf_I_Pos++) & 15;
    while (isdigit(*_Buf_I_Pos));
    res *= _val;
    return *this;
  }
  template <class Type>
  inline IO_Tp& operator<<(Type val) {
    if (val < 0) *_Buf_O_Pos++ = '-', val = -val;
    do *_pos++ = 48 + val % 10;
    while (val /= 10);
    while (_pos != _str) *_Buf_O_Pos++ = *--_pos;
    return *this;
  }
  inline IO_Tp& operator<<(char ch) {
    *_Buf_O_Pos++ = ch;
    return *this;
  }
  inline IO_Tp& operator>>(char& ch) {
    while (!isupper(*_Buf_I_Pos)) _Buf_I_Pos++;
    ch = *_Buf_I_Pos++;
    return *this;
  }
} IO;
const int N = 2e5 + 5;
const long long inf = 1e18;
struct Edge {
  int id, to, nxt;
  long long val;
} e[N << 1];
struct Node {
  int pos;
  long long val;
  Node(int p, long long v) : pos(p), val(v) {}
  bool operator<(const Node& oth) const { return val > oth.val; }
};
bool onpth[N];
int l[N], r[N];
int head[N], cnt;
int inp[N], vis[N];
long long dis1[N], dis2[N];
int n, m, q, cntpth;
int u[N], v[N];
long long w[N], disv[N << 2];
priority_queue<Node> pq;
void Add(int i) {
  e[++cnt].id = i;
  e[cnt].to = v[i];
  e[cnt].val = w[i];
  e[cnt].nxt = head[u[i]];
  head[u[i]] = cnt;
  e[++cnt].id = i;
  e[cnt].to = u[i];
  e[cnt].val = w[i];
  e[cnt].nxt = head[v[i]];
  head[v[i]] = cnt;
}
void init() {
  int rev = 1;
  onpth[1] = true;
  for (int i = 1; rev != n; ++i) {
    int Id = vis[rev];
    inp[Id] = i;
    ++cntpth;
    rev = u[Id] ^ v[Id] ^ rev;
    onpth[rev] = true;
    l[rev] = r[rev] = i;
  }
}
void Dijkstra(int s, long long* Dis, int opt) {
  for (int i = 1; i <= n; ++i) Dis[i] = inf;
  pq.push(Node(s, 0));
  Dis[s] = 0;
  while (!pq.empty()) {
    Node x = pq.top();
    pq.pop();
    int now = x.pos;
    long long dis = x.val;
    if (dis > Dis[now]) continue;
    for (int i = head[now]; i; i = e[i].nxt) {
      int y = e[i].to;
      long long ddis = e[i].val;
      if (Dis[y] > ddis + dis) {
        vis[y] = e[i].id;
        Dis[y] = dis + ddis;
        if (!onpth[y]) {
          if (opt == 1)
            l[y] = l[now];
          else if (opt == 2)
            r[y] = r[now];
        }
        pq.push(Node(y, Dis[y]));
      }
    }
  }
}
void build(int id, int l, int r) {
  disv[id] = inf;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
}
void update(int id, int l, int r, int x, int y, long long v) {
  if (x > y) return;
  if (x <= l && r <= y) {
    disv[id] = min(disv[id], v);
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= x) update(id << 1, l, mid, x, y, v);
  if (mid < y) update(id << 1 | 1, mid + 1, r, x, y, v);
}
long long query(int id, int l, int r, int x) {
  if (l == r) return disv[id];
  int mid = (l + r) >> 1;
  if (mid >= x)
    return min(disv[id], query(id << 1, l, mid, x));
  else
    return min(disv[id], query(id << 1 | 1, mid + 1, r, x));
}
int main() {
  memset(inp, -1, sizeof inp);
  IO >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    IO >> u[i] >> v[i] >> w[i];
    Add(i);
  }
  Dijkstra(n, dis2, 0);
  init();
  Dijkstra(1, dis1, 1);
  Dijkstra(n, dis2, 2);
  build(1, 1, cntpth);
  for (int i = 1; i <= m; ++i) {
    if (inp[i] == -1) {
      update(1, 1, cntpth, l[u[i]] + 1, r[v[i]],
             dis1[u[i]] + w[i] + dis2[v[i]]);
      update(1, 1, cntpth, l[v[i]] + 1, r[u[i]],
             dis1[v[i]] + w[i] + dis2[u[i]]);
    }
  }
  for (; q; --q) {
    int t;
    long long x;
    IO >> t >> x;
    long long ans = dis1[n];
    if (inp[t] == -1) {
      if (x < w[t]) {
        ans = min(ans, dis1[u[t]] + x + dis2[v[t]]);
        ans = min(ans, dis1[v[t]] + x + dis2[u[t]]);
      }
    } else {
      ans = dis1[n] - w[t] + x;
      if (x > w[t]) {
        ans = min(ans, query(1, 1, cntpth, inp[t]));
      }
    }
    IO << ans << '\n';
  }
  return 0;
}
