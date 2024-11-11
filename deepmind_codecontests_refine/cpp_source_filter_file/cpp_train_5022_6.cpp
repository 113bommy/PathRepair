#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6, md = 1004535809, siz = 320;
mt19937 mt(time(0) + (size_t) new int);
int n, m, base, _[N], L[N], R[N], blocks, i_[N];
inline int pow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = (long long)a * a % md)
    if (b & 1) res = (long long)res * a % md;
  return res;
}
struct qaq {
  int id, l, r;
};
struct Block {
  int a[350], len;
  int hx[2][350], b[2][350], c[2];
  bool isgood;
  inline int get_hash(int o, int l, int r) {
    return (hx[o][r] - (long long)hx[o][l] * _[r - l] % md + md) % md;
  }
  void build() {
    static int sta[350];
    int top = 0;
    for (int i = 1; i <= len; ++i) {
      if (a[i] > 0)
        sta[++top] = a[i];
      else {
        if (top && a[i] == -sta[top])
          --top;
        else
          sta[++top] = a[i];
      }
    }
    isgood = 0;
    c[0] = c[1] = 0;
    for (int i = 1; i <= top; ++i)
      if (sta[i] < 0) {
        ++c[0];
        b[0][c[0]] = sta[i];
      } else
        break;
    for (int i = top; i; --i)
      if (sta[i] > 0) {
        ++c[1];
        b[1][c[1]] = -sta[i];
      } else
        break;
    if (c[0] + c[1] == top) {
      isgood = 1;
      reverse(b[0] + 1, b[0] + c[0] + 1);
      reverse(b[1] + 1, b[1] + c[1] + 1);
      for (int i = 1; i <= c[0]; ++i)
        hx[0][i] = ((long long)hx[0][i - 1] * base + b[0][i]) % md;
      for (int i = 1; i <= c[1]; ++i)
        hx[1][i] = ((long long)hx[1][i - 1] * base + b[1][i]) % md;
    }
  }
  void init(int ln) {
    len = ln;
    for (int i = 1; i <= len; ++i) cin >> a[i];
    build();
  }
} G[350];
deque<qaq> dL, dR;
int LEN;
bool add_block(int id) {
  LEN += G[id].c[0] + G[id].c[1];
  qaq k = (qaq){id, 1, G[id].c[0]};
  while (dR.size() && k.l <= k.r) {
    qaq kk = dR.back();
    dR.pop_back();
    int ln = min(k.r - k.l + 1, kk.r - kk.l + 1);
    if (G[k.id].get_hash(0, k.r - ln + 1, k.r) !=
        G[kk.id].get_hash(1, kk.r - ln + 1, kk.r))
      return 0;
    kk.r -= ln;
    k.r -= ln;
    if (kk.r >= kk.l) dR.push_back(kk);
    LEN -= 2 * ln;
  }
  if (k.l <= k.r) dL.push_front(k);
  dR.push_back((qaq){id, 1, G[id].c[1]});
  return 1;
}
int STK[N], tp;
bool chk() {
  static int sta[N];
  int top = 0;
  for (int i = 1; i <= tp; ++i) {
    if (STK[i] > 0)
      sta[++top] = STK[i];
    else if (top && STK[i] == -sta[top])
      --top;
    else
      return 0;
  }
  return top == 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  base = mt() % 1000000 + 233333;
  cin >> n >> m;
  for (int i = *_ = 1; i <= n; ++i) _[i] = (long long)_[i - 1] * base % md;
  for (int i = 0; i <= n; ++i) i_[i] = pow(_[i], md - 2);
  blocks = ((n - 1) / siz + 1);
  for (int i = 1; i <= blocks; ++i) R[i] = i * siz, L[i] = R[i - 1] + 1;
  R[blocks] = n;
  for (int i = 1; i <= blocks; ++i) G[i].init(R[i] - L[i] + 1);
  for (cin >> m; m--;) {
    int op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
      int bl = ((l - 1) / siz + 1);
      G[bl].a[l - L[bl] + 1] = r;
      G[bl].build();
    } else {
      int bL = ((l - 1) / siz + 1), bR = ((r - 1) / siz + 1);
      tp = 0;
      if (bL == bR) {
        for (int i = l; i <= r; ++i) STK[++tp] = G[bL].a[i - L[bL] + 1];
      } else {
        bool ok = 1;
        for (int i = bL + 1; i < bR; ++i)
          if (!G[i].isgood) ok = 0;
        dL.clear(), dR.clear();
        LEN = 0;
        for (int i = bL + 1; i < bR && ok; ++i) ok &= add_block(i);
        if (!ok || LEN > 2 * siz) {
          cout << "No\n";
          continue;
        }
        for (int i = l; i <= R[bL]; ++i) STK[++tp] = G[bL].a[i - L[bL] + 1];
        while (dL.size()) {
          qaq k = dL.back();
          dL.pop_back();
          for (int i = k.r; i >= k.l; --i) STK[++tp] = G[k.id].b[0][i];
        }
        while (dR.size()) {
          qaq k = dR.front();
          dR.pop_front();
          for (int i = k.l; i <= k.r; ++i) STK[++tp] = -G[k.id].b[1][i];
        }
        for (int i = L[bR]; i <= r; ++i) STK[++tp] = G[bR].a[i - L[bR] + 1];
      }
      if (chk())
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}
