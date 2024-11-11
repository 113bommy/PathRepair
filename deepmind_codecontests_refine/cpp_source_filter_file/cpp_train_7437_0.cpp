#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
long long int INF = 1e18;
long long int power(long long int n, long long int p) {
  long long int ans = 1;
  while (p > 0) {
    p--;
    n *= n;
  }
}
long long int bitc(long long int n, long long int x) { return ((n >> x) & 1); }
long long int __gcd(long long int a, long long int b) {
  return b == 0 ? a : __gcd(b, a % b);
}
long long int sub(long long int a, long long int b, long long int p = MOD) {
  return ((a % p) - (b % p) + p) % p;
}
long long int mult(long long int a, long long int b, long long int p = MOD) {
  return ((a % p) * (b % p)) % p;
}
long long int add(long long int a, long long int b, long long int p = MOD) {
  return (a % p + b % p) % p;
}
long long int fpow(long long int n, long long int k, long long int p = MOD) {
  long long int r = 1;
  while (k > 0) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
    k = k >> 1;
  }
  return r;
}
long long int inv(long long int a, long long int p = MOD) {
  return fpow(a, p - 2, p);
}
long long int fdiv(long long int a, long long int b, long long int p = MOD) {
  long long int yinv = inv(b);
  long long int ans = (a * yinv) % p;
  return ans;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &a) {
  for (auto &item : a) {
    in >> item;
  }
  return in;
}
template <typename T, typename U>
ostream &operator<<(ostream &out, pair<T, U> &a) {
  cout << a.first << " " << a.second;
  return out;
}
template <typename T, typename U>
istream &operator>>(istream &out, pair<T, U> &a) {
  cin >> a.first >> a.second;
  return out;
}
template <typename T, typename U>
ostream &operator<<(ostream &out, map<T, U> &a) {
  for (auto &item : a) {
    out << item << "\n";
  }
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &item : a) {
    out << item << " ";
  }
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &a) {
  for (auto &item : a) {
    out << item << "\n";
  }
  return out;
}
std::vector<bool> is_prime;
std::vector<long long int> primes;
void sieve(long long int n) {
  is_prime.resize(n + 2, true);
  primes.clear();
  long long int p;
  for (p = 2; p * p <= n; p++) {
    if (is_prime[p]) {
      long long int i;
      for (i = p * p; i <= n; i += p) {
        is_prime[i] = false;
      }
    }
  }
  is_prime[0] = is_prime[1] = false;
  long long int i;
  for (i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.emplace_back(i);
    }
  }
}
map<long long int, long long int> prime_factors(long long int n) {
  map<long long int, long long int> s;
  long long int i;
  long long int tc = 0;
  while (n % 2 == 0) {
    tc++;
    n /= 2;
  }
  if (tc > 0) {
    s[2] = tc;
  }
  for (i = 3; i <= sqrt(n); i += 2) {
    tc = 0;
    while (n % i == 0) {
      tc++;
      n /= i;
    }
    if (tc > 0) {
      s[i] = tc;
    }
  }
  if (n > 2) {
    s[n] += 1;
  }
  return s;
}
std::vector<long long int> fact_vec;
void fact_fun(long long int n) {
  fact_vec.resize(n + 10);
  long long int i;
  fact_vec[0] = 1;
  for (i = 1; i <= n + 2; i++) {
    fact_vec[i] = (fact_vec[i - 1] * i) % MOD;
  }
}
int main() {
  long long int i, j;
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    long long int n, k, p;
    cin >> n >> k >> p;
    long long int et = p, ot = k - p;
    std::vector<long long int> ec, oc;
    std::vector<long long int> v(n);
    cin >> v;
    for (auto p : v) {
      if (p & 1) {
        oc.emplace_back(p);
      } else {
        ec.emplace_back(p);
      }
    }
    vector<std::vector<long long int>> ans;
    while (ot - 1 > 0 && !oc.empty()) {
      std::vector<long long int> tp;
      ot--;
      tp.emplace_back(oc.back());
      oc.pop_back();
      ans.emplace_back(tp);
    }
    while (et > 0 && !ec.empty()) {
      std::vector<long long int> tp;
      et--;
      tp.emplace_back(ec.back());
      ec.pop_back();
      ans.emplace_back(tp);
    }
    if (!ec.empty()) {
      if (!ans.empty()) {
        ans.back().insert(ans.back().end(), (ec).begin(), (ec).end());
        ec.clear();
      } else {
        if (et > 0) {
          et--;
          ans.emplace_back(ec);
          ec.clear();
        }
      }
    }
    while (et > 0 && oc.size() > 1) {
      et--;
      std::vector<long long int> tp;
      tp.emplace_back(oc.back());
      oc.pop_back();
      tp.emplace_back(oc.back());
      oc.pop_back();
      ans.emplace_back(tp);
    }
    while (ot > 0 && oc.size() > 0 && oc.size() % 2 != 0) {
      ot--;
      std::vector<long long int> tp;
      while (!oc.empty()) {
        tp.emplace_back(oc.back());
        oc.pop_back();
      }
      while (!ec.empty()) {
        tp.emplace_back(ec.back());
        ec.pop_back();
      }
      ans.emplace_back(tp);
    }
    if (oc.size() % 2 == 0) {
      if (!ans.empty()) {
        ans.back().insert(ans.back().end(), (oc).begin(), (oc).end());
        ans.back().insert(ans.back().end(), (ec).begin(), (ec).end());
        ec.clear();
        oc.clear();
      } else {
        if (ot > 0) {
          ot--;
          ans.emplace_back(oc);
          ans.emplace_back(ec);
          ec.clear();
          oc.clear();
        }
      }
    }
    if (et == 0 && ot == 0 && ec.empty() && oc.empty()) {
      cout << "YES"
           << "\n";
      for (auto p : ans) {
        cout << p.size() << " " << p << "\n";
      }
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
