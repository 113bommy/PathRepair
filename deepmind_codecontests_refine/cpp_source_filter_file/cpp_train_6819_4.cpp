#include <bits/stdc++.h>
using namespace std;
int n;
int a[111111];
map<int, int> mm;
int ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    if (i <= n / 2)
      a[i] = a[i] - i;
    else
      a[i] = a[i] - (n - i + 1);
  }
  for (int i = 1; i <= n; i++) {
    mm[a[i]]++;
    if (a[i] > 0) ans = max(ans, mm[a[i]]);
  }
  printf("%d\n", n - ans);
  return 0;
}
