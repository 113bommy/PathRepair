#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long xor1_n(long long n) {
  switch (n % 4) {
    case 0:
      return n;
    case 1:
      return 1;
    case 2:
      return n + 1;
  }
  return 0;
}
long long ncr(long long n, long long r) {
  long long res = 1;
  if (r > n - r) r = n - r;
  for (long long i = 0; i < r; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}
clock_t time_p = clock();
void rtime() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long power(long long a, long long b, long long m = mod) {
  long long ans = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) ans = (1ll * a * ans) % m;
    b >>= 1;
    a = (1ll * a * a) % m;
  }
  return ans;
}
long long rr[] = {
    0, 1, 1, 1, 0, -1, -1, -1,
};
long long cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], h[2] = {0};
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      h[a[i] % 2]++;
    }
    if (h[1] % 2 == 0)
      cout << h[0];
    else
      cout << 1;
  }
  rtime();
  return 0;
}
