#include <bits/stdc++.h>
using namespace std;
int N, Sweep[500005 * 2], Ref[500005 * 2], pt;
struct seg {
  int l, r, c;
} S[500005];
map<int, int> Lookup;
long long Ans, x, y;
class Segtree {
  long long ST[500005 * 10], Lazy[500005 * 10];
  int Opt[500005 * 10];
  void pushdown(int cur, int l, int r) {
    if (Lazy[cur]) {
      ST[cur] += Lazy[cur];
      if (r > l) {
        Lazy[2 * cur] += Lazy[cur];
        Lazy[2 * cur + 1] += Lazy[cur];
      }
      Lazy[cur] = 0;
    }
  }
  void pushup(int cur) {
    ST[cur] = max(ST[2 * cur], ST[2 * cur + 1]);
    Opt[cur] = ST[2 * cur] > ST[2 * cur + 1] ? Opt[2 * cur] : Opt[2 * cur + 1];
  }

 public:
  void init(int l, int r, int cur) {
    Opt[cur] = l;
    ST[cur] = Ref[l] - (1LL << 40);
    if (l != r) {
      int mid = (l + r) >> 1;
      init(l, mid, 2 * cur);
      init(mid + 1, r, 2 * cur + 1);
    }
  }
  void upd(int lo, int hi, long long v, int l, int r, int cur) {
    pushdown(cur, l, r);
    if (lo > hi || lo > r || hi < l) {
      return;
    }
    if (lo <= l && hi >= r) {
      Lazy[cur] += v;
      pushdown(cur, l, r);
    } else {
      int mid = (l + r) >> 1;
      upd(lo, hi, v, l, mid, 2 * cur);
      upd(lo, hi, v, mid + 1, r, 2 * cur + 1);
      pushup(cur);
    }
  }
  long long get1() {
    pushdown(1, 0, pt);
    return (ST[1]);
  }
  int get2() { return (Opt[1]); }
} ST;
void compress() {
  for (int i = 1; i <= N; i++) {
    Sweep[2 * i - 1] = S[i].l;
    Sweep[2 * i] = S[i].r;
  }
  Sweep[0] = -1000000005;
  Sweep[2 * N + 1] = 1000000005;
  sort(Sweep, Sweep + 2 * N + 2);
  for (int i = 0; i < 2 * N + 2; i++) {
    if (i == 0 || Sweep[i] != Sweep[i - 1]) {
      Lookup[Sweep[i]] = pt;
      Ref[pt] = Sweep[i];
      pt++;
    }
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d %d", &S[i].l, &S[i].r, &S[i].c);
    if (S[i].l > S[i].r) {
      swap(S[i].l, S[i].r);
    }
  }
  S[0].r = -1000000005;
  sort(S, S + N + 1, [](seg a, seg b) { return (a.r < b.r); });
  compress();
  ST.init(0, pt, 1);
  for (int i = 1; i <= N; i++) {
    ST.upd(Lookup[S[i - 1].r] + 1, Lookup[S[i].r], 1LL << 40, 0, pt, 1);
    ST.upd(0, Lookup[S[i].l], S[i].c, 0, pt, 1);
    if (i == N || S[i].r != S[i + 1].r) {
      Ans = max(Ans, ST.get1() - S[i].r);
      if (ST.get1() - S[i].r == Ans) {
        x = Ref[ST.get2()];
        y = S[i].r;
      }
    }
  }
  if (Ans == 0) {
    x = y = 1e9;
  }
  printf("%lld\n%lld %lld %lld %lld", Ans, x, x, y, y);
}
