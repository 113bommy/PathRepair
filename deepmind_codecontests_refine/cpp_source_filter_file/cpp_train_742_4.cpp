#include <bits/stdc++.h>
using namespace std;
struct type {
  long long k, i, j;
};
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long findSubarray(long long arr[], long long n, long long k) {
  long long window_sum = 0;
  long long min_window = INT_MAX;
  long long last = 0;
  for (long long i = 0; i < n; i++) {
    window_sum += arr[i];
    if (i + 1 >= k) {
      if (min_window > window_sum) {
        min_window = window_sum;
        last = i;
      }
      window_sum -= arr[i + 1 - k];
    }
  }
  long long sum = 0;
  for (long long i = last - k + 1; i <= last; i++) {
    sum += arr[i];
  }
  return sum;
}
long long nextpermutation(vector<long long> v) {
  vector<long long> t = v;
  sort((t).begin(), (t).end());
  long long x = 0;
  while (true) {
    x++;
    if (t == v) {
      return x;
    }
    next_permutation((t).begin(), (t).end());
  }
}
vector<long long> factors(long long n) {
  vector<long long> ans;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n == i * i)
        ans.push_back(i);
      else {
        ans.push_back(i);
        if (i != n / i) ans.push_back(n / i);
      }
    }
  }
  return ans;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y / 2;
    x = (x * x) % p;
  }
  return res;
}
bool isSubSequence(char str1[], char str2[], long long m, long long n) {
  if (m == 0) return true;
  if (n == 0) return false;
  if (str1[m - 1] == str2[n - 1])
    return isSubSequence(str1, str2, m - 1, n - 1);
  return isSubSequence(str1, str2, m, n - 1);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout << fixed << setprecision(12);
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  long long mod = 998244353;
  for (long long i = 0; i < n; i++) {
    a[i] = (a[i] * (i + 1) * (n - i)) % mod;
  }
  sort((a).begin(), (a).end());
  sort((b).rbegin(), (b).rend());
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    ans += ((a[i] % mod) * (b[i] % mod)) % mod;
  }
  cout << (ans % mod) << "\n";
}
