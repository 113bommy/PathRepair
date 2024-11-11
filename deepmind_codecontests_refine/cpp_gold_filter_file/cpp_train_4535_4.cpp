#include <bits/stdc++.h>
using namespace std;
long long x[300010], sum1[300010], sum2[300010];
int main() {
  int n, i, pos;
  long long minx, ans;
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%I64d", &x[i]);
  sort(x + 1, x + 1 + n);
  sum1[0] = 0;
  for (i = 1; i <= n; i++) sum1[i] = sum1[i - 1] + x[i];
  sum2[n + 1] = 0;
  for (i = n; i >= 1; i--) sum2[i] = sum2[i + 1] + x[i];
  pos = 1;
  minx = sum2[1] - n * x[1];
  for (i = 2; i <= n; i++) {
    ans = (i - 1) * x[i] - sum1[i - 1] + sum2[i + 1] - (n - i) * x[i];
    if (ans < minx) {
      minx = ans;
      pos = i;
    }
  }
  cout << x[pos] << endl;
  return 0;
}
