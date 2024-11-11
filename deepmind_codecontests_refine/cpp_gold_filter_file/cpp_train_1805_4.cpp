#include <bits/stdc++.h>
using namespace std;
namespace iB {
char buf[1 << 21], *p1 = buf, *p2 = buf;
}
namespace oB {
char buf[1 << 21], *p1 = buf, *p2 = buf + (1 << 21);
}
namespace Fastio {
struct Reader {
  char endch;
  Reader() { endch = '\0'; }
  Reader &operator>>(char &ch) {
    ch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                        fread(iB::buf, 1, 1 << 21, stdin),
                               iB::p1 == iB::p2)
              ? EOF
              : *iB::p1++);
    while (ch == ' ' || ch == '\r' || ch == '\n' || ch == '\t')
      ch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                          fread(iB::buf, 1, 1 << 21, stdin),
                                 iB::p1 == iB::p2)
                ? EOF
                : *iB::p1++);
    return *this;
  }
  Reader &operator>>(char *str) {
    while (((*str = (iB::p1 == iB::p2 &&
                             (iB::p2 = (iB::p1 = iB::buf) +
                                       fread(iB::buf, 1, 1 << 21, stdin),
                              iB::p1 == iB::p2)
                         ? EOF
                         : *iB::p1++)) == ' ' ||
            *str == '\n' || *str == '\r' || *str == '\t') &&
           *str != EOF)
      ;
    while ((*++str = (iB::p1 == iB::p2 &&
                              (iB::p2 = (iB::p1 = iB::buf) +
                                        fread(iB::buf, 1, 1 << 21, stdin),
                               iB::p1 == iB::p2)
                          ? EOF
                          : *iB::p1++)) != ' ' &&
           *str != '\n' && *str != '\r' && *str != '\t' && *str != EOF)
      ;
    *str = '\0';
    return *this;
  }
  template <typename Int>
  Reader &operator>>(Int &d) {
    bool flag = 0;
    endch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                           fread(iB::buf, 1, 1 << 21, stdin),
                                  iB::p1 == iB::p2)
                 ? EOF
                 : *iB::p1++);
    while ((!isdigit(endch)) && endch != '-' && endch != EOF)
      endch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                             fread(iB::buf, 1, 1 << 21, stdin),
                                    iB::p1 == iB::p2)
                   ? EOF
                   : *iB::p1++);
    if (endch == '-')
      flag = 1,
      endch = (iB::p1 == iB::p2 && (iB::p2 = (iB::p1 = iB::buf) +
                                             fread(iB::buf, 1, 1 << 21, stdin),
                                    iB::p1 == iB::p2)
                   ? EOF
                   : *iB::p1++);
    d = endch & 15;
    while (isdigit(endch = (iB::p1 == iB::p2 &&
                                    (iB::p2 = (iB::p1 = iB::buf) +
                                              fread(iB::buf, 1, 1 << 21, stdin),
                                     iB::p1 == iB::p2)
                                ? EOF
                                : *iB::p1++)))
      d = (d << 3) + (d << 1) + (endch & 15);
    if (flag) d = -d;
    return *this;
  }
  template <typename T>
  inline T get() {
    T Val;
    (*this) >> Val;
    return Val;
  }
};
struct Writer {
  ~Writer() { fwrite(oB::buf, 1, oB::p1 - oB::buf, stdout); }
  Writer &operator<<(const char ch) {
    ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
     *oB::p1++ = ch);
    return *this;
  }
  Writer &operator<<(const char *ch) {
    while (*ch)
      ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
       *oB::p1++ = *(ch++));
    return *this;
  }
  Writer &operator<<(char *ss) { return *this << (const char *)ss; }
  template <typename Int>
  Writer &operator<<(Int x) {
    static char buffer[33];
    static int top = 0;
    if (!x) {
      ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
       *oB::p1++ = '0');
      return *this;
    }
    if (x < 0)
      ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
       *oB::p1++ = '-'),
          x = -x;
    while (x) {
      buffer[++top] = '0' | (x % 10);
      x /= 10;
    }
    while (top)
      ((oB::p1 == oB::p2 && fwrite(oB::p1 = oB::buf, 1, 1 << 21, stdout)),
       *oB::p1++ = buffer[top--]);
    return *this;
  }
};
}  // namespace Fastio
Fastio::Reader kin;
Fastio::Writer kout;
namespace Network_MinCostMaxFlow {
const int Net_Node = 2005, Net_Edge = 6010;
const long long inf = 0x3f3f3f3f3f3f3f3f;
struct edge {
  int to, nxt_edge;
  long long flow, fee;
} e[Net_Edge * 2 + 5];
int head[Net_Node + 5], ecnt = 1;
int node_total, st, ed;
long long flow[Net_Node + 5], dis[Net_Node + 5];
int from[Net_Node + 5];
bool inq[Net_Node + 5];
inline void clear() {
  memset(head, 0, sizeof(head));
  ecnt = 1;
  st = ed = 0;
}
inline void add_edge(const int &from, const int &to, const long long &flow,
                     const long long &fee) {
  e[++ecnt].to = to;
  e[ecnt].flow = flow;
  e[ecnt].fee = fee;
  e[ecnt].nxt_edge = head[from];
  head[from] = ecnt;
  e[++ecnt].to = from;
  e[ecnt].flow = 0;
  e[ecnt].fee = -fee;
  e[ecnt].nxt_edge = head[to];
  head[to] = ecnt;
}
inline bool spfa() {
  memset(dis, 0x3f, sizeof(long long) * (node_total + 1));
  memset(flow, 0, sizeof(long long) * (node_total + 1));
  memset(inq, 0, sizeof(bool) * (node_total + 1));
  from[st] = -1;
  dis[st] = 0;
  flow[st] = inf;
  std::queue<int> q;
  q.push(st);
  inq[st] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = e[i].nxt_edge)
      if (dis[e[i].to] > dis[u] + e[i].fee && e[i].flow) {
        dis[e[i].to] = dis[u] + e[i].fee;
        flow[e[i].to] = std::min(flow[u], e[i].flow);
        from[e[i].to] = i;
        if (!inq[e[i].to]) {
          q.push(e[i].to);
          inq[e[i].to] = true;
        }
      }
    inq[u] = false;
  }
  return dis[ed] != inf;
}
struct MCMF_result {
  long long max_flow, min_cost;
  MCMF_result(long long MF, long long MC) : max_flow(MF), min_cost(MC) {}
};
MCMF_result work(int node_count, int start_node = 1, int finish_node = -1) {
  node_total = node_count;
  st = start_node;
  ed = ~finish_node ? finish_node : node_count;
  long long max_flow = 0, min_cost = 0;
  while (spfa()) {
    long long now_flow = flow[ed];
    max_flow += now_flow;
    for (int i = from[ed]; ~i; i = from[e[i ^ 1].to]) {
      e[i].flow -= now_flow;
      e[i ^ 1].flow += now_flow;
      min_cost += e[i].fee * now_flow;
    }
  }
  return MCMF_result(max_flow, min_cost);
}
}  // namespace Network_MinCostMaxFlow
const int N = 1000 + 5;
int n, k;
long long l[N], r[N], w[N], val[N << 1];
int m;
signed main() {
  kin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    kin >> l[i] >> r[i] >> w[i];
    r[i] += l[i] - 1;
    val[++m] = l[i], val[++m] = r[i];
  }
  sort(val + 1, val + m + 1);
  m = unique(val + 1, val + m + 1) - val - 1;
  int S = m + 2, T = m + 3;
  for (int i = 1; i <= n; ++i) {
    l[i] = lower_bound(val + 1, val + m + 1, l[i]) - val;
    r[i] = lower_bound(val + 1, val + m + 1, r[i]) - val;
    Network_MinCostMaxFlow::add_edge(l[i], r[i] + 1, 1, -w[i]);
  }
  for (int i = 1; i <= m; ++i) Network_MinCostMaxFlow::add_edge(i, i + 1, k, 0);
  Network_MinCostMaxFlow::add_edge(S, 1, k, 0);
  Network_MinCostMaxFlow::add_edge(m + 1, T, k, 0);
  Network_MinCostMaxFlow::work(m + 3, S, T);
  for (int i = 1; i <= n; ++i)
    if (Network_MinCostMaxFlow::e[i << 1].flow)
      kout << "0 ";
    else
      kout << "1 ";
  kout << '\n';
  return 0;
}
