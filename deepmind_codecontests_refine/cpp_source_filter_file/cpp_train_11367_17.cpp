#include <bits/stdc++.h>
using namespace std;
long long modulo(long long base, long long exponent, long long modulus);
long long choose(long long n, long long k);
long long inverse(long long a, long long m);
void build();
long long ncr(long long n, long long r);
const int nax = 1e6 + 10;
const int LG = log2(nax) + 1;
vector<long long> fact(nax);
long long dowork(long long x) {
  long long prefix = 0;
  long long i = 1;
  long long ans = 0;
  while (1) {
    long long high = min(x, (long long)(pow(10, i) - 1));
    long long low = pow(10, i - 1);
    long long num = high - low + 1;
    ans += prefix * (num) + i * (num * (num + 1)) / 2;
    prefix = num;
    if (high == x) break;
    i++;
  }
  return ans;
}
long long dig(long long x) {
  long long ans = 0;
  while (x) {
    x /= 10;
    ans++;
  }
  return ans;
}
bool check(long long x, long long k) {
  if (dowork(x) >= k) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;
    long long low = 0, high = 1000000000;
    long long ans = 0;
    while (low <= high) {
      long long mid = (low + high) / 2;
      if (check(mid, k)) {
        low = mid + 1;
      } else {
        ans = mid;
        high = mid - 1;
      }
    }
    k -= dowork(ans - 1);
    long long d = dig(ans);
    int i;
    for (i = 1; i <= d; i++) {
      long long high = pow(10, i) - 1;
      long long low = pow(10, i - 1);
      long long num = high - low + 1;
      if (i * num >= k) break;
      k -= i * num;
    }
    long long one = (k - 1) / i;
    long long two = (k - 1) % i;
    long long three = pow(10, i - 1) + one;
    long long j = i - 1;
    while (three) {
      long long f = three % 10;
      if (j == two) {
        cout << f << '\n';
        break;
      }
      three /= 10;
      j--;
    }
  }
  return 0;
}
long long ncr(long long n, long long r) {
  if (r > n || r < 0 || n < 0) return 0;
  long long ans = fact[n];
  long long temp = (fact[n - r] * fact[r]) % 1000000007;
  ans = (ans * inverse(temp, 1000000007)) % 1000000007;
  return ans;
}
void build() {
  fact[0] = 1;
  for (long long i = 1; i < nax; i++) fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long modulo(long long base, long long exponent, long long modulus) {
  if (modulus == 1) return 0;
  long long result = 1;
  base = base % modulus;
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % modulus;
    }
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}
long long choose(long long n, long long k) {
  if (k == 0) return 1;
  return (n * choose(n - 1, k - 1)) / k;
}
void EE(long long a, long long b, long long &co1, long long &co2) {
  if (a % b == 0) {
    co1 = 0;
    co2 = 1;
    return;
  }
  EE(b, a % b, co1, co2);
  long long temp = co1;
  co1 = co2;
  co2 = temp - co2 * (a / b);
}
long long inverse(long long a, long long m) {
  long long x, y;
  EE(a, m, x, y);
  if (x < 0) x += m;
  return x;
}
