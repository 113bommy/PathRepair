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
const double eps = 1e-8;
const double PI = acos(-1);
const long long mod = 1e9 + 7;
const int inf = 1 << 28;
const int maxn = 1e5 + 5;
void err(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long n, k, mx;
deque<char> s;
map<int, vector<string>> ma;
bool win() {
  bool f = 1;
  for (auto i : s) {
    if (f == 1 && i == 'X') return 0;
    if (f == 0 && i == 'X') return 1;
    f = !f;
  }
  return true;
}
void bt(int i, int rem) {
  if (i == n) {
    if (rem != 0) return;
    long long all = n, cn = 0;
    for (int ss = 0; ss < (int)(n); ++ss) {
      s.push_back(s.front());
      s.pop_front();
      cn += win();
    }
    string st(s.begin(), s.end());
    ma[cn].push_back(st);
    mx = max(mx, cn);
    return;
  }
  s.push_back('.');
  bt(i + 1, rem);
  s.pop_back();
  if (rem > 0) {
    s.push_back('X');
    bt(i + 1, rem - 1);
    s.pop_back();
  }
}
char get(long long i) {
  if (k == 0) return '.';
  if (k == 1) return (i + 1 == n ? 'X' : '.');
  if (i + 1 == n) return 'X';
  long long nn = n, nk = k;
  if (n & 1) {
    nn--;
    nk--;
  }
  long long s1 = nn / 2;
  bool s2 = 0;
  if (s1 < nk) s2 = 1;
  if (!s2) {
    if (i % 2 == 0)
      return '.';
    else {
      if ((nn - i) / 2LL + 1 > nk)
        return '.';
      else
        return 'X';
    }
  } else {
    if (i % 2)
      return 'X';
    else {
      long long rk = nk - nn / 2LL;
      if ((nn - i) / 2LL > rk)
        return '.';
      else
        return 'X';
    }
  }
  return '.';
}
void solve() {
  int q;
  cin >> n >> k >> q;
  string r;
  while (q--) {
    int i;
    cin >> i;
    r += get(i - 1);
  }
  cout << r;
}
int main() {
  int tc = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int tt = 0; tt < (int)(tc); ++tt) {
    solve();
  }
}
