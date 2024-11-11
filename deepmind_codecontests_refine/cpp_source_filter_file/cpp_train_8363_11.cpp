#include <bits/stdc++.h>
using namespace std;
const int maxn = 10, oo = ~0U >> 1;
int n, m;
int ans, resi, resj, resk;
int cnt[maxn];
int main() {
  int i, j, k;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; ++i) scanf("%d", &j), cnt[j]++;
  ans = oo;
  for (i = m / (cnt[3] + cnt[4] + cnt[5]); i >= 0; --i)
    for (j = min((i * cnt[3] + ans) / cnt[4], (m - cnt[3] * i) / (n - cnt[3]));
         j >= i; --j) {
      k = (m - i * cnt[3] - j * cnt[4]) / cnt[5];
      if (k * cnt[5] - j * cnt[4] >= ans) break;
      if (i * cnt[3] + j * cnt[4] + k * cnt[5] == m &&
          ans > abs(i * cnt[3] - j * cnt[4]) + abs(j * cnt[4] - k * cnt[5]))
        ans = abs(i * cnt[3] - j * cnt[4]) + abs(j * cnt[4] - k * cnt[5]),
        resi = i, resj = j, resk = k;
    }
  if (ans < oo)
    printf("%d %d %d", resi, resj, resk);
  else
    printf("-1");
  return 0;
}
