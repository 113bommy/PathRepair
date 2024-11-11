#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) { return a < b ? a : b; }
int tm[100005];
int ll[100005];
int rr[100005];
int main() {
  int n, i, j, tt, m;
  scanf("%d", &n);
  int h = 1;
  int e = n;
  for (i = 1; i <= n; i++) scanf("%d", &tm[i]);
  tm[0] = 2147483647 - 1;
  tm[n + 1] = 2147483647 - 1;
  for (i = 1; i <= n; i++) ll[i] = min(i, min(tm[i], ll[i - 1] + 1));
  for (i = n; i >= 1; i--) rr[i] = min(n - i + 1, min(tm[i], rr[i + 1] + 1));
  int maxx = 0;
  for (i = 1; i <= n; i++) {
    tm[i] = min(ll[i], rr[i]);
    if (tm[i] > maxx) maxx = tm[i];
  }
  printf("%d\n", maxx);
  return 0;
}
