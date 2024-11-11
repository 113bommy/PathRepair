#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') ch = getchar(), f = -1;
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return ~f ? s : -s;
}
const int mod = 1e9 + 7;
inline int power(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (long long)ans * a % mod;
    b >>= 1;
    a = (long long)a * a % mod;
  }
  return ans;
}
const int seed = 181;
const int seedinv = power(seed, mod - 2);
const int maxn = 1e5 + 20;
const int M = 320;
int a[maxn];
int id[maxn], p2[maxn];
struct BLK {
  int pa[M + 20], phs[M + 20], lp;
  int sa[M + 20], shs[M + 20], ls;
  int L, R, FAKE;
  inline void BUILD() {
    ls = lp = 0;
    FAKE = 0;
    for (int i = (L), _end_ = (R); i <= _end_; i++) {
      if (a[i] > 0) {
        sa[++ls] = a[i];
      } else {
        if (ls) {
          if (sa[ls] != -a[i])
            return FAKE = 1, void();
          else
            ls--;
        } else
          pa[++lp] = -a[i];
      }
    }
    reverse(pa + 1, pa + lp + 1);
    for (int i = (1), _end_ = (lp); i <= _end_; i++)
      phs[i] = ((long long)phs[i - 1] * seed + pa[i]) % mod;
    for (int i = (1), _end_ = (ls); i <= _end_; i++)
      shs[i] = ((long long)shs[i - 1] * seed + sa[i]) % mod;
  }
  inline int SHash(int l, int r) {
    return (shs[r] - (long long)shs[l - 1] * p2[r - l + 1] % mod + mod) % mod;
  }
  inline int PHash(int l, int r) {
    return (phs[r] - (long long)phs[l - 1] * p2[r - l + 1] % mod + mod) % mod;
  }
};
BLK B[M + 20];
int n, k;
inline void init() {
  n = read();
  k = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++) a[i] = read();
  for (int ID = (1), _end_ = ((n - 1) / M + 1); ID <= _end_; ID++)
    B[ID].L = (ID - 1) * M + 1, B[ID].R = min(ID * M, n), B[ID].BUILD();
  for (int i = (1), _end_ = (n); i <= _end_; i++) id[i] = (i - 1) / M + 1;
  p2[0] = 1;
  for (int i = (1), _end_ = (n); i <= _end_; i++)
    p2[i] = (long long)p2[i - 1] * seed % mod;
}
struct node {
  int blk, r;
  node(int _blk = 0, int _r = 0) {
    blk = _blk;
    r = _r;
  }
};
bool query(int ql, int qr) {
  vector<node> st;
  if (id[ql] == id[qr]) {
    static int st[maxn], top;
    top = 0;
    for (int i = (ql), _end_ = (qr); i <= _end_; i++)
      if (a[i] < 0) {
        if (top && st[top] == -a[i])
          top--;
        else
          return 0;
      } else
        st[++top] = a[i];
    return top == 0;
  } else {
    int idl = id[ql], idr = id[qr];
    for (int i = (ql), _end_ = (B[idl].R); i <= _end_; i++)
      if (a[i] < 0) {
        if (!st.empty() && a[st.back().r] == -a[i])
          st.pop_back();
        else
          return 0;
      } else
        st.push_back(node(0, i));
    for (int i = (idl + 1), _end_ = (idr - 1); i <= _end_; i++) {
      if (B[i].FAKE) return 0;
      int len = B[i].lp;
      while (len > 0 && !st.empty()) {
        node t = st.back();
        st.pop_back();
        if (t.blk) {
          int bj = min(t.r, len);
          if (B[t.blk].SHash(t.r - bj + 1, t.r) !=
              B[i].PHash(len - bj + 1, len))
            return 0;
          len -= bj;
          t.r -= bj;
          if (t.r > 0) st.push_back(t);
        } else {
          if (a[t.r] == B[i].pa[len])
            t.r--, len--;
          else
            return 0;
        }
      }
      if (len) return 0;
      if (B[i].ls) st.push_back(node(i, B[i].ls));
    }
    for (int i = (B[idr].L), _end_ = (qr); i <= _end_; i++)
      if (a[i] < 0) {
        if (!st.empty()) {
          node t = st.back();
          st.pop_back();
          if ((t.blk ? B[t.blk].sa[t.r] : a[t.r]) != -a[i]) return 0;
          t.r--;
          if (t.r > 0) st.push_back(t);
        } else
          return 0;
      } else
        st.push_back(node(0, i));
  }
  return st.empty();
}
inline void doing() {
  int q = read();
  for (int i = (1), _end_ = (q); i <= _end_; i++) {
    int op = read(), x = read(), y = read();
    if (op == 1)
      a[x] = y, B[id[x]].BUILD();
    else {
      if (query(x, y))
        puts("Yes");
      else
        puts("No");
    }
  }
}
int main() {
  init();
  doing();
  return 0;
}
