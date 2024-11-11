#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
ifstream fin("input.txt");
ofstream fout("output.txt");
bool isPrime(int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
  for (int i = 5; i * i <= x; i += 6)
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  return 1;
}
int NumDigits(int x) {
  return (
      x < 10
          ? 1
          : (x < 100
                 ? 2
                 : (x < 1000
                        ? 3
                        : (x < 10000
                               ? 4
                               : (x < 100000
                                      ? 5
                                      : (x < 1000000
                                             ? 6
                                             : (x < 10000000
                                                    ? 7
                                                    : (x < 100000000
                                                           ? 8
                                                           : (x < 1000000000
                                                                  ? 9
                                                                  : 10)))))))));
}
inline void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
}
long long int Pow10[19] = {
    (long long int)1,    (long long int)1e1,  (long long int)1e2,
    (long long int)1e3,  (long long int)1e4,  (long long int)1e5,
    (long long int)1e6,  (long long int)1e7,  (long long int)1e8,
    (long long int)1e9,  (long long int)1e10, (long long int)1e11,
    (long long int)1e12, (long long int)1e13, (long long int)1e14,
    (long long int)1e15, (long long int)1e16, (long long int)1e17,
    (long long int)1e18};
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
long long Mod = 998244353;
template <class T>
struct Fenwick {
  vector<T> V;
  Fenwick(long long n) : V(n) {}
  void add(size_t i, T x) {
    for (; i < V.size(); i |= i + 1) V[i] += x;
  }
  T sum(long long i) {
    T r = T();
    for (--i; i >= 0; i = (i & (i + 1)) - 1) r += V[i];
    return r;
  }
  T sum(long long l, long long r) { return sum(r) - sum(l); }
};
long long mul(long long a, long long b, long long c = 1, long long d = 1,
              long long e = 1, long long g = 1) {
  a %= Mod;
  b %= Mod;
  c %= Mod;
  d %= Mod;
  e %= Mod;
  g %= Mod;
  return (a * b % Mod * c % Mod * d % Mod * e % Mod * g % Mod);
}
long long Pow(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long x = Pow(a, b / 2);
    return mul(x, x);
  } else {
    long long x = Pow(a, b / 2);
    return mul(a, x, x);
  }
}
long long inf = 1e18;
struct My {
  long long a = inf;
  long long b = inf;
  long long solved = 0;
  long long fee = 0;
};
struct comp {
  bool operator()(My const& a, My const& b) const {}
};
struct Tree {
  long long n = 1;
  vector<long long> t;
  Tree(long long nn) {
    while (n < nn) n *= 2;
    t.assign(n * 2, 0);
  }
  Tree(vector<long long>& A) {
    while (n < A.size()) n *= 2;
    t.assign(n * 2, 0);
    for (long long i = 0; i < (A.size()); ++i) {
      t[i + n] = A[i];
    }
    for (long long i = A.size() - 1; i >= 1; --i) {
      t[i] = t[i + i] + t[i + i + 1];
    }
  }
  long long get(long long i) {
    long long res = t[i += n];
    for (i /= 2; i; i /= 2) {
      res += t[i];
    }
    return res;
  }
  void set(long long l, long long r, long long x) {
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) t[l++] += x;
      ;
      if (~r & 1) t[r--] += x;
    }
  }
};
long long gcdex(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcdex(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long mypow(long long a, long long b = Mod - 2, long long k = Mod) {
  if (b == 0) return 1;
  long long tmp = mypow(a, b / 2, k);
  if ((b % 2) == 1)
    return mul(tmp, tmp, a);
  else
    return mul(tmp, tmp);
}
long long mypow2(long long a, long long m = Mod) {
  long long x, y;
  long long g = gcdex(a, m, x, y);
  x = (x % m + m) % m;
  return x;
}
int32_t main() {
  boostIO();
  long long T;
  cin >> T;
  for (long long t = 0; t < T; ++t) {
    long long n;
    cin >> n;
    vector<long long> A(n);
    long long Sum = 0;
    long long Xor = 0;
    for (long long i = 0; i < (n); ++i) {
      cin >> A[i];
      Sum += A[i];
      Xor ^= A[i];
    }
    vector<long long> ans;
    bitset<64> B = Xor;
    long long Add = 0;
    for (long long i = 1; i < 55; ++i) {
      if (B[i] == 0) {
        Add += (1LL << i);
      }
    }
    if (B[0] == 1) Add += 1;
    ans.push_back(Add);
    Sum += Add;
    Xor ^= Add;
    long long dif = Xor * 2 - Sum;
    ans.push_back(dif / 2);
    ans.push_back(dif / 2);
    Sum += dif / 2;
    Sum += dif / 2;
    Xor ^= dif / 2;
    Xor ^= dif / 2;
    if (Xor * 2 != Sum) {
      cerr << "ERROR" << '\n';
      return 0;
    }
    cerr << "ans = ";
    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
  return 0;
}
