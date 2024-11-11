#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
long long k, sum;
int n, arr[N];
long long f(long long blockSize) {
  long long blockNum = sum / blockSize;
  long long cur = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] % blockSize == 0)
      cur += arr[i] / blockSize;
    else
      cur += arr[i] / blockSize + 1;
  }
  return cur <= blockNum;
}
int main() {
  scanf("%d %lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]), sum += arr[i];
  sum += k;
  long long ans = 0, upper = sqrt(sum);
  for (long long i = 1; i <= upper; i++) {
    if (f(i)) ans = max(ans, i);
    if (f(sum / i)) ans = max(ans, sum / i);
  }
  printf("%lld\n", ans);
  return 0;
}
