#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
signed main(void) {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  vector<long long> num(101, 0);
  for (long long i = 0; i < (n); i++) {
    long long sum = a[i];
    long long k = 1, ans = 0;
    while (k <= 100 && sum <= m) {
      long long cnt = min((m - sum) / k, num[k]);
      ans += cnt;
      sum += num[k] * k;
      k++;
    }
    cout << i - ans << " ";
    num[a[i]]++;
  }
  cout << endl;
}
