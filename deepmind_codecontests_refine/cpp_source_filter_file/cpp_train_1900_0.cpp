#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long z = 1000000000;
const long long N = 1e5 + 1;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
long long __gcd(long long a, long long b) {
  if (a == 0) return b;
  return __gcd(b % a, b);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    bool flag = 0;
    long long m = INT_MIN;
    for (long long i = 0; i < n; i++) {
      if (a[i] == k) {
        flag = 1;
        a[i] = 1;
      } else if (a[i] < k)
        a[i] = 0;
      else
        a[i] = 2;
    }
    if (flag == 0) {
      cout << "no" << endl;
      continue;
    }
    if (n == 1) {
      cout << "yes" << endl;
      continue;
    }
    bool flag2 = false;
    for (long long i = 0; i < n; i++) {
      for (long long j = i + 1; j < n && j - i <= 2; j++) {
        if (a[i] & a[j]) {
          flag2 = true;
          break;
        }
      }
      if (flag == true) {
        break;
      }
    }
    if (flag2)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}
