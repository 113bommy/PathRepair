#include <bits/stdc++.h>
using namespace std;
const unsigned seed =
    std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rnd(seed);
const int MOD = 998244353;
vector<int> primes;
void getPrimes() {
  for (int i = 2; i <= 1000; i++) {
    bool f = true;
    for (auto p : primes) {
      if (i % p == 0) {
        f = false;
        break;
      }
    }
    if (f) primes.push_back(i);
  }
}
void solve() {
  int currentP = 0;
  long long fx = 1;
  long long ans = 1;
  vector<int> canp;
  while (true) {
    long long p = primes[currentP];
    long long cpp = 1;
    if (canp.size() > 0) cpp = canp.back();
    if (p * p * p * fx > 1e9 && canp.size() == 0) {
      cout << "! " << ans * 2 << endl;
      return;
    } else if (ans <= 2 && canp.size() == 0 && p >= 178) {
      cout << "! " << ans * 4 << endl;
      return;
    } else if (canp.size() >= 2 ||
               (canp.size() == 1 &&
                ((p >= 178 && ans == 1) || p * p * p * fx * cpp > 1e9))) {
      vector<long long> pp;
      while (canp.size() > 0 && pp.size() < 2) {
        pp.push_back(canp.back());
        canp.pop_back();
      }
      long long t = 1;
      for (long long p1 : pp) {
        long long t1 = 1;
        while (t1 * p1 <= 1e9) {
          t1 *= p1;
        }
        t *= t1;
      }
      cout << "? " << t << endl;
      long long d;
      cin >> d;
      for (long long p1 : pp) {
        long long a1 = 0;
        while (d % p1 == 0) {
          fx *= p1;
          d /= p1;
          a1++;
        }
        ans *= (a1 + 1);
      }
    } else {
      long long t = 1;
      int startP = currentP;
      while (primes[currentP] < 1e18 / t) {
        int p = primes[currentP++];
        t *= p;
      }
      cout << "? " << t << endl;
      long long d;
      cin >> d;
      for (int i = startP; i < currentP; i++) {
        if (d % primes[i] == 0) canp.push_back(primes[i]);
      }
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  getPrimes();
  int T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  cout.flush();
  return 0;
}
