#include <bits/stdc++.h>
using namespace std;
long long flag[100005] = {0};
long long a[100005] = {0};
long long b[100005] = {0};
vector<long long> v(100005);
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res % 1000003) * (a % 1000003);
    a = (a % 1000003) * (a % 1000003);
    b >>= 1;
  }
  return res % 1000003;
}
long long fact[1000007] = {0};
long long expo(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (1ll * res * x) % 1000000007;
    y = y >> 1;
    x = (1ll * x * x) % 1000000007;
  }
  return res;
}
void facto() {
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i < 100007; i++)
    fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long npr(long long n, long long r) {
  facto();
  long long res = 1;
  res = fact[n];
  res = (res * (expo(fact[n - r], 1000000007 - 2))) % 1000000007;
  return res;
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
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, d;
  cin >> n >> m >> d;
  long long a[n][m];
  long long k = n * m;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
      v.push_back(a[i][j]);
    }
  }
  sort(v.begin(), v.end());
  if (k % 2 == 1) {
    k = n / 2;
    long long b = v[k];
    long long cnt = 0;
    for (long long i = 0; i < n * m; i++) {
      if (abs(b - v[i]) % d == 0) {
        cnt += abs(b - v[i]) / d;
      } else {
        cout << "-1\n";
        exit(0);
      }
    }
    cout << cnt << "\n";
  } else {
    k = n / 2;
    long long b = v[k];
    long long cnt0 = 0, cnt1 = 0;
    for (long long i = 0; i < n * m; i++) {
      if (abs(b - v[i]) % d == 0) {
        cnt0 += abs(b - v[i]) / d;
      } else {
        cout << "-1\n";
        exit(0);
      }
    }
    k++;
    b = v[k];
    for (long long i = 0; i < n * m; i++) {
      if (abs(b - v[i]) % d == 0) {
        cnt1 += abs(b - v[i]) / d;
      } else {
        cout << "-1\n";
        exit(0);
      }
    }
    cout << min(cnt0, cnt1) << "\n";
  }
}
