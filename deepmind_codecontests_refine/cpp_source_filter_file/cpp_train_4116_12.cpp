#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 1.5e5 + 5;
const int S = 2e2;
int a[MAXN], bl[MAXN], Cnt[MAXN], q[MAXN], dfn[MAXN];
int L[S], R[S], tag[S];
int N, M, P, cnt, id;
mt19937 rng;
inline void spread(int x) {
  if (tag[x]) {
    for (int i = L[x]; i <= R[x]; i++) a[i] = tag[x];
    tag[x] = 0;
  }
}
inline void Modify(int l, int r, int x) {
  spread(bl[l]);
  spread(bl[r]);
  if (bl[l] == bl[r]) {
    for (int i = l; i <= r; i++) a[i] = x;
    return;
  }
  for (int i = l; i <= R[bl[l]]; i++) a[i] = x;
  for (int i = bl[l] + 1; i < bl[r]; i++) tag[i] = x;
  for (int i = L[bl[r]]; i <= r; i++) a[i] = x;
}
inline int Query(int x) {
  if (tag[bl[x]]) return tag[bl[x]];
  return a[x];
}
set<pair<int, int>> Sp;
inline void solve() {
  Sp.clear();
  for (int i = 1; i <= cnt; i++) Cnt[q[i]]++;
  id++;
  for (int i = 1; i <= cnt; i++) {
    if (dfn[q[i]] != id) Sp.insert(make_pair(-Cnt[q[i]], q[i]));
    dfn[q[i]] = id;
  }
  vector<int> ans;
  ans.clear();
  for (auto it = Sp.begin(); it != Sp.end(); it++) {
    ans.push_back((*it).second);
    if (ans.size() == P) break;
  }
  for (auto it = Sp.begin(); it != Sp.end(); it++) Cnt[(*it).second] = 0;
  printf("%d ", (int)ans.size());
  for (auto x : ans) printf("%d ", x);
  printf("\n");
}
inline int rnd(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}
int main() {
  N = read();
  M = read();
  P = 100 / read();
  for (int i = 1; i <= N; i++) a[i] = read();
  for (int i = 1; i <= N; i++) bl[i] = (i - 1) / S + 1;
  int cntS = bl[N];
  for (int i = 1; i <= cntS; i++) L[i] = (i - 1) * S + 1, R[i] = min(i * S, N);
  while (M--) {
    int opt = read(), l = read(), r = read();
    if (opt == 1) {
      int x = read();
      Modify(l, r, x);
    } else {
      cnt = 0;
      if (r - l + 1 <= S) {
        for (int i = l; i <= r; i++) q[++cnt] = Query(i);
      } else {
        for (int i = 1; i <= S; i++) q[++cnt] = Query(rnd(l, r));
      }
      solve();
    }
  }
  return 0;
}
