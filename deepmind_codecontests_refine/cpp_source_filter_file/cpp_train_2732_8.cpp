#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const int LIM = 801, MOD = 1e9 + 7;
const long double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool prime[LIM];
vector<int> primes;
void precompute() {
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i < LIM; ++i) {
    if (prime[i] == 0) {
      primes.push_back(i);
      int j = 2;
      while (i * j < LIM) {
        prime[i * j] = 1;
        j++;
      }
    }
  }
}
long long fastpow(long long a, long long p) {
  if (p == 0) return 1;
  long long z = fastpow(a, p / 2);
  z = z * z;
  if (p % 2) z = a * z;
  return z;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    primes.clear();
    precompute();
    long long mul = 1;
    vector<long long> query;
    map<long long, long long> div;
    for (auto& r : primes) {
      if (mul < 1e18 / r) {
        mul *= r;
      } else {
        query.push_back(mul);
        mul = 1;
      }
    }
    long long done = 0;
    if (mul > 1) query.push_back(mul);
    vector<int> toc;
    for (auto& r : query) {
      cout << "? " << r << endl;
      long long x;
      cin >> x;
      for (auto& k : primes) {
        if (x % k == 0) div[k] = 1;
        if (x % k == 0) toc.push_back(k);
      }
      done += 1;
    }
    vector<long long> check;
    long long chk = 1;
    shuffle(toc.begin(), toc.end(), rng);
    vector<long long> tc;
    for (auto& r : toc) {
      if (chk < 1e18 / (r * r)) {
        chk *= r * r;
        continue;
      }
      if (done < 21) {
        done += 1;
        cout << "? " << chk << endl;
        long long x;
        cin >> x;
        for (auto& k : primes) {
          long long tot = 0;
          while (x % k == 0) {
            tot++;
            x /= k;
          }
          if (tot == 2) tc.push_back(k);
          div[k] = max(div[k], tot);
        }
      }
      chk = 1;
    }
    if (chk > 1 && done < 21) {
      done += 1;
      cout << "? " << chk << endl;
      long long x;
      cin >> x;
      for (auto& k : primes) {
        long long tot = 0;
        while (x % k == 0) {
          tot++;
          x /= k;
        }
        if (tot == 2) tc.push_back(k);
        div[k] = max(div[k], tot);
      }
    }
    long long x = 1;
    for (auto& r : tc) {
      if (x == 1) {
        while (x < 1e9 / r) x *= r;
        continue;
      }
      while (x < 1e18 / r) x *= r;
      if (done < 22) {
        done += 1;
        cout << "? " << x << endl;
        long long in;
        cin >> in;
        for (auto& k : primes) {
          if (in % k == 0) {
            long long tot = 0;
            while (in % k == 0) {
              tot++;
              in /= k;
            }
            div[k] = max(div[k], tot);
          }
        }
      }
    }
    if (x > 1 && done < 22) {
      cout << "? " << x << endl;
      long long in;
      cin >> in;
      for (auto& k : primes) {
        if (in % k == 0) {
          long long tot = 0;
          while (in % k == 0) {
            tot++;
            in /= k;
          }
          div[k] = max(div[k], tot);
        }
      }
    }
    long long ans = 1;
    for (auto& r : div) {
      ans *= (r.second + 1);
    }
    cout << "! " << max(ans * 2 - 1, ans + 7) << endl;
  }
  return 0;
}
