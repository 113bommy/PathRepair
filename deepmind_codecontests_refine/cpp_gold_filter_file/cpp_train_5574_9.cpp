#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int l = 1, r = n;
  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u > v) swap(u, v);
    l = max(l, u);
    r = min(r, v);
  }
  printf("%d\n", l > r ? 0 : r - l);
  return 0;
}
