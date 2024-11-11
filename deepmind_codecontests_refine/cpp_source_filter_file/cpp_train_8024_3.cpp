#include <bits/stdc++.h>
using namespace std;
int n, m, x;
struct Vx {
  vector<pair<int, int> > lo, ro;
  long long cnt;
};
vector<Vx> seg_tree;
long long getMixCnt(const vector<pair<int, int> > &lo,
                    const vector<pair<int, int> > &ro, int l, int r) {
  long long cnt = 0;
  int pli = l - 1;
  for (int li = lo.size() - 1; li >= 0; li--) {
    int ri = 0;
    while (ri < ro.size()) {
      if ((ro[ri].first | lo[li].first) >= x) {
        cnt += 1LL * (lo[li].second - pli) * (r + 1 - ro[ri].second);
        pli = lo[li].second;
        break;
      }
      ri++;
    }
  }
  return cnt;
}
vector<pair<int, int> > mer(const vector<pair<int, int> > &mo,
                            const vector<pair<int, int> > &so) {
  vector<pair<int, int> > ret;
  if (mo.size() == 0) {
    ret = so;
    return ret;
  }
  ret = mo;
  int prev = ret.back().first;
  for (auto si : so) {
    prev |= si.first;
    if (prev != ret.back().first) ret.push_back(make_pair(prev, si.second));
  }
  return ret;
}
void update(int ti, int l, int r, int i, int ai) {
  vector<pair<int, int> > lo;
  vector<pair<int, int> > ro;
  long long cnt = 0;
  if (l == r) {
    lo.push_back(make_pair(ai, i));
    ro.push_back(make_pair(ai, i));
    if (ai >= x) cnt = 1;
  } else {
    int m = (l + r) / 2;
    int tli = ti * 2 + 1;
    int tri = ti * 2 + 2;
    if (i <= m) {
      update(tli, l, m, i, ai);
    } else {
      update(tri, m + 1, r, i, ai);
    }
    lo = mer(seg_tree[tri].lo, seg_tree[tli].lo);
    ro = mer(seg_tree[tli].ro, seg_tree[tri].ro);
    cnt = seg_tree[tli].cnt + seg_tree[tri].cnt +
          getMixCnt(seg_tree[tli].lo, seg_tree[tri].ro, l, r);
  }
  seg_tree[ti].lo = lo;
  seg_tree[ti].ro = ro;
  seg_tree[ti].cnt = cnt;
}
void read_data() {
  cin >> n >> m >> x;
  int ai;
  seg_tree.resize(400020);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ai);
    update(0, 0, n - 1, i, ai);
  }
}
Vx query(int ti, int l, int r, int pl, int pr) {
  if (l >= pl && r <= pr) {
    return seg_tree[ti];
  }
  int m = (l + r) / 2;
  if (pr <= m) {
    return query(ti * 2 + 1, l, m, pl, pr);
  } else if (pl > m) {
    return query(ti * 2 + 2, m + 1, r, pl, pr);
  } else {
    Vx vl = query(ti * 2 + 1, l, m, pl, pr);
    Vx vr = query(ti * 2 + 2, m + 1, r, pl, pr);
    Vx v;
    v.lo = mer(vr.lo, vl.lo);
    v.ro = mer(vl.ro, vr.ro);
    v.cnt = vl.cnt + vr.cnt + getMixCnt(vl.lo, vr.ro, max(pl, l), min(pr, r));
    return v;
  }
}
void deal() {
  int p, i, y, l, r;
  while (m-- > 0) {
    scanf("%d ", &p);
    if (1 == p) {
      scanf("%d %d", &i, &y);
      i--;
      update(0, 0, n - 1, i, y);
    } else {
      scanf("%d %d", &l, &r);
      l--;
      r--;
      Vx v = query(0, 0, n - 1, l, r);
      printf("%Illd\n", v.cnt);
    }
  }
}
int main() {
  read_data();
  deal();
  return 0;
}
