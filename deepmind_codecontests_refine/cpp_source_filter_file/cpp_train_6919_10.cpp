#include <bits/stdc++.h>
using namespace std;
struct SegTree {
  int l, r, m, v, cov;
  SegTree *_cl, *_cr;
  SegTree *cl() { return _cl ? _cl : _cl = new SegTree(l, m); }
  SegTree *cr() { return _cr ? _cr : _cr = new SegTree(m + 1, r); }
  SegTree(int l, int r)
      : l(l), r(r), m((l + r) / 2), v(0), cov(0), _cl(NULL), _cr(NULL) {}
  ~SegTree() {
    if (_cl) delete _cl;
    if (_cr) delete _cr;
  }
  void update() { v = cov ? r - l + 1 & 1 : cl()->v ^ cr()->v; }
  void add(int ql, int qr, int qv) {
    if (qr < l || ql > r) return;
    if (ql <= l && qr >= r) {
      cov += qv;
      update();
    } else {
      cl()->add(ql, qr, qv);
      cr()->add(ql, qr, qv);
      update();
    }
  }
  int query() { return v; }
} * segt;
struct Event {
  int x, l, r, v;
  Event() {}
  Event(int x, int l, int r, int v) : x(x), l(l), r(r), v(v) {}
  bool operator<(const Event &rhs) const { return x < rhs.x; }
};
vector<Event> events;
int N, M, K, ans;
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= M; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    events.emplace_back(a - 1, b, d, 1);
    events.emplace_back(c, b, d, -1);
  }
  sort(events.begin(), events.end());
  int bitv = 1;
  while (N && K) {
    segt = new SegTree(1, N);
    int last = 0, res = 0;
    for (auto &i : events) {
      res ^= i.x - last & segt->query();
      last = i.x;
      segt->add(i.l, i.r, i.v);
      i.x /= 2;
      i.l /= 2;
      i.r /= 2;
    }
    ans ^= res * (bitv ^ bitv >> 1);
    delete segt;
    N /= 2;
    K /= 2;
    bitv *= 2;
  }
  printf(ans ? "Hamed\n" : "Malek\n");
}
