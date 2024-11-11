#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
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
  int f = 0;
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
template <class A>
void read(vector<A>& v);
template <class A, size_t S>
void read(array<A, S>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t S>
void read(array<A, S>& x) {
  for (auto& a : x) read(a);
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const int MAXN = 2e5 + 6;
long long mod = 1e9 + 7;
long long dx[] = {0, -1, 1, 0, -1, -1, 1, 1};
long long dy[] = {1, 0, 0, -1, 1, -1, -1, 1};
long long n, l, k;
vector<long double> p;
vector<long long> bgs;
long double dp[203][203][203];
long double go(long long i, long long wins, long long bags) {
  ;
  if (i == n) {
    return (wins <= bags && wins >= l);
  }
  long double& ans = dp[i][wins][bags];
  if (ans != -1.0) return ans;
  ans = (1.0 - p[i]) * go(i + 1, wins, bags);
  if (bgs[i] == -1) {
    ans += (p[i] * go(i + 1, wins + 1, bags));
  } else {
    ans += (p[i] * go(i + 1, wins + 1, min(201ll, 1 + bags + bgs[i])));
  }
  return ans = ans;
}
void solve() {
  read(n, l, k);
  p.resize(n);
  for (long long i = int(0); i < int(n); i++) {
    long long x;
    cin >> x;
    p[i] = x / 100.0;
  }
  bgs.resize(n);
  read(bgs);
  for (long long i = int(0); i < int(202); i++) {
    for (long long j = int(0); j < int(202); j++)
      for (long long k = int(0); k < int(202); k++) dp[i][j][k] = -1.0;
  }
  long double ans = go(0, 0, k);
  cout << ans << "\n";
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
