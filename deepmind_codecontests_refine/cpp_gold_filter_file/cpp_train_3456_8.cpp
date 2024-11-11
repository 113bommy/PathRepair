#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
std::pair<int, int> DR[] = {{-1, 0}, {0, 1},   {1, 0}, {0, -1},
                            {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
using namespace std;
const long long mod = 1e9 + 7;
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
  return ans % mod;
}
long long modinv(long long a) { return mexp(a, mod - 2); }
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, long long> > a(n);
    vector<long long> count(n + 1, 0), pref(n + 2, 0);
    for (long long i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
      count[a[i].first]++;
    }
    partial_sum(count.begin(), count.end(), pref.begin() + 1);
    multiset<long long> price;
    sort(a.begin(), a.end(), greater<pair<long long, long long> >());
    long long prev = -1, cnt = 0, ans = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i].first == prev) {
        price.insert(a[i].second);
        prev = a[i].first;
        continue;
      } else if (prev != -1) {
        if (pref[prev] + cnt < prev) {
          long long no = prev - pref[prev] - cnt;
          for (long long j = 0; j < no; j++) {
            cnt++;
            ans += *price.begin();
            price.erase(price.begin());
          }
        }
      }
      price.insert(a[i].second);
      prev = a[i].first;
    }
    if (prev != -1 && pref[prev] + cnt < prev) {
      long long no = prev - pref[prev] - cnt;
      for (long long j = 0; j < no; j++) {
        cnt++;
        ans += *price.begin();
        price.erase(price.begin());
      }
    }
    cout << ans << endl;
  }
  return 0;
}
