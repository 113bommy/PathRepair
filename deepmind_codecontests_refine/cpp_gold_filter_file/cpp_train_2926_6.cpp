#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 326, maxLog = 17;
int N, rad[maxN];
struct Seg {
  int l, r, len;
  Seg() : l(-1), r(-1), len(0) {}
  Seg(int _l, int _r) : l(_l), r(_r) {
    if (l > r) {
      r += N;
    }
    len = r - l + 1;
    if (r >= N) r -= N;
  }
  string disp() {
    return to_string(l) + " - " + to_string(r) + ": " + to_string(len);
  }
};
Seg Merge(Seg a, Seg b) {
  if (a.l == -1) return b;
  if (b.l == -1) return a;
  Seg s;
  int L, R, le = max(a.len, b.len);
  if (a.l > a.r && b.l > b.r) {
    a.r += N;
    b.r += N;
    L = min(a.l, b.l);
    R = max(a.r, b.r);
  } else if (a.l > a.r) {
    a.r += N;
    if (b.r >= a.l) {
      L = min(a.l, b.l);
      R = a.r;
    } else if (b.l <= a.r - N) {
      L = a.l;
      R = max(a.r, b.r + N);
    }
  } else if (b.l > b.r) {
    swap(a, b);
    a.r += N;
    if (b.r >= a.l) {
      L = min(a.l, b.l);
      R = a.r;
    } else if (b.l <= a.r - N) {
      L = a.l;
      R = max(a.r, b.r + N);
    }
  } else {
    L = min(a.l, b.l);
    R = max(a.r, b.r);
  }
  le = max(le, R - L + 1);
  if (le >= N) {
    s = Seg(1, 0);
    s.len = N;
  } else {
    if (R >= N) R -= N;
    s = Seg(L, R);
  }
  return s;
}
struct ST {
  Seg seg[4 * maxN];
  inline void pull(int id) {
    seg[id] = Merge(seg[2 * id + 1], seg[2 * id + 2]);
  }
  ST() { fill(seg, seg + 4 * maxN, Seg(-1, -1)); }
  void build(int id = 0, int l = 0, int r = N) {
    if (l + 1 == r) {
      seg[id] = Seg(l, l);
      return;
    }
    int m = (l + r) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    pull(id);
  }
  void modify(int id, int l, int r, int p, Seg s) {
    if (l + 1 == r) {
      seg[id] = s;
      return;
    }
    int m = (l + r) / 2;
    if (p < m)
      modify(2 * id + 1, l, m, p, s);
    else
      modify(2 * id + 2, m, r, p, s);
    pull(id);
  }
  Seg query(int id, int l, int r, int ql, int qr) {
    if (l >= qr || ql >= r) return Seg(-1, -1);
    if (ql <= l && r <= qr) return seg[id];
    int m = (l + r) / 2;
    return Merge(query(2 * id + 1, l, m, ql, qr),
                 query(2 * id + 2, m, r, ql, qr));
  }
} segs[20];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < N; i++) cin >> rad[i];
  segs[0].build();
  for (int i = 0; i < N; i++) {
    Seg tgt = Seg((i - rad[i] + N) % N, (i + rad[i]) % N);
    if (2 * rad[i] + 1 >= N) {
      tgt = Seg(1, 0);
    }
    segs[0].modify(0, 0, N, i, tgt);
    tgt = segs[0].query(0, 0, N, i, i + 1);
  }
  for (int i = 1; i < maxLog; i++) {
    segs[i].build();
    for (int j = 0; j < N; j++) {
      Seg range = segs[i - 1].query(0, 0, N, j, j + 1), tgt;
      if (range.l <= range.r) {
        tgt = segs[i - 1].query(0, 0, N, range.l, range.r + 1);
      } else {
        Seg ls = segs[i - 1].query(0, 0, N, range.l, N),
            rs = segs[i - 1].query(0, 0, N, 0, range.r + 1);
        tgt = Merge(segs[i - 1].query(0, 0, N, range.l, N),
                    segs[i - 1].query(0, 0, N, 0, range.r + 1));
      }
      segs[i].modify(0, 0, N, j, tgt);
    }
  }
  for (int i = 0; i < N; i++) {
    int ans = 0;
    Seg curSeg = Seg(i, i);
    for (int j = maxLog - 1; j >= 0; j--) {
      Seg queSeg = curSeg, nxtSeg;
      if (queSeg.l > queSeg.r) {
        nxtSeg = Merge(segs[j].query(0, 0, N, queSeg.l, N),
                       segs[j].query(0, 0, N, 0, queSeg.r + 1));
      } else {
        nxtSeg = segs[j].query(0, 0, N, queSeg.l, queSeg.r + 1);
      }
      if (nxtSeg.len < N) {
        curSeg = nxtSeg;
        ans |= (1 << j);
      }
    }
    cout << ans + 1 << " ";
  }
}
