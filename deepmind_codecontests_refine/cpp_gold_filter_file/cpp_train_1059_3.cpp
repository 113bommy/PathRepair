#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long nop = 100;
vector<int> primes(nop, 1);
void sieve() {
  primes[1] = primes[0] = 0;
  for (long long i = 2; i * i <= nop; i++) {
    if (primes[i]) {
      for (long long j = i * i; j <= nop; j += i) {
        primes[j] = 0;
      }
    }
  }
}
long long gcd(long long a, long long b) {
  if (b > a) swap(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
void extgcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = a;
    y = b;
    return;
  }
  extgcd(b % a, a, x, y);
  long long y1 = y, x1 = x;
  x = y1 - (b / a) * x1;
  y = x1;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long bexp(long long num, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) {
      ans *= num;
    }
    num *= num;
    e >>= 1;
  }
  return ans;
}
long long mexp(long long num, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) {
      ans = (ans * num) % mod;
    }
    num *= num;
    num %= mod;
    e >>= 1;
  }
  return ans;
}
long long modinv(long long a) { return bexp(a, mod - 2); }
long long calc(long long v, long long mode) {
  long long sum = 0, cnt = 0, add = 0;
  long long pw = 1;
  for (long long i = 1; i <= 17; i++) {
    if (pw * 10 <= v) {
      cnt = pw * 10 - pw;
      if (mode) {
        sum += add * cnt + ((cnt * (cnt + 1)) / 2) * i;
        add += cnt * i;
      } else {
        sum += cnt * i;
      }
    } else {
      cnt = v - pw + 1;
      if (mode) {
        sum += add * cnt + ((cnt * (cnt + 1)) / 2) * i;
        add += cnt * i;
      } else {
        sum += cnt * i;
      }
      break;
    }
    pw *= 10;
  }
  return sum;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long l = 0, r = 1e9;
    long long b = 0;
    while (l < r) {
      long long mid = ceil((l + r) / 2.0);
      if (calc(mid, 1) < k) {
        l = mid;
      } else
        r = mid - 1;
    }
    b = l;
    k -= calc(b, 1);
    b++;
    l = 1;
    r = b;
    while (l < r) {
      long long mid = (l + r) / 2.0;
      if (calc(mid, 0) < k) {
        l = mid + 1;
      } else
        r = mid;
    }
    string s = to_string(l);
    cout << s[k - calc(l - 1, 0) - 1] << endl;
  }
  return 0;
}
