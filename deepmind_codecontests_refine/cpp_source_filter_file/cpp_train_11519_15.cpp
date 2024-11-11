#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dat[10010];
int solve() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%d", &dat[i]);
  if (n % 2 == 0) return 0;
  if (n > m + 1) return 0;
  int mini = 0x3fffffff;
  for (int i = 0; i < n; i += 2) mini = min(mini, dat[i]);
  int tp = m / (n / 2 + 1);
  if ((long long)tp * k > (long long)mini)
    return mini;
  else
    return tp * k;
}
int main() {
  printf("%d\n", solve());
  return 0;
}
