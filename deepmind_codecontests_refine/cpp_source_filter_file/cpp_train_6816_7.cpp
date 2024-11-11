#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
  int f = 0;
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
long long MOD = 134151353125325623LL;
long long _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;
vector<long long> power;
long long get_hash(string &s) {
  long long x = 0;
  for (int i = 0; i < s.length(); i++)
    x = (x + power[i] * (s[i] - 'a' + 1)) % MOD;
  return x;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  power.resize(1000000);
  power[0] = 1;
  for (int i = 1; i < 100000; i++) power[i] = power[i - 1] * 4 % MOD;
  set<long long> st;
  while (n--) {
    string s;
    cin >> s;
    st.insert(get_hash(s));
  }
  while (m--) {
    string s;
    cin >> s;
    long long x = get_hash(s);
    bool yes = false;
    for (int i = 0; i < s.length(); i++)
      for (char c = 'a'; c <= 'c'; c++) {
        if (c == s[i]) continue;
        long long y = x + power[i] * (c - s[i]);
        y = (y % MOD + MOD) % MOD;
        if (st.count(y)) yes = true;
      }
    printf(yes ? "YES\n" : "NO\n");
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
