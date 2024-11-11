#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      res = res * x;
    }
    x = x * x;
    n = n / 2;
  }
  return res;
}
long long int powm(long long int a, long long int b) {
  long long int res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, k, i, j;
  cin >> n >> k;
  vector<long long int> v;
  for (i = 1; i <= 400000; i++) {
    v.push_back(i * (i + 1) / 2);
  }
  vector<long long int> f;
  for (i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      f.push_back(i);
      if (i != n / i) f.push_back(n / i);
    }
  }
  sort(f.begin(), f.end());
  reverse(f.begin(), f.end());
  for (i = 0; i < f.size(); i++) {
    auto it = lower_bound(v.begin(), v.end(), n / f[i]);
    long long int x;
    if (*it == n / f[i]) {
      x = it - v.begin() + 1;
    } else {
      x = it - v.begin();
    }
    if (k <= x) {
      vector<long long int> ans;
      long long int sum = 0;
      for (i = 1; i <= k - 1; i++) {
        ans.push_back(i);
        sum += i;
      }
      ans.push_back(n / f[i] - sum);
      for (j = 0; j < k; j++) {
        cout << f[i] * ans[j] << " ";
      }
      return 0;
    }
  }
  cout << -1;
}
