#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n, 0);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(i); j++) ans += a[i] < a[j];
  if (ans & 1)
    printf("%d.000000\n", (ans - 1) << 1 + 1);
  else
    printf("%d.000000\n", ans << 2);
  return 0;
}
