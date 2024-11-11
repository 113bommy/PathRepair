#include <bits/stdc++.h>
using namespace std;
long long n, p = 1, a[200069];
long long md(long long l, long long r) { return (l + r) / 2; }
struct segtree {
  long long l, r, lz;
  pair<long long, long long> ans;
  segtree *p1, *p2;
  pair<long long, long long> mrg(pair<long long, long long> x,
                                 pair<long long, long long> y) {
    return {min(x.first, y.first), max(x.second, y.second)};
  }
  void bd(long long lh, long long rh) {
    l = lh;
    r = rh;
    lz = 0;
    if (l == r) {
      ans = {0, 0};
    } else {
      p1 = new segtree;
      p2 = new segtree;
      p1->bd(l, md(l, r));
      p2->bd(md(l, r) + 1, r);
      ans = mrg(p1->ans, p2->ans);
    }
  }
  void blc() {
    p1->ans.first += lz;
    p2->ans.first += lz;
    p1->ans.second += lz;
    p2->ans.second += lz;
    p1->lz += lz;
    p2->lz += lz;
    lz = 0;
  }
  void ud(long long lh, long long rh, long long w) {
    if (l > rh || r < lh)
      ;
    else if (l >= lh && r <= rh) {
      ans.first += w;
      ans.second += w;
      lz += w;
    } else {
      blc();
      p1->ud(lh, rh, w);
      p2->ud(lh, rh, w);
      ans = mrg(p1->ans, p2->ans);
    }
  }
  pair<long long, long long> qr(long long lh, long long rh) {
    if (l > rh || r < lh) {
      return {1e18, -1e18};
    } else if (l >= lh && r <= rh) {
      return ans;
    } else {
      blc();
      return mrg(p1->qr(lh, rh), p2->qr(lh, rh));
    }
  }
} sg;
int main() {
  long long i, j, k;
  string s;
  pair<long long, long long> tmp;
  scanf("%lld", &n);
  sg.bd(1, n);
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == 'L') {
      p = max(p - 1, 1ll);
    } else if (s[i] == 'R') {
      p++;
    } else {
      if (s[i] == '(') {
        k = 1;
      } else if (s[i] == ')') {
        k = -1;
      } else {
        k = 0;
      }
      sg.ud(p, n, k - a[p]);
      a[p] = k;
    }
    tmp = sg.qr(n, n);
    if (tmp.first != 0) {
      printf("-1");
    } else {
      tmp = sg.qr(1, n);
      if (tmp.first < 0) {
        printf("-1");
      } else {
        printf("%lld", tmp.second);
      }
    }
    printf("%c", " \n"[i == n - 1]);
  }
}
