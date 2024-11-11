#include <bits/stdc++.h>
using namespace std;
bool hash[1000010];
int h[1000010], pa[1000010];
int a[5002];
int n, k, i, j, limited, maxx, tmp, sum;
bool flag;
bool check(int x) {
  int i, rec, tmp;
  rec = 0;
  for (i = 1; i <= n; ++i) {
    tmp = a[i] % x;
    if (h[tmp] == x)
      rec++;
    else
      h[tmp] = x;
  }
  if (rec > k) return false;
  return true;
}
int main() {
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  limited = a[n] + 1;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= i - 1; ++j) pa[a[i] - a[j]]++;
  limited = a[n] + 1;
  maxx = (k + 1) * k / 2;
  for (i = 2; i <= limited; ++i) {
    sum = 0;
    tmp = limited / i;
    for (j = 0; j <= tmp; ++j) sum = sum + pa[i * j];
    if (sum <= k) {
      printf("%d\n", i);
      break;
    };
    if (sum > maxx) continue;
    if (check(i)) {
      printf("%d\n", i);
      break;
    }
  }
}
