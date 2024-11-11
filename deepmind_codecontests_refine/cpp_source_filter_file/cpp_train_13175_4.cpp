#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 9;
int iv10;
int ip10[500006];
int n, q;
int Pow(int x, int a) {
  int ret = 1;
  while (a) {
    if (a & 1) ret = ret * 1ll * x % P;
    x = x * 1ll * x % P, a >>= 1;
  }
  return ret;
}
int rd() {
  char ch = getchar();
  int ret = 0;
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
  return ret;
}
char S[500006];
int bel[500006], lk[500006];
struct sgt {
  struct node {
    int l, r;
    node operator+(const node a) {
      return (node){a.l - min(a.l, r) + l, r - min(a.l, r) + a.r};
    }
  } T[500006 << 2];
  void build(int rt, int l, int r) {
    if (l == r) {
      if (S[l] == '(')
        T[rt].r = 1;
      else if (S[l] == ')')
        T[rt].l = 1;
      return;
    }
    int m = l + r >> 1;
    build(rt << 1, l, m), build(rt << 1 | 1, m + 1, r);
    T[rt] = T[rt << 1] + T[rt << 1 | 1];
  }
  node que(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r) return T[rt];
    int m = l + r >> 1;
    node re = (node){0, 0};
    if (L <= m) re = re + que(rt << 1, l, m, L, R);
    if (R > m) re = re + que(rt << 1 | 1, m + 1, r, L, R);
    return re;
  }
  bool que(int l, int r) {
    node re = que(1, 1, n, l, r);
    return !re.l && !re.r;
  }
} T;
int solve(int l, int r);
int cnn, bn[500006];
struct segnum {
  int l, r, v, dx;
  vector<int> s;
  int build() {
    if (S[l] == '(') {
      bn[l] = bn[r] = cnn;
      return v = solve(l + 1, r - 1);
    }
    int pw = 1;
    for (int j = (1), jend = (r - l + 1); j <= jend; ++j) pw = pw * 10ll % P;
    for (int i = (l), iend = (r); i <= iend; ++i) bn[i] = dx;
    for (int i = (0), iend = (r - l); i <= iend; ++i) {
      pw = pw * 1ll * iv10 % P;
      s.push_back((S[i + l] - '0') * 1ll * pw % P);
      if (s.size() > 1) s[s.size() - 1] = (s.back() + s[s.size() - 2]) % P;
    }
    return v = s.back();
  }
  int gv(int L, int R) {
    if (L == l && R == r) return v;
    int x = (s[R - l] + P - (L == l ? 0 : s[L - 1 - l])) % P;
    return x * 1ll * ip10[r - R] % P;
  }
} N[500006];
int bm[500006], cnm;
struct segmul {
  int l, r, v, dx;
  vector<int> nums, pm, c0;
  int build() {
    int pl = l;
    for (int i = (l), iend = (r); i <= iend; ++i) {
      if (S[i] == '*') {
        ++cnn;
        N[cnn].l = pl, N[cnn].r = i - 1, N[cnn].dx = cnn;
        nums.push_back(cnn);
        int v = N[cnn].build();
        pm.push_back(v == 0 ? 1 : v), c0.push_back(v == 0);
        pl = i + 1;
      }
      bm[i] = dx;
      if (S[i] == '(') i = lk[i] - 1;
    }
    ++cnn, N[cnn].l = pl, N[cnn].r = r, N[cnn].dx = cnn;
    nums.push_back(cnn);
    int v = N[cnn].build();
    pm.push_back(v == 0 ? 1 : v), c0.push_back(v == 0);
    for (int i = (1), iend = (pm.size() - 1); i <= iend; ++i) {
      pm[i] = pm[i - 1] * 1ll * pm[i] % P;
      c0[i] += c0[i - 1];
    }
    return c0.back() ? 0 : pm.back();
  }
  int gv(int L, int R) {
    int tl = bn[L], tr = bn[R];
    if (tl == tr) return N[tl].gv(L, R);
    int re = N[tl].gv(L, N[tl].r) * 1ll * N[tr].gv(N[tr].l, R) % P;
    tl = upper_bound((nums).begin(), (nums).end(), tl) - nums.begin(),
    tr = lower_bound((nums).begin(), (nums).end(), tr) - nums.begin() - 1;
    if (tr >= tl && c0[tr]) return 0;
    return pm[tr] * 1ll * (tl == 0 ? 1 : Pow(pm[tl - 1], P - 2)) % P * re % P;
  }
} M[500006];
int cna;
struct segadd {
  int l, r, v;
  vector<int> ms, ps;
  int build() {
    int pl = l;
    for (int i = (l), iend = (r); i <= iend; ++i) {
      if (S[i] == '+') {
        ++cnm;
        M[cnm].l = pl, M[cnm].r = i - 1, M[cnm].dx = cnm;
        ms.push_back(cnm), ps.push_back(M[cnm].build());
        pl = i + 1;
      }
      if (S[i] == '(') i = lk[i] - 1;
    }
    ++cnm, M[cnm].l = pl, M[cnm].r = r, M[cnm].dx = cnm;
    ms.push_back(cnm), ps.push_back(M[cnm].build());
    for (int i = (1), iend = (ps.size() - 1); i <= iend; ++i)
      ps[i] = (ps[i - 1] + ps[i]) % P;
    return ps.back();
  }
  int gv(int L, int R) {
    int tl = bm[L], tr = bm[R];
    if (tl == tr) return M[tl].gv(L, R);
    int res = M[tl].gv(L, M[tl].r) + M[tr].gv(M[tr].l, R);
    tl = upper_bound((ms).begin(), (ms).end(), tl) - ms.begin(),
    tr = lower_bound((ms).begin(), (ms).end(), tr) - ms.begin() - 1;
    return (1ll * res + ps[tr] + P - ps[tl - 1]) % P;
  }
} W[500006];
int solve(int l, int r) {
  W[l - 1].l = l, W[l - 1].r = r;
  return W[l - 1].build();
}
void solve() {
  scanf("%s", S + 1);
  n = strlen(S + 1);
  iv10 = Pow(10, P - 2);
  ip10[0] = 1;
  for (int i = (1), iend = (n); i <= iend; ++i)
    ip10[i] = ip10[i - 1] * 1ll * iv10 % P;
  cin >> q;
  vector<int> pt;
  pt.push_back(0);
  for (int i = (1), iend = (n); i <= iend; ++i) {
    if (S[i] == '(')
      bel[i] = pt.back(), pt.push_back(i);
    else {
      if (S[i] == ')') lk[pt.back()] = i, pt.pop_back();
      bel[i] = pt.back();
    }
  }
  T.build(1, 1, n);
  solve(1, n);
  for (int i = (1), iend = (q); i <= iend; ++i) {
    int l, r;
    l = rd(), r = rd();
    if (S[l] == '+' || S[l] == '*' || S[r] == '+' || S[r] == '*') {
      puts("-1");
      continue;
    }
    if (!T.que(l, r)) {
      puts("-1");
      continue;
    }
    int x = bel[l];
    printf("%d\n", W[x].gv(l, r));
  }
}
signed main() { solve(); }
