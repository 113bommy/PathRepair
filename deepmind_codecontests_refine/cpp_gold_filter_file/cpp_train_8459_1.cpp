#include <bits/stdc++.h>
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long double pi = 3.14159265358979323846;
const long long mod = 1000000007;
using vl = vector<long long>;
namespace number_theory {
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  if (y == 0) return x;
  return gcd(y, x % y);
}
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool prime[15000105];
void sieve(int n) {
  for (long long i = 0; i < n + 1; i++) prime[i] = 1;
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  prime[1] = prime[0] = 0;
}
vl primelist;
bool __primes_generated__ = 0;
void genprimes(int n) {
  __primes_generated__ = 1;
  sieve(n + 1);
  for (long long i = 2; i < n + 1; i++)
    if (prime[i]) primelist.push_back(i);
}
vl factors(long long n) {
  if (!__primes_generated__) {
    cerr << "Call genprimes you dope" << endl;
    exit(1);
  }
  vl facs;
  for (long long i = 0;
       primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
    if (n % primelist[i] == 0) {
      while (n % primelist[i] == 0) {
        n /= primelist[i];
        facs.push_back(primelist[i]);
      }
    }
  }
  if (n > 1) {
    facs.push_back(n);
  }
  sort(facs.begin(), facs.end());
  return facs;
}
vl getdivs(long long n) {
  vl divs;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      divs.push_back(n / i);
    }
  }
  {
    sort(divs.begin(), divs.end());
    divs.erase(unique(divs.begin(), divs.end()), divs.end());
  };
  return divs;
}
}  // namespace number_theory
using namespace number_theory;
long long n, m, k, q, l, r, x, y, z;
const long long template_array_size = 1e6 + 1389;
long long a[template_array_size];
long long b[template_array_size];
long long c[template_array_size];
string second, t;
long long ans = 0;
const long long sqrtn = 100;
vector<long long> pr;
bool alive[100005];
long long expected_val(long long a) {
  long long tot = 0;
  for (long long i = a; i <= n; i += a) {
    tot += alive[i];
  }
  return tot;
}
void kill(long long a) {
  for (long long i = a; i <= n; i += a) {
    alive[i] = 0;
  }
}
long long queryA(long long a) {
  cout << "A " << a << endl;
  cin >> x;
  return x;
}
long long queryB(long long a) {
  cout << "B " << a << endl;
  kill(a);
  cin >> x;
  return x;
}
void solve(int tc = 0) {
  genprimes(2e5);
  cin >> n;
  while (primelist.size() && primelist.back() > n) {
    primelist.pop_back();
  }
  long long stop = min(sqrtn, (long long)primelist.size());
  long long tot = 1 + primelist.size();
  for (long long i = 0; i < n; i++) alive[i] = 1;
  for (long long i = 0; i < stop; i++) {
    queryB(primelist[i]);
    --tot;
  }
  bool maybe_composite = 0;
  for (long long i = 0; i < stop; i++) {
    long long x = queryB(primelist[i]);
    if (x > 0) maybe_composite = 1;
  }
  if (maybe_composite) {
    long long prod = 1;
    for (long long x : primelist) {
      long long cur = 1;
      long long y = x;
      while (y <= n) {
        long long a = expected_val(y);
        long long b = queryA(y);
        if (a != b)
          cur = y;
        else
          break;
        y *= x;
      }
      prod *= cur;
    }
    cout << "C " << prod << endl;
    return;
  }
  long long lpt = 0;
  while (1) {
    long long mid = (lpt + primelist.size() + 1) / 2;
    if (lpt == mid) {
      cout << "C 1\n";
      return;
    }
    for (long long i = lpt; i < mid; i++) {
      queryB(primelist[i]);
    }
    long long a = expected_val(1);
    long long b = queryA(1);
    if (a != b) {
      for (long long i = lpt; i < mid; i++) {
        if (queryA(primelist[i]) == 1) {
          cout << "C " << primelist[i] << '\n';
          return;
        }
      }
    }
    lpt = mid;
  }
}
int main() {
  { ios_base::sync_with_stdio(false); }
  {
    cin.tie(NULL);
    cout.tie(NULL);
  }
  int tc = 1;
  for (int t = 0; t < tc; t++) solve(t);
}
