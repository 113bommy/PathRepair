#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long double PI = 4 * atan((long double)1);
const long long INF = 1e18;
const long long NINF = -1e18;
long long get_hash(string s) {
  long long N = 1000001;
  long long base[N], A = 11, MD = 1110111110111;
  base[0] = 1;
  for (long long i = (1); i < (N); ++i) base[i] = (base[i - 1] * A) % MD;
  long long hs = 0;
  for (long long i = (0); i < (s.size()); ++i) {
    hs += (s[i] * base[i]);
    hs %= MD;
  }
  return hs;
}
long long power(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res *= a;
    a *= a;
    n /= 2;
  }
  return res;
}
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) long long idx,
               __attribute__((unused)) long long LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long idx, long long LINE_NUM, Head H,
               Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
long long fun(string a) {
  long long n = a.size();
  vector<long long> pi(n + 1);
  pi[0] = 0;
  for (long long i = (1); i < (a.size()); ++i) {
    long long j = pi[i - 1];
    while (j > 0 && a[i] != a[j]) j = pi[j - 1];
    if (a[i] == a[j]) j++;
    pi[i] = j;
  }
  long long u = pi[n - 1];
  if (u == 0) return 0;
  for (long long i = (0); i < (n - 1); ++i) {
    if (pi[i] == u) return u;
  }
  long long v = pi[u - 1];
  if (pi[u - 1] == 0) return 0;
  return v;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  long long x = fun(s);
  if (x <= 0) {
    cout << "Just a legend";
    return 0;
  }
  string a = s.substr(0, x);
  cout << a;
  return 0;
}
