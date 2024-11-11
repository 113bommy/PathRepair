#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int w[1000005];
int b[1000005];
int L[1000005];
bool cmp(int x, int y) { return x > y; }
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    w[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    b[i] = w[b[i]];
  }
  int r = 0;
  for (int i = 1; i <= n; i++) {
    if (r == 0 || b[i] < L[r - 1])
      L[r++] = b[i];
    else if (b[i] > L[0])
      L[0] = b[i];
    else {
      int p = lower_bound(L, L + r, b[i], cmp) - L;
      L[p] = b[i];
    }
  }
  printf("%d\n", r);
  return 0;
}
