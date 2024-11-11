#include <bits/stdc++.h>
template <class T>
inline void rd(T &x) {
  char c = getchar(), f = 0;
  x = 0;
  while (!isdigit(c)) f = (c == '-'), c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x = f ? -x : x;
}
const int MAXN = 6e5 + 7;
const long long HA = 1e9 + 7, INV2 = (1 + HA) / 2;
std::vector<std::pair<int, int> > v;
int n, m, a[MAXN], val[MAXN], pos[MAXN];
struct Node {
  int l, r;
  Node *lc, *rc;
  long long pow, sum, pre, suf;
  Node() {}
  Node(int l, int r, Node *lc = NULL, Node *rc = NULL)
      : l(l), r(r), lc(lc), rc(rc), pow(1), sum(0), pre(0), suf(0) {}
  static Node *build(int l, int r) {
    if (l == r)
      return new Node(l, r);
    else
      return new Node(l, r, build(l, ((l + r) / 2)),
                      build(((l + r) / 2) + 1, r));
  }
  void up() {
    pow = lc->pow * rc->pow % HA;
    sum = lc->sum + rc->sum + lc->suf * rc->pre % HA;
    sum %= HA;
    suf = lc->suf * rc->pow % HA + rc->suf;
    suf %= HA;
    pre = lc->pre + rc->pre * lc->pow % HA;
    pre %= HA;
  }
  void change(int p, bool op) {
    if (l == r) {
      if (op)
        pow = INV2, sum = 0, pre = suf = v[l].first * INV2 % HA;
      else
        pow = 1, sum = pre = suf = 0;
      return;
    }
    (p <= ((l + r) / 2) ? lc : rc)->change(p, op);
    up();
  }
} * root;
int get(std::pair<int, int> a) {
  return std::lower_bound((v).begin(), (v).end(), a) - v.begin();
}
int main() {
  rd(n);
  for (int i = (1); i <= (n); ++i) rd(a[i]), v.emplace_back(a[i], i);
  rd(m);
  for (int i = (1); i <= (n); ++i)
    rd(pos[i]), rd(val[i]), v.emplace_back(val[i], i + n), pos[i] - 1;
  std::sort((v).begin(), (v).end());
  v.resize(std::unique((v).begin(), (v).end()) - v.begin());
  int nn = v.size();
  root = Node::build(0, nn - 1);
  for (int i = (1); i <= (n); ++i)
    root->change(a[i] = get(std::make_pair(a[i], i)), 1);
  printf("%lld\n", root->sum);
  for (int i = (1); i <= (m); ++i) {
    root->change(a[pos[i]], 0);
    a[pos[i]] = get(std::make_pair(val[i], i + n));
    root->change(a[pos[i]], 1);
    printf("%lld\n", root->sum);
  }
  return 0;
}
