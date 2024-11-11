#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void amin(T &x, const T &y) {
  if (y < x) x = y;
}
template <class T>
inline void amax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class Iter>
void rprintf(const char *fmt, Iter begin, Iter end) {
  for (bool sp = 0; begin != end; ++begin) {
    if (sp)
      putchar(' ');
    else
      sp = true;
    printf(fmt, *begin);
  }
  putchar('\n');
}
int N;
int M;
int nxt[500011];
vector<int> G[1 << 20];
int deg[1 << 20];
void init() {
  for (int i = 0, i_len = (M * 2); i < i_len; ++i) {
    G[i].clear();
    deg[i] = 0;
  }
  for (int i = M; --i;) {
    deg[i] += 1;
  }
}
int stk[1 << 20];
int sz;
void add(int x, int y, int tar) {
  sz = 0;
  stk[sz++] = 0;
  stk[sz++] = M;
  stk[sz++] = 1;
  while (sz) {
    int k = stk[--sz];
    int r = stk[--sz];
    int l = stk[--sz];
    if (y <= l || r <= x) {
    } else if (x <= l && r <= y) {
      G[k].push_back(tar);
      deg[tar]++;
    } else {
      stk[sz++] = l;
      stk[sz++] = (l + r) / 2;
      stk[sz++] = k * 2;
      stk[sz++] = (l + r) / 2;
      stk[sz++] = r;
      stk[sz++] = k * 2 + 1;
    }
  }
}
int ans[1 << 20];
void MAIN() {
  scanf("%d", &N);
  for (int i = 0, i_len = (N); i < i_len; ++i) scanf("%d", nxt + i), nxt[i]--;
  M = 1;
  while (M < N) M *= 2;
  init();
  for (int i = 0, i_len = (N); i < i_len; ++i) {
    if (nxt[i] == -2) continue;
    if (nxt[i] < N) {
      G[M + i].push_back(M + nxt[i]);
      deg[M + nxt[i]]++;
    }
    if (i + 1 < nxt[i]) {
      add(i + 1, nxt[i], M + i);
    }
  }
  sz = 0;
  for (int i = 0, i_len = (M * 2); i < i_len; ++i)
    if (deg[i] == 0) stk[sz++] = i;
  int cnt = 0;
  while (sz) {
    int v = stk[--sz];
    if (M <= v && v < M + N) {
      ans[v - M] = ++cnt;
    }
    if (v > 1) {
      deg[v / 2]--;
      if (deg[v / 2] == 0) stk[sz++] = v / 2;
    }
    for (__typeof((G[v]).begin()) e = (G[v]).begin(), e_end = (G[v]).end();
         e != e_end; ++e) {
      deg[*e]--;
      if (deg[*e] == 0) {
        stk[sz++] = *e;
      }
    }
  }
  if (*max_element(deg, deg + M * 2) == 0) {
    rprintf("%d", ans, ans + N);
  } else {
    puts("-1");
  }
}
int main() {
  int TC = 1;
  scanf("%d", &TC);
  for (int tc = 0, tc_len = (TC); tc < tc_len; ++tc) MAIN();
  return 0;
}
