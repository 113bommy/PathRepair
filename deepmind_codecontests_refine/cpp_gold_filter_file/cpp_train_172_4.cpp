#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 3e5 + 5;
const int M = 20;
long long power(long long x, unsigned long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long n, r;
  cin >> n >> r;
  long long sum = 0, m = 1LL << n;
  long long arr[m], i;
  for (i = 0; i < m; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  double ans = (sum * 1.0) / m;
  printf("%0.10lf\n", ans);
  for (i = 1; i <= r; i++) {
    long long idx, val;
    cin >> idx >> val;
    sum -= arr[idx];
    sum += val;
    arr[idx] = val;
    ans = (1.0 * sum) / m;
    printf("%0.10lf\n", ans);
  }
  return 0;
}
