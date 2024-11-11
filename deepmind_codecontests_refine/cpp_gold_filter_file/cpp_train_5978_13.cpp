#include <bits/stdc++.h>
using namespace std;
int n, q;
struct event {
  int st, en, ind;
  bool q;
  event(int st = 0, int en = 0, int ind = 0, bool q = 0)
      : st(st), en(en), ind(ind), q(q) {}
};
vector<event> v;
int bit[1000008], ans[300008];
void update(int x, int v) {
  while (x < 1000008) {
    bit[x] += v;
    x += (x & (-x));
  }
}
int query(int x) {
  int ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= (x & (-x));
  }
  return ret;
}
bool cmp(const event &a, const event &b) {
  if (a.st != b.st) return a.st < b.st;
  return a.q > b.q;
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    v.push_back(event(l, r));
    update(r, 1);
  }
  for (int i = 0; i < q; i++) {
    int st = 0, cn, a;
    cin >> cn;
    while (cn--) {
      cin >> a;
      if (st <= a - 1) {
        v.push_back(event(st, a - 1, i, 1));
      }
      st = a + 1;
    }
    v.push_back(event(st, 1000001, i, 1));
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    if (v[i].q == 1) {
      ans[v[i].ind] += query(v[i].en);
    } else {
      update(v[i].en, -1);
    }
  }
  for (int i = 0; i < q; i++) cout << n - ans[i] << endl;
}
