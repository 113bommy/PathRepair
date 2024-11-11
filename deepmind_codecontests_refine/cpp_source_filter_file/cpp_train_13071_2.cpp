#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int MAXN = 4e6 + 5;
long long sum[MAXN];
int main() {
  long long m, n, i, j, k;
  scanf("%I64d", &m);
  for (i = 1; i <= m; i++) scanf("%I64d", &n), sum[n]++;
  for (i = 1; i <= 4000000; i++) sum[i] += sum[i - 1];
  long long ans = -1;
  for (i = 1; i <= 300000; i++) {
    if (!(sum[i] - sum[i - 1])) continue;
    long long tmp = 0;
    for (j = i; j + i <= 300000; j += i) {
      tmp += (sum[j + i - 1] - sum[j - 1]) * j;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
