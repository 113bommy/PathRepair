#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos((long double)-1.0);
const double EPS = 1e-10;
const int MOD = 1e9 + 7;
template <typename T>
void cmin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void cmax(T &x, T y) {
  if (y > x) x = y;
}
long long qpow(long long x, long long n, long long mod = MOD) {
  if (n < 0) return 0;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long sq(long long x) { return x * x; }
long long read() {
  long long res = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    res = res * 10 + (c - '0');
    c = getchar();
  }
  return res;
}
namespace MoAlgorithm {
int n, m, BLOCK;
struct Node {
  int l, r, id;
  bool operator<(const Node &node) const {
    if (l / BLOCK != node.l / BLOCK) return l < node.l;
    if ((l / BLOCK) & 1) return r < node.r;
    return r > node.r;
  }
} node[1000005];
int L, R;
long long cur, ans[100005];
int a[600005];
int cnt[300005];
void subL() {
  --L;
  int val = a[L];
  ++cnt[val];
  cur += (cnt[val] == 1);
}
void addL() {
  int val = a[L];
  cur -= (cnt[val] == 1);
  --cnt[val];
  ++L;
}
void subR() {
  int val = a[R];
  cur -= (cnt[val] == 1);
  --cnt[val];
  --R;
}
void addR() {
  ++R;
  int val = a[R];
  ++cnt[val];
  cur += (cnt[val] == 1);
}
int mi[300005];
int lst[300005];
void Solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    a[i] = (n + 1) - i;
    mi[i] = i;
    lst[a[i]] = i;
  }
  int t = 0;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[n + i]);
    int val = a[n + i];
    mi[val] = 1;
    int L = lst[val] + 1, R = n + i - 1, id = val;
    ++t;
    node[t].id = id;
    node[t].l = L;
    node[t].r = R;
    lst[val] = n + i;
  }
  for (int i = 1; i <= n; ++i) {
    int L = lst[i] + 1, R = n + m, id = i;
    ++t;
    node[t].id = id;
    node[t].l = L;
    node[t].r = R;
  }
  int cn = n;
  n += m;
  m = t;
  BLOCK = ceil(pow(n, 0.5));
  sort(node + 1, node + 1 + m);
  L = 1, R = 0, cur = 0;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= m; ++i) {
    while (L > node[i].l) subL();
    while (L < node[i].l) addL();
    while (R > node[i].r) subR();
    while (R < node[i].r) addR();
    cmax(ans[node[i].id], cur + 1);
  }
  for (int i = 1; i <= cn; ++i) printf("%d %d\n", mi[i], ans[i]);
}
};  // namespace MoAlgorithm
namespace Solver {
void InitOnce() { int t; }
void Read() {
  int res = 1;
  if (res == -1) exit(0);
}
void Solve() {
  MoAlgorithm::Solve();
  exit(0);
}
}  // namespace Solver
int main() {
  Solver::InitOnce();
  while (true) {
    Solver::Read();
    Solver::Solve();
  }
  return 0;
}
