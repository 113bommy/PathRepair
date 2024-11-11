#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int v[1000010];
struct nod {
  int l, r, v;
};
vector<nod> s;
void add(int o, int l, int r, int x, int y) {
  if (l == r) {
    s[o].v = y;
    return;
  }
  if (x <= (l + r >> 1)) {
    if (s[o].l == -1) {
      s[o].l = s.size();
      s.push_back((nod){-1, -1, 0});
    }
    add(s[o].l, l, (l + r >> 1), x, y);
  } else {
    if (s[o].r == -1) {
      s[o].r = s.size();
      s.push_back((nod){-1, -1, 0});
    }
    add(s[o].r, (l + r >> 1) + 1, r, x, y);
  }
  s[o].v = 0;
  if (s[o].l != -1) {
    s[o].v += s[s[o].l].v;
  }
  if (s[o].r != -1) {
    s[o].v += s[s[o].r].v;
  }
}
int ask(int o, int l, int r, int il, int ir) {
  if (il <= l && ir >= r) {
    return s[o].v;
  }
  int re = 0;
  if (il <= (l + r >> 1) && s[o].l != -1) {
    re += ask(s[o].l, l, (l + r >> 1), il, ir);
  }
  if (ir > (l + r >> 1) && s[o].r != -1) {
    re += ask(s[o].r, (l + r >> 1) + 1, r, il, ir);
  }
  return re;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    long long cnt = 0;
    s.clear();
    s.push_back((nod){-1, -1, 0});
    for (int i = 1; i <= m; i++) {
      int v;
      cin >> v;
      cnt += ask(0, 1, (1 << 30), 1, v - 1);
      add(0, 1, (1 << 30), v, 1);
    }
    cout << cnt << endl;
  }
  return 0;
}
