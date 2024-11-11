#include <bits/stdc++.h>
int anext[200000];
int n;
int next(int v) {
  if (v == n || v == anext[v]) return v;
  return anext[v] = next(anext[v]);
}
int maxsize[200000];
int count[200000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &maxsize[i]);
    count[i] = 0;
    anext[i] = i;
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int p, x;
      scanf("%d %d", &p, &x);
      p--;
      while (x > 0) {
        p = next(p);
        if (p == n) break;
        int add =
            ((x) < (maxsize[p] - count[p]) ? (x) : (maxsize[p] - count[p]));
        count[p] += add;
        x -= add;
        if (count[p] == maxsize[p]) {
          if (p < n)
            anext[p] = anext[p + 1];
          else
            anext[p] = n;
        }
      }
    } else {
      int k;
      scanf("%d", &k);
      k--;
      printf("%d\n", count[k]);
    }
  }
}
