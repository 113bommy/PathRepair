#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
const long long infl = 1e18 + 4;
const int inf = 1e9 + 5;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void print(long long t) { cout << t; }
void print(int t) { cout << t; }
void print(string t) { cout << t; }
void print(char t) { cout << t; }
void print(long double t) { cout << t; }
void print(double t) { cout << t; }
void print(unsigned long long t) { cout << t; }
template <class T>
void print(vector<T> v) {
  for (T i : v) {
    print(i);
    cout << " ";
  }
  cout << "\n";
}
template <class T>
void print(set<T> v) {
  for (T i : v) {
    print(i);
    cout << " ";
  }
  cout << "\n";
}
template <class T>
void print(multiset<T> v) {
  for (T i : v) {
    print(i);
    cout << " ";
  }
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
};
long long lcm(long long a, long long b) { return (a / (gcd(a, b))) * b; };
long long mod_add(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a + b) % 1000000007) + 1000000007) % 1000000007;
}
long long mod_mul(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a * b) % 1000000007) + 1000000007) % 1000000007;
}
long long mod_sub(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (a - b + 1000000007) % 1000000007;
}
long long ceil_div(long long a, long long b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
bool revsort(long long a, long long b) { return a > b; }
bool perf_sq(long long x) {
  if (x >= 0) {
    long long sr = (long long)sqrtl(x);
    return (sr * sr == x);
  }
  return false;
}
vector<long long> spf(int n) {
  vector<long long> p(n + 1, 0);
  p[1] = 0;
  for (long long i = 2; i <= n; i++) {
    if (p[i] == 0) {
      p[i] = i;
      for (long long j = i * i; j <= n; j = j + i) {
        if (p[j] == 0) p[j] = i;
      }
    }
  }
  return p;
}
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long expo(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b = b >> 1;
  }
  return res;
}
int get(vector<int> &a, int x) {
  return (lower_bound(a.begin(), a.end(), x) - a.begin());
}
void solution() {
  int te;
  te = 1;
  cin >> te;
  while (te--) {
    long long n, k;
    cin >> n >> k;
    if (k == 0) {
      cout << 1 << "\n";
      continue;
    }
    vector<long long> dp(k);
    dp[0] = (expo(2ll, n - 1) + (n % 2 == 1)) % 1000000007;
    if (n % 2 == 0) {
      dp[0]--;
      dp[0] += 1000000007;
      dp[0] %= 1000000007;
    }
    for (int i = 1; i < k; i++) {
      dp[i] = dp[i - 1];
      dp[i] *= dp[0];
      dp[i] %= 1000000007;
    }
    long long ans = dp[k - 1];
    if (n % 2 == 1) {
      cout << ans << "\n";
      continue;
    }
    for (int bit = 0; bit < k; bit++) {
      long long current = 1;
      if (bit != 0) {
        current = dp[bit - 1];
      }
      long long remaining = (k - bit - 1) * n;
      current *= expo(2ll, remaining);
      current %= 1000000007;
      ans += current;
      ans %= 1000000007;
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start1 = high_resolution_clock::now();
  cout << fixed << setprecision(10);
  solution();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
