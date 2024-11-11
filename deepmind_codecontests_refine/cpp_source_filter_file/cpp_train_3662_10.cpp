#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 4e5 + 10;
const int mod = 998244353;
const int inf = 1e9 + 7;
const int mo = 1e9 + 7;
const int N = 1e6 + 10;
long long i, j, k, n, m, ff, I, pos, dis, dif;
long long a[MAXN], b[MAXN], sum[MAXN];
long long fpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b /= 2;
  }
  return ans;
}
int main() {
  scanf("%lld%lld", &n, &I);
  long long ss = min(31LL, 8 * I / n);
  k = fpow(2, ss);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  pos = unique(b + 1, b + n + 1) - b - 1;
  for (i = 1; i <= n; i++) {
    sum[lower_bound(b + 1, b + n + 1, a[i]) - b]++;
  }
  for (i = 1; i <= pos; i++) sum[i] += sum[i - 1];
  if (pos <= k)
    printf("0\n");
  else {
    long long minn = 1e18, num;
    for (i = 1; i <= pos - k + 1; i++) {
      num = n - (sum[i + k - 1] - sum[i - 1]);
      minn = min(minn, num);
    }
    printf("%lld\n", minn);
  }
}
