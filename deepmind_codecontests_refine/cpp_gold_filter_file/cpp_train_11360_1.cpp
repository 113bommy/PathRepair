#include <bits/stdc++.h>
using namespace std;
const int maxn = 200001;
long long a[maxn];
int n, m;
long long t;
void enter() {
  cin >> n >> m >> t;
  for (int i = (1), _b = (n + 1); i < _b; ++i) cin >> a[i];
}
struct seg {
  long long sum;
  int sl;
  seg() {}
  seg(long long aa, int bb) {
    sum = aa;
    sl = bb;
  }
};
seg IT[4 * maxn];
void update(int l, int r, int st, int q, long long SUM, int SL) {
  if (l == r)
    IT[st] = seg(SUM, SL);
  else {
    int mid = (l + r) >> 1;
    if (mid >= q)
      update(l, mid, st * 2, q, SUM, SL);
    else
      update(mid + 1, r, st * 2 + 1, q, SUM, SL);
    IT[st].sum = IT[st * 2].sum + IT[st * 2 + 1].sum;
    IT[st].sl = IT[st * 2].sl + IT[st * 2 + 1].sl;
  }
}
seg _get(int l, int r, int u, int v, int st) {
  if (u <= l && r <= v)
    return IT[st];
  else if (l > v || r < u)
    return seg(0, 0);
  else {
    int mid = (l + r) >> 1;
    seg ans1 = _get(l, mid, u, v, st * 2);
    seg ans2 = _get(mid + 1, r, u, v, st * 2 + 1);
    return seg(ans1.sum + ans2.sum, ans1.sl + ans2.sl);
  }
}
int jump1(int l, int r, int st, long long tong, int cnt) {
  if (l == r) {
    if (IT[st].sum * 2 + tong <= t)
      return (cnt + IT[st].sl);
    else
      return cnt;
  } else {
    int mid = (l + r) >> 1;
    if (tong + IT[st * 2].sum * 2 <= t)
      return jump1(mid + 1, r, st * 2 + 1, tong + IT[st * 2].sum * 2,
                   cnt + IT[st * 2].sl);
    else
      return jump1(l, mid, st * 2, tong, cnt);
  }
}
int fix(int l, int r, int st, long long tong, int cnt, int cntroot) {
  if (l == r) {
    if (cnt + IT[st].sl <= cntroot)
      return l;
    else
      return (l - 1);
  } else {
    int mid = (l + r) >> 1;
    if (cnt + IT[st * 2].sl <= cntroot)
      return fix(mid + 1, r, st * 2 + 1, tong + IT[st * 2].sum * 2,
                 cnt + IT[st * 2].sl, cntroot);
    else
      return fix(l, mid, st * 2, tong, cnt, cntroot);
  }
}
struct tv {
  int bn, id;
  long long tg;
  tv() {}
  tv(long long aa, int bb, int cc) {
    tg = aa;
    bn = bb;
    id = cc;
  }
};
tv jump2(int l, int r, int st, long long tong, int cnt, int pos, int cntroot) {
  if (l == r) {
    if ((tong + IT[st].sum <= t) && (cnt + IT[st].sl <= cntroot))
      return tv(tong + IT[st].sum, cnt + IT[st].sl, l);
    else
      return tv(tong, cnt, l - 1);
  } else if (l >= pos) {
    int mid = (l + r) >> 1;
    if ((tong + IT[st * 2].sum <= t) && (IT[st * 2].sl + cnt <= cntroot))
      return jump2(mid + 1, r, st * 2 + 1, tong + IT[st * 2].sum,
                   cnt + IT[st * 2].sl, pos, cntroot);
    else
      return jump2(l, mid, st * 2, tong, cnt, pos, cntroot);
  } else {
    int mid = (l + r) >> 1;
    if (mid < pos)
      return jump2(mid + 1, r, st * 2 + 1, tong + IT[st * 2].sum * 2,
                   cnt + IT[st * 2].sl, pos, cntroot);
    else {
      tv ans = jump2(l, mid, st * 2, tong, cnt, pos, cntroot);
      if (ans.id == mid)
        return jump2(mid + 1, r, st * 2 + 1, ans.tg, ans.bn, pos, cntroot);
      else
        return ans;
    }
  }
}
void solve() {
  vector<pair<long long, int> > p;
  vector<int> q;
  for (int i = (1), _b = (n + 1); i < _b; ++i) {
    p.push_back(pair<long long, int>(a[i], i));
    q.push_back(a[i]);
  }
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  int I = 0;
  int kq = 0;
  long long d = t;
  for (auto i : q) {
    while (I < int(p.size()) && (i >= p[I].first)) {
      update(1, n, 1, p[I].second, p[I].first, 1);
      ++I;
    }
    int dem = jump1(1, n, 1, 0, 0);
    int w = fix(1, n, 1, 0, 0, dem - (dem % m));
    tv ans = jump2(1, n, 1, 0, 0, w + 1, dem - (dem % m) + m);
    if (kq < ans.bn) {
      kq = ans.bn;
      d = i;
    }
  }
  cout << kq << " " << d << "\n";
}
void _reset() {
  for (int i = (1), _b = (4 * n + 1); i < _b; ++i) IT[i].sl = IT[i].sum = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  for (int i = (0), _b = (t); i < _b; ++i) {
    enter();
    solve();
    _reset();
  }
}
