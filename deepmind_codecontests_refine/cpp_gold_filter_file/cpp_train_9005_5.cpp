#include <bits/stdc++.h>
using namespace std;
int a[200006], p[200006];
int main() {
  int n, q, pos;
  int ls = -1;
  a[0] = -1;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (ls == a[i]) {
      p[i] = pos;
    } else {
      pos = p[i] = i - 1;
      ls = a[i];
    }
  }
  int l, r, x;
  while (q--) {
    scanf("%d %d %d", &l, &r, &x);
    if (a[r] != x) {
      printf("%d\n", r);
    } else {
      if (p[r] < l)
        printf("-1\n");
      else
        printf("%d\n", p[r]);
    }
  }
}
