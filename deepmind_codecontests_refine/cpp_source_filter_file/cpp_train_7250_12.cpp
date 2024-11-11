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
int n, ans, val[10] = {1}, ans1[11], ans2[11], ans3[1], p[11];
inline void dfs(int x) {
  if (val[x] == n and x == ans) {
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i)
      if (~ans2[i])
        printf("lea e%cx, [e%cx + %d*e%cx]\n", ans1[i] + 'a', ans2[i] + 'a',
               p[i], ans3[i] + 'a');
      else
        printf("lead e%cx,[%d*e%cx]\n", ans1[i] + 'a', p[i], ans3[i] + 'a');
    exit(0);
  }
  if (x == ans) return;
  for (int i = 0; i <= x; ++i)
    for (int j = -1; j <= x; ++j)
      for (int k = 1; k < 9; k <<= 1) {
        if (j + 1)
          val[x + 1] = val[i] * k + val[j];
        else
          val[x + 1] = val[i] * k;
        ans1[x] = x + 1, ans2[x] = j, ans3[x] = i, p[x] = k;
        dfs(x + 1);
      }
}
int main() {
  scanf("%d", &n);
  for (ans = 0; ans <= n; ++ans) dfs(0);
}
