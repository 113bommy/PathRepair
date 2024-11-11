#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 1e3 + 5, M = 3e5 + 5;
int n, m, d;
int a[N], cnt[N], cum[N];
int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 0; i < m; ++i) scanf("%d", a + i);
  for (int i = m - 1; ~i; --i) cnt[i] = a[i] + cnt[i + 1];
  int i = 0;
  for (int j = 0; j < m && i <= n; ++j) {
    int idx = min(n - cnt[j], i + d);
    ++cum[idx];
    i = idx + a[j] - 1;
    --cum[i + 1];
  }
  if (i + d < n) exit(puts("NO"));
  puts("YES");
  int hna = 1;
  int here = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    cum[i] += cum[i - 1];
    if (cum[i]) {
      if (a[j] == here) ++j, ++hna, here = 0;
      printf("%d%c", hna, " \n"[i == n]);
      ++here;
      continue;
    }
    printf("0%c", " \n"[i == n]);
  }
  cout << endl;
}
