#include <bits/stdc++.h>
using U = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using std::bitset;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::string;
using std::vector;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;
class MyTimer {
 public:
  void reset() {}
  void report() {}
} myTimer;
template <typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) {
  return a > b ? a = b, true : false;
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) {
  return a < b ? a = b, true : false;
}
inline int readint() {
  int a = 0;
  char c = getchar(), p = 0;
  while (isspace(c)) c = getchar();
  if (c == '-') p = 1, c = getchar();
  while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
  return p ? -a : a;
}
inline LL readLL() {
  LL a = 0;
  char c = getchar(), p = 0;
  while (isspace(c)) c = getchar();
  if (c == '-') p = 1, c = getchar();
  while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
  return p ? -a : a;
}
const int maxN = 100000 + 233;
const int INF = 0x3f3f3f3f;
int n, p[maxN], nlim, dep[maxN];
LL w[maxN], wlim;
int f[maxN], sum[maxN];
struct Node {
  int ans;
  LL weight;
  int node;
  Node(int ans, LL w, int node) : ans(ans), weight(w), node(node) {}
  bool operator<(const Node &rhs) const {
    return ans != rhs.ans         ? ans > rhs.ans
           : weight != rhs.weight ? weight < rhs.weight
                                  : node < rhs.node;
  }
};
void merge(priority_queue<Node> &Q, int &dans, LL &dweight,
           priority_queue<Node> &P, int &pans, LL &pweight) {
  if (Q.size() < P.size()) {
    std::swap(Q, P);
    std::swap(dans, pans);
    std::swap(dweight, pweight);
  }
  while (!P.empty()) {
    Node x = P.top();
    P.pop();
    Q.push(Node(x.ans + pans - dans, x.weight + pweight - dweight, x.node));
  }
}
priority_queue<Node> pq[maxN];
int dans[maxN];
LL dweight[maxN];
void solve() {
  memset(sum, 0, sizeof(sum));
  memset(f, INF, sizeof(f));
  memset(dans, 0, sizeof(dans));
  memset(dweight, 0, sizeof(dweight));
  for (int u = 1; u <= n; ++u) pq[u].push(Node(1, w[u], u));
  for (int u = n; u >= 1; --u) {
    priority_queue<Node> &Q = pq[u];
    while (1) {
      Node x = Q.top();
      if (dep[x.node] - dep[u] + 1 > nlim || x.weight + dweight[u] > wlim) {
        Q.pop();
        continue;
      }
      f[u] = x.ans + dans[u];
      break;
    }
    if (u == 1) break;
    dweight[u] += w[u];
    dans[u] += sum[p[u]];
    dans[p[u]] += f[u];
    sum[p[u]] += f[u];
    merge(pq[p[u]], dans[p[u]], dweight[p[u]], pq[u], dans[u], dweight[u]);
  }
}
int main() {
  scanf("%d%d%lld", &n, &nlim, &wlim);
  for (int i = 1; i <= n; ++i) scanf("%lld", &w[i]);
  for (int i = 2; i <= n; ++i) scanf("%d", &p[i]);
  for (int i = 1; i <= n; ++i)
    if (w[i] > wlim) {
      cout << -1 << endl;
      return 0;
    }
  dep[1] = 1;
  for (int i = 2; i <= n; ++i) dep[i] = dep[p[i]] + 1;
  solve();
  cout << f[1] << endl;
  return 0;
}
