#include <bits/stdc++.h>
using namespace std;
long long mM(long long a, long long b, long long p = 998244353) {
  long long res = 0;
  if (a >= p) a %= p;
  while (b) {
    if (b & 1ll) res = (res + a);
    if (res >= p) res %= p;
    a = (2 * a);
    if (a >= p) a %= p;
    b >>= 1ll;
  }
  return res;
}
long long fpow(long long first, long long second, long long p = 998244353) {
  if (first >= p) first = first % p;
  long long res = 1;
  while (second) {
    if (second & 1ll) res *= first;
    if (res < 0) res += p;
    if (res >= p) res %= p;
    second = second >> 1ll;
    first *= first;
    if (first < 0) first += p;
    if (first >= p) first %= p;
  }
  return res;
}
long long inv(long long n, long long p = 998244353) {
  return fpow(n, p - 2, p);
}
long long modmul(long long first, long long second, long long p = 998244353) {
  if (first < 0) first += p;
  if (first >= p) first %= p;
  if (second < 0) second += p;
  if (second >= p) second %= p;
  return (first * second) % p;
}
long long modadd(long long first, long long second, long long p = 998244353) {
  if (first < 0) first += p;
  if (first >= p) first %= p;
  if (second < 0) second += p;
  if (second >= p) second %= p;
  long long temp = first + second;
  if (temp >= p) temp %= p;
  return temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1, tc = 0;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort((a).begin(), (a).end());
    int ans = INT_MAX;
    for (int minI = 0; minI < n; minI++)
      for (int maxI = minI; maxI < n; maxI++) {
        long long D = a[maxI] - a[minI];
        if (D <= d) {
          int tans = n - (maxI - minI + 1);
          ans = min(ans, tans);
        }
      }
    if (ans == INT_MAX) ans = 0;
    cout << ans << "\n";
  }
}
