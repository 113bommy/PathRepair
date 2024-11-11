#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long ans = 0;
map<long long, long long> p, dp;
long long func(long long x) {
  if (dp.count(x)) return dp[x];
  unordered_set<long long> pom;
  for (long long i = 1; i <= 30; i++) {
    long long from = (x >> i) | (x & (1 << (i - 1)) - 1);
    if (from != x) pom.insert(func(from));
  }
  long long meks = 0;
  while (pom.count(meks)) meks++;
  return dp[x] = meks;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    for (long long j = 2; j * j <= a; j++) {
      if (a % j == 0) {
        long long cnt = 0;
        while (a % j == 0) a /= j, cnt++;
        p[j] |= (1 << (cnt - 1));
      }
    }
    if (a > 1) p[a] |= 1;
  }
  for (auto it : p) ans ^= func(it.second);
  if (ans)
    cout << "Mojtaba";
  else
    cout << "Arpa";
  return 0;
}
