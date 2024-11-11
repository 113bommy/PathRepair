#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[110000], b[110000];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%I64d", &b[i]);
  }
  sort(a, a + n);
  sort(b, b + m);
  if (a[n - 1] < b[m - 1]) {
    for (int i = 0; i < max(n, m); i++) swap(a[i], b[i]);
    swap(n, m);
  }
  long long sum = 0;
  for (int i = 0; i < m; i++) sum += b[i];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += min(a[i], sum);
  }
  cout << ans << endl;
  return 0;
}
