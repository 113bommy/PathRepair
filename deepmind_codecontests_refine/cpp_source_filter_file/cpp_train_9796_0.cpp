#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long mulMod(long long x, long long y, long long p) {
  if (y == 0) return 0;
  if (x < 1000111000111000111LL / y) return x * y % p;
  long long mid = mulMod((x + x) % p, y >> 1LL, p);
  if (y & 1)
    return (mid + x) % p;
  else
    return mid;
}
long long powMod(long long x, long long k, long long m) {
  if (k == 0) return 1;
  if ((k & 1))
    return mulMod(x, powMod(x, k - 1, m), m);
  else
    return powMod(mulMod(x, x, m), k / 2, m);
}
bool suspect(long long a, long long s, long long d, long long n) {
  long long x = powMod(a, d, n);
  if (x == 1) return true;
  for (int r = 0; r < s; ++r) {
    if (x == n - 1) return true;
    x = mulMod(x, x, n);
  }
  return false;
}
bool isPrime(long long n) {
  if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
  long long test[] = {2,  3,  5,  7,  11, 13, 17, 19,
                      23, 29, 31, 37, 41, 43, 47, -1};
  long long d = n - 1, s = 0;
  while (d % 2 == 0) ++s, d /= 2;
  for (int i = 0; test[i] < n && test[i] != -1; ++i)
    if (!suspect(test[i], s, d, n)) return false;
  return true;
}
long long pollard_rho(long long n, long long seed) {
  long long x, y;
  x = y = rand() % (n - 1) + 1;
  int head = 1, tail = 2;
  while (true) {
    x = mulMod(x, x, n);
    x = (x + seed) % n;
    if (x == y) return n;
    long long d = gcd(max(x - y, y - x), n);
    if (1 < d && d < n) return d;
    if (++head == tail) y = x, tail <<= 1;
  }
}
void factorize(long long n, vector<long long> &divisor) {
  if (n == 1) return;
  if (isPrime(n))
    divisor.push_back(n);
  else {
    long long d = n;
    while (d >= n) d = pollard_rho(n, rand() % (n - 1) + 1);
    factorize(n / d, divisor);
    factorize(d, divisor);
  }
}
long long n, x, y, arr[200009];
vector<long long> vec;
vector<long long> lc, gc;
long long dp[(1 << 17) + 2], dp2[(1 << 17) + 2];
long long dp3[(1 << 17) + 2], dp4[(1 << 17) + 2];
int main() {
  scanf("%lld %lld %lld", &n, &x, &y);
  if (y % x) {
    cout << 0 << endl;
    return 0;
  }
  int one = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i]);
    if (arr[i] == 1) one++;
  }
  if (y == 1) {
    cout << n * one << endl;
    return 0;
  }
  factorize(y, vec);
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  int m = vec.size();
  long long temp, cnt;
  for (int i = 0; i < m; i++) {
    temp = y;
    cnt = 0;
    while (temp % vec[i] == 0) {
      cnt++;
      temp /= vec[i];
    }
    lc.push_back(cnt);
    temp = x;
    cnt = 0;
    while (temp % vec[i] == 0) {
      cnt++;
      temp /= vec[i];
    }
    gc.push_back(cnt);
  }
  for (int i = 1; i <= n; i++) {
    if (y % arr[i]) continue;
    int mask = 0;
    for (int j = 0; j < m; j++) {
      temp = arr[i];
      cnt = 0;
      while (temp % vec[j] == 0) {
        cnt++;
        temp /= vec[j];
      }
      if (cnt == lc[j] && lc[j] != gc[j]) mask |= (1 << j);
    }
    dp[mask]++;
  }
  for (int i = 0; i < (1 << m); i++) {
    dp2[i] = dp[i];
    int temp = i;
    while (temp > 0) {
      temp = ((temp - 1) & i);
      dp2[i] += dp[temp];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] % x) continue;
    int mask = 0;
    for (int j = 0; j < m; j++) {
      temp = arr[i];
      cnt = 0;
      while (temp % vec[j] == 0) {
        cnt++;
        temp /= vec[j];
      }
      if (cnt == gc[j]) mask |= (1 << j);
    }
    ans += dp2[mask];
  }
  cout << ans << endl;
  return 0;
}
