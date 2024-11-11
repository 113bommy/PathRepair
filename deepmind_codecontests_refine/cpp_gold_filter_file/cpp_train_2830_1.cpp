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
  string s, t;
  cin >> s >> t;
  long long tota = 0, totb = 0, sa = 0, ta = 0;
  for (long long i = 0; i < n; i++) {
    tota += (s[i] == 'a');
    totb += (s[i] == 'b');
    tota += (t[i] == 'a');
    totb += (t[i] == 'b');
    sa += (s[i] == 'a');
    ta += (t[i] == 'a');
  }
  if (tota % 2) {
    cout << -1 << endl;
    return 0;
  }
  tota /= 2;
  totb /= 2;
  vector<long long> crca, crcb;
  for (long long i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      if (s[i] == 'a')
        crca.push_back(i);
      else
        crcb.push_back(i);
    }
  }
  long long ans = 0;
  vector<vector<pair<long long, long long> > > change(
      (crca.size() + crcb.size()) / 2);
  for (long long i = 0; i < crca.size() / 2; i++) {
    long long a = crca[2 * i], b = crca[2 * i + 1];
    ans++;
    change[i].push_back({a, b});
  }
  for (long long i = 0; i < crcb.size() / 2; i++) {
    long long a = crcb[2 * i], b = crcb[2 * i + 1];
    ans++;
    change[(crca.size() / 2) + i].push_back({a, b});
  }
  if (crca.size() % 2) {
    long long a = crca[crca.size() - 1], b = crcb[crcb.size() - 1];
    ans += 2;
    change[change.size() - 1].push_back({a, a});
    change[change.size() - 1].push_back({a, b});
  }
  cout << ans << endl;
  for (long long i = 0; i < change.size(); i++) {
    for (auto p : change[i]) {
      cout << p.first + 1 << " " << p.second + 1 << endl;
    }
  }
  return 0;
}
