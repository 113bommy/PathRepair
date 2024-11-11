#include <bits/stdc++.h>
using namespace std;
struct seg {
  int l, r, v, lz = 0;
  seg *ch[2]{};
  seg(int _l, int _r) : l(_l), r(_r), v(_r - 2) {
    if (l < r - 1)
      ch[0] = new seg(l, l + r >> 1), ch[1] = new seg(l + r >> 1, r);
  }
  void push() {
    ch[0]->v += lz, ch[0]->lz += lz, ch[1]->v += lz, ch[1]->lz += lz;
  }
  void pull() { v = max(ch[0]->v, ch[1]->v); }
  void modify(int _r, int d) {
    if (r <= _r) {
      v += d, lz += d;
      return;
    }
    push();
    ch[0]->modify(_r, d);
    if (l + r >> 1 < _r) ch[1]->modify(_r, d);
    pull();
  }
  int query(int _r) {
    if (r <= _r) return v;
    push();
    int ans = ch[0]->query(_r);
    if (l + r >> 1 < _r) ans = max(ans, ch[1]->query(_r));
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  seg rt(0, 2 * n);
  set<pair<int, int>> s;
  multiset<int> ms;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int z = y + abs(x - k) + 1;
    if (s.count({x, y}))
      s.erase({x, y}), rt.modify(z, -1), ms.erase(ms.equal_range(z).first);
    else
      s.insert({x, y}), rt.modify(z, 1), ms.insert(z);
    if (ms.empty())
      cout << "0\n";
    else
      cout << max(0, rt.query(*(--ms.end())) - n) << '\n';
  }
}
