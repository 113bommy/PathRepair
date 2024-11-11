#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 3e5 + 5;
long long po(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long arr[N];
long long n, m;
long long bins(long long val) {
  long long l = 0, r = n;
  while (l != r) {
    long long mid = ((l + r) >> 1);
    if (arr[mid] > val)
      r = mid;
    else
      l = mid;
    if (r - l == 1)
      if (arr[r] > val)
        r = l;
      else
        l = r;
  }
  return l;
}
void sol() {
  cin >> n >> m;
  arr[0] = -(1e18 + 9);
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  sort(arr, arr + n + 1);
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    cout << bins(x) << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    sol();
  }
}
