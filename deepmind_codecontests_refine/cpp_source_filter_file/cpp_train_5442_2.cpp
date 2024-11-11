#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long rng(long long lim) {
  uniform_int_distribution<long long> uid(0, lim - 1);
  return uid(rang);
}
long long mod = 1e9 + 7;
long long prime[1000000] = {0};
bool comparison(const pair<long long, long long> &a,
                const pair<long long, long long> &b) {
  return a.second < b.second;
}
void sieve() {
  prime[0] = 1;
  prime[1] = 1;
  for (long long i = 2; i < 1000000; i++) {
    if (prime[i] == 0) {
      for (long long j = i * i; j < 1000000; j += i) {
        prime[j] = 1;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    long long oe = 0, eo = 0, o = 0, e = 0;
    for (long long i = 0; i < n; i++) {
      long long a = s[i] - '0';
      if (a % 2 == 0)
        e++;
      else
        o++;
    }
    long long oo = 0;
    for (long long i = n - 1; i >= 0; i -= 2) {
      long long a = s[i] - '0';
      if (a % 2 == 0)
        oe++;
      else
        oo++;
    }
    long long ee = e - oe;
    eo = o - oo;
    if (n % 2 == 0) {
      if (ee > 0)
        ans = 2;
      else
        ans = 1;
    } else {
      if (oo > 0)
        ans = 1;
      else
        ans = 2;
    }
    cout << ans << "\n";
  }
}
