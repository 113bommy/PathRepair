#include <bits/stdc++.h>
using namespace std;
int n, Q, tr;
set<pair<int, int> > Stx, Sty;
pair<int, int> rec[300005];
struct SEG {
  int mx[300005], M;
  void init(int _sz) {
    for (M = 1; M <= _sz; M <<= 1)
      ;
    memset(mx, 0, sizeof(mx));
  }
  void modify(int x, int val) {
    mx[x += M] = val;
    for (x >>= 1; x; x >>= 1) mx[x] = max(mx[x << 1], mx[(x << 1) | 1]);
  }
  int query(int suf) {
    int res = 0;
    for (suf += M - 1; suf; suf >>= 1)
      if (!(suf & 1)) res = max(res, mx[suf ^ 1]);
    return res;
  }
} Tx, Ty;
void modify(int pos, int hei, int val) {
  Tx.modify(pos, val);
  Ty.modify(hei, val);
}
int getx(int l) { return Tx.query(l); }
int gety(int l) { return Ty.query(l); }
int main() {
  scanf("%d%d", &n, &Q);
  Tx.init(n);
  Ty.init(Q + 200);
  for (int times = 1; times <= Q; times++) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int p, h;
      scanf("%d%d", &p, &h);
      h = h - times + Q;
      while (Sty.size() && Sty.begin()->first < h) {
        set<pair<int, int> >::iterator x = Sty.begin();
        rec[++tr] = *x;
        modify(x->second, x->first, 0);
        Sty.erase(x);
      }
      rec[++tr] = make_pair(h, p);
      for (int i = tr; i; i--) {
        pair<int, int> tmp = rec[i];
        modify(tmp.second, tmp.first, getx(tmp.second + 1) + 1);
      }
      for (; tr; tr--) Sty.insert(rec[tr]);
      Stx.insert(make_pair(p, h));
    } else {
      int dir;
      scanf("%d", &dir);
      int tmp = dir;
      while (Stx.size() && tmp) {
        set<pair<int, int> >::iterator x = Stx.begin();
        rec[++tr] = *x;
        modify(x->first, x->second, 0);
        Stx.erase(x);
        --tmp;
      }
      Sty.erase(make_pair(rec[tr].second, rec[tr].first));
      --tr;
      for (int i = tr; i; i--) {
        pair<int, int> tmp = rec[i];
        modify(tmp.first, tmp.second, gety(tmp.second + 1) + 1);
      }
      for (; tr; tr--) Stx.insert(rec[tr]);
    }
    printf("%d\n", getx(1));
  }
  return 0;
}
