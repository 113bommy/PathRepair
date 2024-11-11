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
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  long long v[100] = {0};
  for (long long i = (0); i < (64); ++i) {
    for (long long j = (i + 1); j < (64); ++j) {
      long long p = i & j;
      v[p]++;
    }
  }
  map<char, long long> mpa;
  for (long long i = (0); i < (10); ++i) {
    char x = '0' + i;
    mpa[x] = i;
  }
  for (long long i = (0); i < (26); ++i) {
    char x = 'A' + i;
    mpa[x] = 10 + i;
  }
  for (long long i = (0); i < (26); ++i) {
    char x = 'a' + i;
    mpa[x] = 36 + i;
  }
  mpa['-'] = 62;
  mpa['_'] = 63;
  long long ans = 1;
  for (long long i = (0); i < (s.size()); ++i)
    ans = (ans % MOD * (2 * v[mpa[s[i]]] + 1) % MOD) % MOD;
  cout << ans % MOD;
  return 0;
}
