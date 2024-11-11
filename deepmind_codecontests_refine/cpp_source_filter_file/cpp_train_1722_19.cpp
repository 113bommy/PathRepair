#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
const long long int N = 5e6 + 1;
long long int power(long long int x, long long int y, long long int M = ::M) {
  x %= M;
  long long int ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % M;
    y >>= 1LL;
    x = (x * x) % M;
  }
  return ans;
}
long long int add(long long int a, long long int b) {
  return ((a % M + b % M) % M);
}
long long int sub(long long int a, long long int b) {
  return ((a % M - b % M + M) % M);
}
long long int mul(long long int a, long long int b) {
  return (((a % M) * (b % M)) % M);
}
long long int divi(long long int a, long long int b) {
  return (mul(a, power(b, M - 2)) % M);
}
vector<long long int> lagega, hain;
bool banega(long long int n, long long int k, long long int mid) {
  for (int i = 0; i < n; i++) {
    long long int val = lagega[i] * mid;
    if (val <= hain[i]) continue;
    if (val <= hain[i] + k) {
      k = k - (val - hain[i]);
      continue;
    }
    return false;
  }
  return true;
}
inline void solve() {
  long long int n, k;
  cin >> n >> k;
  lagega.resize(n + 1);
  hain.resize(n + 1);
  for (int i = 0; i < n; i++) cin >> lagega[i];
  for (int i = 0; i < n; i++) cin >> hain[i];
  long long int l = 0, h = 1e18;
  while (l <= h) {
    long long int mid = (l + h) / 2;
    if (banega(n, k, mid)) {
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  cout << l - 1;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
