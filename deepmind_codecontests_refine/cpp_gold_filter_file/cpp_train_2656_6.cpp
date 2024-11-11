#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v;
};
struct bedge {
  int w, ind;
};
bool comp(bedge a, bedge b) { return a.w > b.w; };
int main() {
  enum { maxn = 100000, maxm = 100000 };
  int n, m;
  scanf("%d%d", &n, &m);
  static edge E[maxm];
  static bedge A[maxn];
  static bedge B[maxn];
  int anum = 0, bnum = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b == 1) {
      E[i] = (edge){0, anum + 1};
      A[anum] = (bedge){a, anum + 1};
      anum++;
    } else {
      B[bnum] = (bedge){a, i};
      bnum++;
    }
  }
  sort(A, A + anum, comp);
  sort(B, B + bnum, comp);
  int ptr = 0, nowcnt = n - 2;
  for (int i = 0; i < bnum; i++) {
    while (ptr < anum && A[ptr].w > B[i].w) {
      ptr++;
      nowcnt = n - 2 - ptr;
    }
    if (nowcnt == 0) {
      ptr++;
      nowcnt = n - 2 - ptr;
    }
    if (ptr >= anum - 1) {
      printf("-1\n");
      return 0;
    }
    nowcnt--;
    E[B[i].ind] = (edge){A[ptr].ind, A[ptr + n - 2 - ptr - nowcnt].ind};
  }
  for (int i = 0; i < m; i++) {
    printf("%d %d\n", E[i].u + 1, E[i].v + 1);
  }
  return 0;
}
