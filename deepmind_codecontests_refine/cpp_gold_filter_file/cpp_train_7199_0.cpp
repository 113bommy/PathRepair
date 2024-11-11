#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long nop = 100;
vector<int> primes(nop, 1);
long long cnt = 0;
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
bool isVowel(char ch) {
  ch = tolower(ch);
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
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
    num = (num * num) % mod;
    e >>= 1;
  }
  return ans % mod;
}
long long modinv(long long a) { return bexp(a, mod - 2); }
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  if (n == 1) {
    if (a[0] == 1)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  long long st = 1, start = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == 1) start = 1;
    if (b[i] == st) {
      st++;
    } else if (start) {
      st = 1;
      start = 0;
      break;
    } else
      continue;
  }
  vector<long long> pl(n + 1, -1);
  for (int i = 0; i < n; i++) {
    pl[b[i]] = i + 1;
  }
  long long mov = 0;
  for (long long i = st; i <= n; i++) {
    if (pl[i] <= mov) {
      mov++;
    } else {
      if (st > 1) {
        mov += n + 2;
      } else
        mov = 1 + pl[i];
    }
  }
  cout << mov << endl;
  return 0;
}
