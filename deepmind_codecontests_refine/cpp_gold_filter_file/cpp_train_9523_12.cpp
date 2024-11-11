#include <bits/stdc++.h>
using namespace std;
long long bin_pow(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long t = bin_pow(a, b / 2);
    return t * t % 1000000007;
  } else
    return a * bin_pow(a, b - 1) % 1000000007;
}
bool used[51];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1, n, m, k = 0, x = 0, y = 0, z = 0, sum = 0, l = 0, r = 0,
            ans = 0, mn = LLONG_MAX, mx = LLONG_MIN;
  cin >> n >> m;
  vector<long long> a, b(n);
  for (int i = 0; i < n; i++) a.push_back(i + 1);
  x = (1LL << (n - 2));
  l = 0;
  r = n - 1;
  for (int i = 0; i < n - 1; i++) {
    if (m <= x)
      b[l] = i + 1, l++;
    else
      b[r] = i + 1, r--, m -= x;
    x /= 2;
  }
  b[l] = n;
  for (auto u : b) cout << u << " ";
  return 0;
}
