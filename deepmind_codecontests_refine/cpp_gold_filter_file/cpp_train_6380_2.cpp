#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  vector<bool> prime(100001, true);
  prime[1] = false;
  for (int i = 2; i <= 1000; i++) {
    if (!prime[i] || i * i >= 100001) continue;
    for (int j = i * i; j < 100001; j += i) {
      prime[j] = false;
    }
  }
  while (t--) {
    long long p, q;
    cin >> p >> q;
    if (p % q != 0) {
      cout << p << endl;
      continue;
    }
    bool done = false;
    vector<long long> v;
    for (long long i = 2; i <= min(q, (long long)100001); i++) {
      long long x = q;
      if (prime[i] && x % i == 0) {
        while (x % i == 0) x = x / i;
        v.push_back(i);
      }
    }
    if (v.size() == 0) {
      while (p > 0 && p % q == 0) {
        p = p / q;
      }
      cout << p << endl;
      continue;
    }
    long long minm = INT_MAX;
    minm *= 1000000000;
    long long pp = p;
    for (auto f : v) {
      long long a = 1, b = 1;
      while (q > 0 && q % f == 0) {
        q = q / f;
        a *= f;
      }
      while (a != 1 && p > 0 && p % a == 0) {
        p = p / f;
        b *= f;
      }
      long long curr = b;
      minm = min(minm, curr);
    }
    cout << pp / minm << endl;
  }
  return 0;
}
