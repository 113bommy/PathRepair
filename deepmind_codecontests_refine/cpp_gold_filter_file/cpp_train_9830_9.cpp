#include <bits/stdc++.h>
using namespace std;
const int N = 4e6;
struct seg {
  int ul, ur, c;
} segs[N];
string s;
seg merge(seg lc, seg rc) {
  int now = min(lc.ul, rc.ur);
  seg r;
  r.c = lc.c + rc.c + now * 2;
  r.ul = lc.ul - now + rc.ul;
  r.ur = lc.ur - now + rc.ur;
  return r;
}
void build(int id, int l, int r) {
  if (l == r) {
    segs[id].c = 0;
    if (s[l] == '(') {
      segs[id].ul = 1;
      segs[id].ur = 0;
    } else {
      segs[id].ul = 0;
      segs[id].ur = 1;
    }
    return;
  }
  int mid = (l + r) >> 1;
  int lc = id << 1;
  int rc = lc | 1;
  build(lc, l, mid);
  build(rc, mid + 1, r);
  segs[id] = merge(segs[lc], segs[rc]);
}
seg query(int id, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) return segs[id];
  int mid = (l + r) >> 1;
  if (qr <= mid) return query(id << 1, l, mid, ql, qr);
  if (ql > mid) return query(id << 1 | 1, mid + 1, r, ql, qr);
  return merge(query(id << 1, l, mid, ql, mid),
               query(id << 1 | 1, mid + 1, r, mid + 1, qr));
}
int main() {
  int i, j;
  cin >> s;
  int len = s.size();
  build(1, 0, len - 1);
  int m;
  cin >> m;
  for (i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", query(1, 0, len - 1, l - 1, r - 1).c);
  }
  return 0;
}
