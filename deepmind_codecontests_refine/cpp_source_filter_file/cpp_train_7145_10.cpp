#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  while (b != 0) swap(b, a %= b);
  return a;
}
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  long long f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <class T>
bool selfmax(T& a, const T& b) {
  long long to_ret = 0;
  if (a < b) to_ret = 1;
  a = max(a, b);
  return to_ret;
}
template <class T>
bool selfmin(T& a, const T& b) {
  long long to_ret = 0;
  if (a > b) to_ret = 1;
  a = min(a, b);
  return to_ret;
}
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A>
void read(vector<pair<A, A> >& x) {
  for (auto& a : x) read(a.first, a.second);
}
template <typename... T>
void read(vector<long long>& a) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) cin >> a[i];
}
template <class A>
void print(vector<A>& a) {
  for (auto& x : a) cout << x << " ";
  cout << endl;
}
long long prod(long long a, long long b, long long m) {
  long long res = 0;
  while (b) {
    if (b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}
long long power(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b & 1) res = prod(res, a, m);
    a = prod(a, a, m);
    b >>= 1;
  }
  return res;
}
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
const long long MOD = 1e9 + 7;
const long long INF = 1000000000;
const long long BIGINF = 1e12;
void solve() {
  long long n, l;
  read(n, l);
  vector<long long> c(n);
  read(c);
  vector<long long> bestprice = c;
  for (;;) {
    long long flag = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (j < i) {
          long long diff = i - j;
          flag |= selfmin(bestprice[i], (long long)pow(2, diff) * (c[j]));
        } else {
          flag |= selfmin(bestprice[i], c[j]);
        }
      }
    }
    if (!flag) break;
  }
  long long nn = l;
  long long ans = 0;
  vector<long long> pos;
  for (long long i = n - 1; i >= 0; i--) {
    long long powe = 1 << i;
    if (nn >= powe) {
      long long temp = nn / powe;
      ans += bestprice[i] * temp;
      nn -= temp * powe;
    } else if (nn > 0) {
      long long idx = (long long)log2(nn);
      long long mini = LLONG_MAX;
      for (long long i = idx + 1; i < n; i++) {
        mini = min(mini, bestprice[i]);
      }
      pos.push_back(ans + mini);
    }
  }
  pos.push_back(ans);
  cout << *min_element((pos).begin(), (pos).end()) << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long tt = 0; tt < t; tt++) {
    solve();
  }
}
