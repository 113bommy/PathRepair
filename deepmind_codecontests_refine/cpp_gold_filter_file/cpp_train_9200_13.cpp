#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
long long s[N];
long long p[N];
struct node {
  int l, r, d;
} t[N];
int main() {
  int n, m, k;
  while (EOF != scanf("%d%d%d", &n, &m, &k)) {
    for (int i = 1; i <= n; i++) scanf("%I64d", &s[i]);
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &t[i].l, &t[i].r, &t[i].d);
    int x, y;
    for (int i = n; i > 1; i--) s[i] -= s[i - 1];
    memset(p, 0, sizeof(p));
    int max = 0;
    while (k--) {
      scanf("%d%d", &x, &y);
      p[x]++;
      p[y + 1]--;
      if (y > max) max = y;
    }
    for (int i = 2; i <= max + 2; i++) p[i] += p[i - 1];
    for (int i = 1; i <= max; i++) {
      if (p[i] == 0) continue;
      s[t[i].l] += t[i].d * p[i];
      s[t[i].r + 1] -= t[i].d * p[i];
    }
    cout << s[1];
    for (int i = 2; i <= n; i++) {
      s[i] += s[i - 1];
      printf(" %I64d", s[i]);
    }
    printf("\n");
  }
  return 0;
}
