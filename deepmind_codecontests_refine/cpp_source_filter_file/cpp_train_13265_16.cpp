#include <bits/stdc++.h>
using namespace std;
long long int dp[502][22 * 502];
int n;
vector<int> v;
bool use[100000];
vector<long long int> prime;
long long int ans = 1;
long long int ff[1000];
long long int ppow(long long int i, long long int j) {
  long long int r = 1;
  while (j > 0) {
    if (j & 1) {
      r *= i;
      r %= 1000000007;
    }
    i *= i;
    i %= 1000000007;
    j >>= 1;
  }
  return r % 1000000007;
}
long long int c(long long int a, long long int b) {
  long long int m = ff[a];
  m = m * ppow(ff[a - b], 1000000007 - 2);
  m %= 1000000007;
  long long int h = ff[b];
  long long int r = m * ppow(h, 1000000007 - 2);
  r %= 1000000007;
  return r;
}
int main() {
  ff[0] = 1;
  for (int i = 1; i < 1000; i++) {
    ff[i] = ff[i - 1];
    ff[i] *= (long long int)i;
    ff[i] %= 1000000007;
  }
  scanf("%d", &n);
  prime.push_back(2);
  for (int i = 3; i < 100000; i += 2) {
    if (use[i] == false) {
      prime.push_back(i);
      for (int j = i * 2; j < 100000; j += i) {
        use[j] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= a; i++) {
      while (a % prime[i] == 0) {
        v.push_back(prime[i]);
        a /= prime[i];
      }
    }
    if (a != 1) {
      v.push_back(a);
    }
  }
  sort(v.begin(), v.end());
  {
    int i = 0;
    while (i < v.size()) {
      long long int k = v[i];
      int countt = 0;
      while (i < v.size() && v[i] == k) {
        i++;
        countt++;
      }
      ans *= c(countt + n - 1, countt);
      ans %= 1000000007;
    }
  }
  ans %= 1000000007;
  printf("%I64d\n", ans);
  return 0;
}
