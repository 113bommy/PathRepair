#include <bits/stdc++.h>
using namespace std;
int a[110000];
int sol[110000], pos;
int solve(int n) {
  int bs = 0, i;
  pos = 0;
  sol[0] = -1;
  for (i = 0; i < n; i++) {
    if (a[i] > sol[pos]) {
      pos++;
      sol[pos] = a[i];
      if (pos > bs) bs = pos + 1;
      continue;
    }
    int npos = lower_bound(sol, sol + pos, a[i]) - sol;
    sol[npos] = a[i];
  }
  return bs;
}
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("%d\n", solve(n));
  return 0;
}
