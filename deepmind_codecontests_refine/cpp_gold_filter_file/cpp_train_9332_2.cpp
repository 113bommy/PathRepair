#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
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
int ncr(int n, int r) {
  int res = 1;
  if (r > n - r) r = n - r;
  for (int i = 0; i < r; i++) {
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
long long comp(long long a, long long b) { return (a < b); }
int rr[] = {
    0, 1, 1, 1, 0, -1, -1, -1,
};
int cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    long long ans = 2e18;
    for (int i = 0; i < n; i++) {
      long long c = -2e18;
      for (int j = 0; j < n; j++) {
        if (i != j) {
          for (int k = 0; k < m; k++) {
            c = max(c, 1ll * a[j] * b[k], comp);
          }
        }
      }
      ans = min(c, ans, comp);
    }
    cout << ans;
  }
  rtime();
  return 0;
}
