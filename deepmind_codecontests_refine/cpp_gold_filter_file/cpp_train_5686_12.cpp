#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int n;
struct node {
  int l, r;
  int ok;
  node() { ok = 0; }
} E1[200000 + 5], E2[200000 + 5];
int cmp(node a, node b) { return a.l < b.l; }
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &E1[i].l, &E1[i].r);
      E1[i].ok = 0;
      E2[i].ok = 0;
    }
    sort(E1, E1 + n, cmp);
    int r = E1[0].r;
    E1[0].ok = 1;
    int ans1 = 1;
    for (int i = 1; i < n; i++) {
      if (E1[i].l <= r) continue;
      E1[i].ok = 1;
      r = E1[i].r;
      ans1++;
    }
    if (ans1 == n) {
      puts("YES");
    } else {
      int p = 0;
      for (int i = 0; i < n; ++i) {
        if (E1[i].ok == 0) {
          E2[p++] = E1[i];
        }
      }
      sort(E2, E2 + p, cmp);
      r = E2[0].r;
      int ans2 = 1;
      for (int i = 1; i < p; i++) {
        if (E2[i].l <= r) continue;
        E2[i].ok = 1;
        r = E2[i].r;
        ans2++;
      }
      if (ans1 + ans2 == n)
        puts("YES");
      else
        puts("NO");
    }
  }
}
