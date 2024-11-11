#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110000], b[110000];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  sort(a, a + n), sort(b, b + n);
  long long sum = 0, ans = 0;
  if (a[n - 1] < b[m - 1]) swap(a, b), swap(n, m);
  for (int i = 0; i < m; i++) sum += b[i];
  ans += sum;
  for (int i = 0; i < n - 1; i++) ans += min(sum, (long long)a[i]);
  cout << ans << endl;
  return 0;
}
