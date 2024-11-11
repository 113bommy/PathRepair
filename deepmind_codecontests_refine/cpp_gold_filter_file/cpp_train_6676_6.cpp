#include <bits/stdc++.h>
using namespace std;
long long power(long long n, long long k) {
  if (k == 0) return 1;
  long long x = power(n, k / 2);
  x = (x * x) % 998244353;
  if (k & 1) x = (x * n) % 998244353;
  return x;
}
void fft(vector<long long> &a, bool invert) {
  long long n = a.size(), i, j, k, m;
  for (i = 1, j = 0; i < n; i++) {
    k = n / 2;
    while (j >= k) {
      j -= k;
      k /= 2;
    }
    j += k;
    if (i < j) swap(a[i], a[j]);
  }
  m = n / 2;
  long long t, w, rj;
  for (i = 1; i < n; i *= 2, m /= 2) {
    long long tt = 998244353 - 1;
    tt /= 2 * i;
    if (invert) tt = 998244353 - tt - 1;
    rj = power(3, tt);
    for (j = 0; j < m; j++) {
      w = 1;
      for (k = 0; k < i; k++) {
        t = (a[k + j * i * 2] - (w * a[k + j * i * 2 + i]) % 998244353 +
             998244353) %
            998244353;
        a[k + j * i * 2] =
            (a[k + j * i * 2] + w * a[k + j * i * 2 + i]) % 998244353;
        a[k + j * i * 2 + i] = t;
        w = (w * rj) % 998244353;
      }
    }
  }
  if (invert) {
    for (auto &i : a) i = (i * power(n, 998244353 - 2)) % 998244353;
  }
}
vector<long long> pol_multiply(vector<long long> v1, vector<long long> v2) {
  vector<long long> a1, a2;
  long long m = max(v1.size(), v2.size()), n;
  m--;
  n = m;
  while (n) {
    m = (n | m);
    n = n >> 1;
  }
  m++;
  m *= 2;
  while (v1.size() < m) v1.push_back(0);
  while (v2.size() < m) v2.push_back(0);
  fft(v1, 0);
  fft(v2, 0);
  for (long long i = 0; i < m; i++) {
    v1[i] = (v1[i] * v2[i]) % 998244353;
  }
  fft(v1, 1);
  while (v1.size() > 1 and v1[v1.size() - 1] == 0) v1.pop_back();
  return v1;
}
vector<long long> pol_power(vector<long long> v, long long k) {
  long long m = v.size(), n;
  m--;
  n = m;
  while (n) {
    m = (n | m);
    n = n >> 1;
  }
  m++;
  while (v.size() != m) v.push_back(0);
  fft(v, 0);
  for (auto &i : v) i = power(i, k);
  fft(v, 1);
  return v;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k, x, i, ans = 0;
  cin >> n >> k;
  n = n / 2;
  vector<long long> v(10 * n + 10), vv;
  for (i = 0; i < 10 * n + 10; i++) v[i] = 0;
  for (i = 0; i < k; i++) {
    cin >> x;
    v[x] = 1;
  }
  vv = pol_power(v, n);
  for (auto i : vv) {
    ans = (ans + (i * i) % 998244353) % 998244353;
  }
  cout << ans;
  return 0;
}
