#include <bits/stdc++.h>
using namespace std;
long long int pwr(long long int a, long long int b, long long int mod) {
  a %= mod;
  if (a < 0) a += mod;
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}
long long int gcd(long long int a, long long int b) {
  while (b) {
    long long int temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}
int main() {
  int n, i, j, h[100005], r[100005];
  cin >> n;
  for (i = 0; i < n; i++) cin >> h[i];
  r[n - 1] = h[n - 1];
  for (i = n - 2; i >= 0; i--) {
    r[i] = max(r[i + 1], h[i + 1]);
  }
  for (i = 0; i < n - 1; i++) {
    cout << max(0, r[i] - h[i] + 1) << " ";
  }
  cout << 0;
  return 0;
}
