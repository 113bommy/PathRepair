#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long powmod(long long a, long long b, long long mod) {
  if (b == 0 || a == 1) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2 == 0) {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  }
}
long long prime(long long p) {
  if (p == 1) return -1;
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return i;
  }
  return 1;
}
long long inv(long long a, long long mod) { return powmod(a, mod - 2, mod); }
long long random_modul() {
  uniform_int_distribution<long long> u1(1e9, 2e9);
  long long pepega = u1(rnd);
  while (prime(pepega) != 1) pepega = u1(rnd);
  return pepega;
}
void ifmax(long long &max, long long kek) {
  if (kek > max) max = kek;
  return;
}
void ifmin(long long &min, long long kek) {
  if (kek < min) min = kek;
  return;
}
void solve() {
  long long a, b, m, r;
  cin >> a >> b >> m >> r;
  map<long long, long long> find;
  long long cur = r;
  for (long long i = 1; i <= 1000000; i++) {
    cur = (a * cur + b) % m;
    if (find[cur]) {
      cout << i - find[cur];
      return;
    }
    find[cur] = 1;
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long tututu;
  tututu = 1;
  for (long long qwerty = 0; qwerty < tututu; qwerty++) solve();
  return 0;
}
