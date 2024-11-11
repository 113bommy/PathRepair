#include <bits/stdc++.h>
using namespace std;
const int _ = 4e5 + 7, P = 1e9 + 7;
int poww(long long a, int b) {
  int tms = 1;
  while (b) {
    if (b & 1) tms = tms * a % P;
    a = a * a % P;
    b >>= 1;
  }
  return tms;
}
int upd(int x) { return x + (x >> 31 & P); }
struct segt {
  int sum[_ << 2];
  bool tag[_ << 2];
  segt() {
    memset(sum, 0, sizeof(sum));
    memset(tag, 0, sizeof(tag));
  }
  void mark(int x) {
    tag[x] = 1;
    sum[x] = 0;
  }
  void down(int x) {
    if (tag[x]) {
      mark((x << 1));
      mark((x << 1 | 1));
      tag[x] = 0;
    }
  }
  void up(int x) { sum[x] = upd(sum[(x << 1)] + sum[(x << 1 | 1)] - P); }
  void mdf(int x, int l, int r, int tar, int v) {
    sum[x] = upd(sum[x] + v - P);
    if (l == r) return;
    down(x);
    ((l + r) >> 1) >= tar ? mdf((x << 1), l, ((l + r) >> 1), tar, v)
                          : mdf((x << 1 | 1), ((l + r) >> 1) + 1, r, tar, v);
  }
  void clr(int x, int l, int r, int L, int R) {
    if (l >= L && r <= R) return mark(x);
    down(x);
    if (((l + r) >> 1) >= L) clr((x << 1), l, ((l + r) >> 1), L, R);
    if (((l + r) >> 1) < R) clr((x << 1 | 1), ((l + r) >> 1) + 1, r, L, R);
    up(x);
  }
  int qry(int x, int l, int r, int L, int R) {
    if (tag[x] || (l >= L && r <= R)) return sum[x];
    int sum = 0;
    if (((l + r) >> 1) >= L) sum = qry((x << 1), l, ((l + r) >> 1), L, R);
    if (((l + r) >> 1) < R)
      sum = upd(sum - P + qry((x << 1 | 1), ((l + r) >> 1) + 1, r, L, R));
    return sum;
  }
} Tr[2];
int lft = 1, K, N, M;
struct seg {
  int l, r, type;
};
vector<seg> now;
vector<int> lsh;
int main() {
  ios::sync_with_stdio(0);
  cin >> K >> N >> M;
  for (int i = 1; i <= N; ++i) {
    int l, r;
    cin >> l >> r;
    now.push_back((seg){l, r, 0});
    lsh.push_back(l);
    lsh.push_back(r + 1);
  }
  for (int i = 1; i <= M; ++i) {
    int l, r;
    cin >> l >> r;
    now.push_back((seg){l, r, 1});
    lsh.push_back(l);
    lsh.push_back(r + 1);
  }
  sort(now.begin(), now.end(), [&](seg p, seg q) { return p.l < q.l; });
  int pre = 1;
  lsh.push_back(0);
  lsh.push_back(K + 1);
  sort(lsh.begin(), lsh.end());
  lsh.resize(unique(lsh.begin(), lsh.end()) - lsh.begin());
  for (int i = 1, pos = 0; i < lsh.size(); ++i) {
    lft = (1ll * lft * poww(2, lsh[i] - pre) +
           Tr[0].qry(1, 0, lsh.size(), i - 1, i - 1) +
           Tr[1].qry(1, 0, lsh.size(), i - 1, i - 1)) %
          P;
    Tr[0].clr(1, 0, lsh.size(), i - 1, i - 1);
    Tr[1].clr(1, 0, lsh.size(), i - 1, i - 1);
    while (pos < now.size() && now[pos].l == lsh[i]) {
      int t = upper_bound(lsh.begin(), lsh.end(), now[pos].r) - lsh.begin();
      Tr[now[pos].type].clr(1, 0, lsh.size(), t, lsh.size());
      Tr[now[pos].type].mdf(
          1, 0, lsh.size(), t - 1,
          upd(P - lft - Tr[now[pos].type].qry(1, 0, lsh.size(), 0, t)));
      ++pos;
    }
    pre = lsh[i];
  }
  cout << lft;
  return 0;
}
