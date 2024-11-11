#include <bits/stdc++.h>
using namespace std;
long long mod = pow(10, 9) + 7;
long long n, m, a[1000005], i, j, t, k;
long long prime[1000005] = {0};
vector<long long> vprime;
long long max3(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
long long min3(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
long long inv(long long x1, long long y1) {
  if (y1 == 0) return 1;
  long long temp = inv(x1, y1 / 2);
  temp = (temp * temp) % mod;
  if (y1 % 2) temp = (temp * x1) % mod;
  return temp;
}
long long inv1(long long a1, long long m1) {
  long long m0 = m1, x0 = 0, y0 = 1;
  if (m1 == 1) return 0;
  while (a1 > 1) {
    long long q = a1 / m1;
    long long temp = m1;
    m1 = a1 % m1;
    a1 = temp;
    temp = y0;
    y0 = x0 - q * y0;
    x0 = temp;
  }
  x0 = (x0 + m0) % m0;
  return x0;
}
void sieve() {
  prime[1] = 1;
  for (i = 2; i < 1000; i++) {
    if (prime[i] == 0) {
      for (j = i * i; j <= 1000000; j += i) prime[j] = 1;
    }
  }
  for (i = 2; i < 1000001; i++) {
    if (prime[i] == 0) vprime.push_back(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    long long f = 0;
    for (i = 0; i < k - 2; i++) {
      if (s[i] != s[k - 1]) f = 1;
    }
    if (f == 1) {
      cout << s[k - 1] << "\n";
      continue;
    }
    f = 0;
    for (i = k; i < n - 1; i++) {
      if (s[i] != s[i + 1]) f = 1;
    }
    if (f == 1) {
      for (i = k - 1; i < n; i++) cout << s[i];
      cout << "\n";
      continue;
    }
    long long d = (n - k) / k;
    if ((n - k) % k != 0) d++;
    cout << s[k - 1];
    for (i = 0; i < d; i++) {
      cout << s[k];
    }
    cout << "\n";
  }
  return 0;
}
