#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
int cnt[N], f[N], ar[N];
int main() {
  int l = 1, n, m, s = 1;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
    if (ar[i] <= m) f[ar[i]]++;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j += i) {
      cnt[j] += f[i];
    }
  }
  for (int i = 1; i <= m; i++) {
    if (cnt[i] > s) {
      s = cnt[i];
      l = i;
    }
  }
  printf("%d %d\n", l, s);
  for (int i = 1; i <= n; i++) {
    if (l % ar[i] == 0) printf("%d ", i);
  }
  return 0;
}
