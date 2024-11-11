#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct zt {
  int ss, ii;
} frm[1 << 22], ans[25];
struct node {
  int l, r, t, id;
} a[25], b[25];
bool cmp1(node aa, node bb) { return aa.l < bb.l; }
bool cmp2(node aa, node bb) { return aa.t < bb.t; }
int N, P, S, f[1 << 22];
void dfs(int s, int ii) {
  if (!s) return;
  ans[frm[s].ii] = (zt){frm[s].ss, ii};
  dfs(s ^ (1 << (frm[s].ii - 1)), ii);
}
void SLV1() {
  if (f[S] == inf) {
    puts("NO");
    exit(0);
  }
  puts("YES");
  dfs(S, 1);
  for (int i = 1; i <= N; i++) {
    printf("%d %d\n", ans[i].ii, ans[i].ss);
  }
}
void SLV2() {
  int s1 = 0;
  int s2 = -233;
  for (; s1 <= S; s1++) {
    if (f[s1] < inf && f[S ^ s1] < inf) {
      s2 = (S ^ s1);
      break;
    }
  }
  if (s2 == -233) {
    puts("NO");
    exit(0);
  }
  puts("YES");
  dfs(s1, 1);
  dfs(s2, 2);
  for (int i = 1; i <= N; i++) {
    printf("%d %d\n", ans[i].ii, ans[i].ss);
  }
}
int main() {
  scanf("%d%d", &N, &P);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
    a[i].id = i;
    a[i].r += a[i].l - 1;
    b[i] = a[i];
  }
  sort(a + 1, a + 1 + N, cmp1);
  sort(b + 1, b + 1 + N, cmp2);
  S = (1 << N) - 1;
  memset(f, 0x3f, sizeof f);
  f[0] = 1;
  for (int s = 0; s < S; s++) {
    if (f[s] != inf) {
      int tim = f[s];
      int pit = 1;
      for (int i = 1; i <= N; i++) {
        if ((s >> (b[i].id - 1)) & 1) continue;
        for (; pit <= N && tim + b[i].t >= a[pit].l; pit++) {
          if (tim >= a[pit].l || ((s >> (a[pit].id - 1)) & 1))
            tim = max(tim, a[pit].r + 1);
        }
        if (tim + b[i].t < b[i].l) {
          if (f[s | (1 << (b[i].id - 1))] > tim + b[i].t) {
            f[s | (1 << (b[i].id - 1))] = tim + b[i].t;
            frm[s | (1 << (b[i].id - 1))] = (zt){tim, b[i].id};
          }
        }
      }
    }
  }
  if (P == 1)
    SLV1();
  else
    SLV2();
}
