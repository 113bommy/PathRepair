#include <bits/stdc++.h>
using namespace std;
bitset<10005> f[105], g[105];
int arr[105], cnt[105], n, m;
set<int> ss;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
    m = max(m, arr[i]);
    ss.insert(arr[i]);
    ++cnt[arr[i]];
  }
  if ((int)ss.size() <= 2) return printf("%d\n", n) * 0;
  f[0].set(0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      auto p = f[j - 1] << arr[i];
      f[j] |= p;
      p.reset(j * arr[i]);
      g[j] |= g[j - 1] << arr[i] | p;
    }
  }
  int res = 0;
  for (int i : ss)
    for (int j = 1; j <= cnt[i] && !g[j].test(i * j); j++) res = max(res, j);
  printf("%d\n", res);
  return 0;
}
