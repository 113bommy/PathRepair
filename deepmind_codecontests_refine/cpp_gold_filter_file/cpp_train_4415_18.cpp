#include <bits/stdc++.h>
#pragma GCC optimize(1)
#pragma G++ optimize(1)
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#pragma GCC optimize(3)
#pragma G++ optimize(3)
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
using namespace std;
inline void rdl(long long &val) {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' or ch > '9') and ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' and ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  val = x * f;
}
inline void rdi(int &val) {
  int x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' or ch > '9') and ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' and ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  val = x * f;
}
inline long long rdl() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' or ch > '9') and ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' and ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline int rdi() {
  int x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' or ch > '9') and ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' and ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void _write(int x) {
  write(x);
  putchar(' ');
}
inline void print(int x) {
  write(x);
  putchar('\n');
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void _write(long long x) {
  write(x);
  putchar(' ');
}
inline void print(long long x) {
  write(x);
  putchar('\n');
}
struct dsu {
  int par[200200];
  inline void init(int _n) {
    for (int i = 0; i < _n; ++i) par[i] = i;
  }
  inline int find(int now) {
    if (par[now] == now) return now;
    return par[now] = find(par[now]);
  }
  inline bool uni(int a, int b) {
    int Pa(find(a)), Pb(find(b));
    if (Pa == Pb) return false;
    par[Pa] = Pb;
    return true;
  }
};
const int mxn = 2e5, mxnum = 314000000;
int ntf, nt;
int dest[mxn], cntdest[mxn], dia[mxn], fst[mxn], id[mxn], src[mxn],
    mincost[mxn], curmin[mxn], curdead[mxn];
int heap[mxn], numheap, heapat[mxn], nxtsamesrc[mxn], fstbysrc[mxn];
int maxcost[mxn];
inline void swap(int a, int b) {
  int t = heap[a];
  heap[a] = heap[b];
  heap[b] = t;
  heapat[heap[a]] = a;
  heapat[heap[b]] = b;
}
inline void heapdown(int at) {
  while (1) {
    int i = at;
    if (2 * at + 1 < numheap and curmin[heap[2 * at + 1]] < curmin[heap[i]])
      i = 2 * at + 1;
    if (2 * at + 2 < numheap and curmin[heap[2 * at + 2]] < curmin[heap[i]])
      i = 2 * at + 2;
    if (i == at) break;
    swap(at, i);
    at = i;
  }
}
inline void heapup(int at) {
  while (at > 0) {
    int i = (at - 1) >> 1;
    if (curmin[heap[i]] > curmin[heap[at]]) {
      swap(at, i);
      at = i;
    } else
      break;
  }
}
int main() {
  rdi(ntf);
  rdi(nt);
  int i, j, cnt = 0;
  for (i = 0; i < ntf; ++i) {
    fst[i] = cnt;
    dest[i] = rdi() - 1;
    int len = rdi();
    for (j = 0; j < len; ++j) {
      int cur = rdi();
      if (~cur) {
        --cur;
        id[cnt] = i;
        src[cnt] = cur;
        ++cnt;
      } else
        ++dia[i];
    }
  }
  fst[ntf] = cnt;
  memset(mincost, -1, sizeof(mincost));
  memcpy(curmin, dia, sizeof(dia));
  memset(fstbysrc, -1, sizeof(fstbysrc));
  for (i = 0; i < cnt; ++i) {
    nxtsamesrc[i] = fstbysrc[src[i]];
    fstbysrc[src[i]] = i;
  }
  numheap = 0;
  for (i = 0; i < ntf; ++i) {
    if (fst[i + 1] - fst[i] == curdead[i]) {
      heap[numheap++] = i;
      heapat[i] = numheap - 1;
      heapup(numheap - 1);
    }
  }
  while (numheap > 0) {
    int cur = heap[0];
    swap(0, numheap - 1);
    --numheap;
    if (numheap > 1) heapdown(0);
    heapat[cur] = -1;
    if (mincost[dest[cur]] >= 0) continue;
    mincost[dest[cur]] = curmin[cur];
    int at = fstbysrc[dest[cur]];
    while (at >= 0) {
      curmin[id[at]] += curmin[cur];
      if (curmin[id[at]] >= mxnum) curmin[id[at]] = mxnum;
      ++curdead[id[at]];
      int del = curdead[id[at]] - (fst[id[at] + 1] - fst[id[at]]);
      if (del >= 0) {
        if (del > 0) exit(0);
        heap[numheap++] = id[at];
        heapat[id[at]] = numheap - 1;
        heapup(numheap - 1);
      }
      at = nxtsamesrc[at];
    }
  }
  memcpy(curmin, dia, sizeof(dia));
  memset(curdead, 0, sizeof(curdead));
  for (i = 0; i < ntf; ++i) {
    bool ok = 1;
    for (j = fst[i]; j < fst[i + 1]; ++j)
      if (mincost[src[j]] < 0) ok = 0;
    if (ok) ++cntdest[dest[i]];
  }
  numheap = 0;
  for (i = 0; i < nt; ++i)
    if (mincost[i] >= 0 and cntdest[i] == 0) heap[numheap++] = i;
  for (i = 0; i < ntf; ++i) {
    if (fst[i + 1] - fst[i] == curdead[i] and mincost[dest[i]] >= 0) {
      maxcost[dest[i]] = max(maxcost[dest[i]], curmin[i]);
      if (maxcost[dest[i]] >= mxnum) maxcost[dest[i]] = mxnum;
      --cntdest[dest[i]];
      if (cntdest[dest[i]] == 0) heap[numheap++] = dest[i];
    }
  }
  while (numheap > 0) {
    int cur = heap[--numheap];
    int at = fstbysrc[cur];
    while (at >= 0) {
      if (mincost[dest[id[at]]] >= 0) {
        curmin[id[at]] += maxcost[cur];
        if (curmin[id[at]] >= mxnum) curmin[id[at]] = mxnum;
        ++curdead[id[at]];
        int del = curdead[id[at]] - (fst[id[at] + 1] - fst[id[at]]);
        if (del >= 0) {
          if (del > 0) exit(0);
          maxcost[dest[id[at]]] = max(maxcost[dest[id[at]]], curmin[id[at]]);
          --cntdest[dest[id[at]]];
          if (cntdest[dest[id[at]]] <= 0) {
            if (cntdest[dest[id[at]]] < 0) exit(0);
            heap[numheap++] = dest[id[at]];
          }
        }
      }
      at = nxtsamesrc[at];
    }
  }
  for (i = 0; i < nt; ++i) {
    if (mincost[i] < 0)
      puts("-1 -1");
    else {
      _write(mincost[i]);
      if (cntdest[i] > 0)
        print(-2);
      else
        print(maxcost[i]);
    }
  }
}
