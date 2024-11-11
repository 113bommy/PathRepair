#include <bits/stdc++.h>
using namespace std;
const double eps(1e-8);
int n, m;
int x[5010], cnt[1010], l[5010], r[5010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    l[i] = x[i];
    cnt[x[i]]++;
  }
  int Max = 0;
  sort(l + 1, l + 1 + n);
  for (int i = 1; i <= m; i++) Max = max(Max, cnt[i]);
  for (int i = Max + 1; i <= n; i++) r[i - Max] = l[i];
  for (int i = 1; i <= Max; i++) r[i + n - Max] = l[i];
  int ret = 0;
  for (int i = 1; i <= n; i++) ret += (l[i] != r[i]);
  cout << ret << endl;
  for (int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << endl;
  return 0;
}
