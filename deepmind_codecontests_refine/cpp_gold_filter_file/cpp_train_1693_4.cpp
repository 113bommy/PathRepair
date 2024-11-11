#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const long long N = 1e6 + 5;
long long mod = 1e9 + 7;
void pairsort(long long a[], long long b[], long long n) {
  pair<long long, long long> pairt[n];
  for (long long i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
long long pow1(long long n, long long p) {
  if (p == 0) return 1;
  long long x = pow1(n, p / 2);
  x = (x * x) % mod;
  if (p % 2 == 0)
    return x;
  else
    return (x * n) % mod;
}
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
bool compare(const pair<long long, long long> &p1,
             const pair<long long, long long> &p2) {
  if (p1.first < p2.first) return true;
  if (p1.first == p2.first) return p1.second < p2.second;
  return false;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long isPrime(long long n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 or n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return 0;
  return 1;
}
long long C(long long n, long long r) {
  if (r > n - r) r = n - r;
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % mod;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % mod;
    res %= mod;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, m, f = 0, flag = 0;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<long long> ans;
    for (long long i = n - 1; i >= 0; i--) {
      if (s[i] != t[i]) {
        if (s[0] == s[i]) {
          ans.push_back(i + 1);
          for (long long j = 0; j <= i; j++) {
            if (s[j] == '0')
              s[j] = '1';
            else
              s[j] = '0';
          }
          reverse(s.begin(), s.begin() + i + 1);
        } else {
          ans.push_back(1);
          if (s[0] == '0')
            s[0] = '1';
          else
            s[0] = '0';
          ans.push_back(i + 1);
          for (long long j = 0; j <= i; j++) {
            if (s[j] == '0')
              s[j] = '1';
            else
              s[j] = '0';
          }
          reverse(s.begin(), s.begin() + i + 1);
        }
      }
    }
    cout << ans.size() << " ";
    for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
