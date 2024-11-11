#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r;
  scanf("%d %d %d", &n, &m, &r);
  int ar[n];
  for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
  int br[m];
  for (int i = 0; i < m; i++) scanf("%d", &br[i]);
  sort(ar, ar + n);
  sort(br, br + m, greater<int>());
  if (br[0] <= ar[0]) {
    printf("%d\n", r);
    return 0;
  }
  int mx = (r % ar[0]) + (r / ar[0]) * br[0];
  if (n > 1) mx = max(mx, (r - ar[1]) % ar[0] + ((r - ar[1]) / ar[0]) * br[0]);
  printf("%d\n", mx);
  return 0;
}
