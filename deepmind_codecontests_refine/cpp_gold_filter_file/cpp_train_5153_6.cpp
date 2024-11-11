#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
long long a[MAXN];
map<long long, long long> sum1, sum2;
long long l[MAXN], r[MAXN];
int main() {
  long long m, n, i, j, k;
  scanf("%I64d %I64d", &m, &n);
  for (i = 1; i <= m; i++) scanf("%I64d", &a[i]);
  for (i = 1; i <= m; i++) {
    if (a[i] % n == 0) {
      l[i] = sum1[a[i] / n];
    }
    sum1[a[i]]++;
  }
  long long ans = 0;
  for (i = m; i >= 1; i--) {
    r[i] = sum2[a[i] * n];
    sum2[a[i]]++;
  }
  for (i = 1; i <= m; i++) ans += (long long)r[i] * (long long)l[i];
  cout << ans << endl;
}
