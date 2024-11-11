#include <bits/stdc++.h>
using namespace std;
inline int read_int() {
  int t = 0;
  bool sign = false;
  char c = getchar();
  while (!isdigit(c)) {
    sign |= c == '-';
    c = getchar();
  }
  while (isdigit(c)) {
    t = (t << 1) + (t << 3) + (c & 15);
    c = getchar();
  }
  return sign ? -t : t;
}
inline long long read_LL() {
  long long t = 0;
  bool sign = false;
  char c = getchar();
  while (!isdigit(c)) {
    sign |= c == '-';
    c = getchar();
  }
  while (isdigit(c)) {
    t = (t << 1) + (t << 3) + (c & 15);
    c = getchar();
  }
  return sign ? -t : t;
}
inline char get_char() {
  char c = getchar();
  while (c == ' ' || c == '\n' || c == '\r') c = getchar();
  return c;
}
inline void write(long long x) {
  register char c[21], len = 0;
  if (!x) return putchar('0'), void();
  if (x < 0) x = -x, putchar('-');
  while (x) c[++len] = x % 10, x /= 10;
  while (len) putchar(c[len--] + 48);
}
inline void space(long long x) { write(x), putchar(' '); }
inline void enter(long long x) { write(x), putchar('\n'); }
const int MAXN = 50, MAXM = 5e4 + 5;
struct opt {
  long long a, b;
  int t;
  bool operator<(const opt &o) const { return a < o.a; }
};
vector<opt> upd, nodes;
void Insert(opt node, long long vl, long long vr) {
  if (node.a == node.b)
    nodes.push_back(node);
  else {
    long long vm = vl + vr >> 1;
    if (node.a <= vm && node.b > vm) {
      nodes.push_back(opt{node.a, vm, node.t});
      nodes.push_back(opt{vm + 1, node.b, node.t});
    } else if (node.b <= vm)
      Insert(node, vl, vm);
    else
      Insert(node, vm + 1, vr);
  }
}
vector<pair<int, int> > edges[MAXM];
void build(int ql, int qr, long long vl, long long vr) {
  if (ql == qr) return;
  long long vm = vl + vr >> 1, len = vm - vl + 1;
  int qm1 = ql, qm2;
  while (qm1 < qr && nodes[qm1 + 1].a <= vm) qm1++;
  qm2 = qm1 + (nodes[qm1].b > vm ? 0 : 1);
  int pos1 = ql, pos2 = qm2;
  while (pos1 <= qm1 && pos2 <= qr) {
    edges[min(nodes[pos1].t, nodes[pos2].t)].emplace_back(pos1, pos2);
    if (nodes[pos1].b + len < nodes[pos2].b)
      pos1++;
    else if (nodes[pos1].b + len > nodes[pos2].b)
      pos2++;
    else
      pos1++, pos2++;
  }
  build(ql, qm1, vl, vm);
  build(qm2, qr, vm, vr);
}
int p[MAXM << 2];
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
pair<long long, long long> query[MAXM];
vector<long long> mp;
char buf[MAXN];
int main() {
  int n = read_int(), m = read_int();
  long long maxv = (1LL << n) - 1;
  for (int i = (0); i < (m); ++i) {
    scanf("%s", buf);
    long long l = read_LL(), r = read_LL();
    if (buf[0] == 'b') {
      upd.push_back(opt{l, r, i});
      query[i] = make_pair(-1LL, -1LL);
    } else
      query[i] = make_pair(l, r);
  }
  query[m] = make_pair(-1LL, -1LL);
  sort(upd.begin(), upd.end());
  long long pos1 = 0;
  int pos2 = 0;
  while (pos1 <= maxv) {
    if (pos2 < upd.size()) {
      if (upd[pos2].a == pos1) {
        Insert(upd[pos2], 0, maxv);
        pos1 = upd[pos2++].b + 1;
      } else {
        Insert(opt{pos1, upd[pos2].a - 1, m}, 0, maxv);
        pos1 = upd[pos2].a;
      }
    } else {
      Insert(opt{pos1, maxv, m}, 0, maxv);
      pos1 = maxv + 1;
    }
  }
  build(0, nodes.size() - 1, 0, maxv);
  for (int i = (0); i < (nodes.size()); ++i) {
    p[i] = i;
    mp.push_back(nodes[i].b);
  }
  stack<int> ans;
  for (int i = m; i >= 0; i--) {
    for (pair<int, int> pr : edges[i]) {
      int x = Find(pr.first), y = Find(pr.second);
      if (x != y) p[x] = y;
    }
    if (query[i].first != -1) {
      int p1 = lower_bound(mp.begin(), mp.end(), query[i].first) - mp.begin();
      int p2 = lower_bound(mp.begin(), mp.end(), query[i].second) - mp.begin();
      p1 = Find(p1);
      p2 = Find(p2);
      if (p1 == p2)
        ans.push(1);
      else
        ans.push(0);
    }
  }
  while (!ans.empty()) {
    enter(ans.top());
    ans.pop();
  }
  return 0;
}
