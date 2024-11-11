#include <bits/stdc++.h>
using namespace std;
int n, ans, i, j;
int a[1000000], cnt[5];
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n, greater<int>());
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  ans += cnt[4];
  ans += cnt[3];
  cnt[1] -= cnt[3];
  ans += cnt[2] / 2 + cnt[2] % 2;
  if (cnt[2] % 2) cnt[1] -= 2;
  if (cnt[1] > 0) {
    if (cnt[1] % 4)
      ans += cnt[1] / 4 + 1;
    else
      ans += cnt[1] / 4;
  }
  printf("%d\n", ans);
  return 0;
}
