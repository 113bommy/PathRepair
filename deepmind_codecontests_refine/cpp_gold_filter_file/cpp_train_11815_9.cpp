#include <bits/stdc++.h>
#pragma GCC optimize("O3")
int mod = 1000000007;
using namespace std;
bool isp(long long x) {
  for (long long i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
void pog() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
}
bool sortinrev(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.first > b.first);
}
bool prime_check(long long n) {
  bool flag = 1;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      flag = 0;
      break;
    }
  }
  return flag;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
void Main() {
  long long n;
  cin >> n;
  long long a;
  cin >> a;
  long long arr[n];
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  for (long long i = 0; i < n; i++) {
    long long f = max(1ll, a - (sum - arr[i]));
    long long g = min(1ll * arr[i], a - n + 1);
    cout << arr[i] - (g - f + 1) << " ";
  }
  cout << "\n";
}
int32_t main() {
  srand(time(0));
  pog();
  long long t = 1;
  while (t--) {
    Main();
  }
}
