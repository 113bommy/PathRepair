#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int modd = 998244353;
const long long int N = 200005;
const long long int oo = 1000000000;
long long int n, k;
long long int a[N];
bool f(long long int c) {
  long long int x = 0;
  for (long long int i = n / 2; i < n; i++) {
    if (c - a[i] > 0) x += c - a[i];
    if (x > k) return false;
  }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  multiset<long long int> ms;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long int l = a[n / 2], r = 5 * oo;
  while (l <= r) {
    if (l == r) {
      cout << l;
      return 0;
    }
    long long int mid = (l + r + 1) / 2;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return 0;
}
