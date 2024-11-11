#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
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
struct _ {
  ios_base::Init i;
  _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); }
} _;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
long long mod_pow(long long a, long long b, long long p) {
  long long res = 1;
  a %= p;
  while (b > 0) {
    if ((b & 1) == 1) res = ((res % p) * (a % p)) % p;
    a = ((a % p) * (a % p)) % p;
    b >>= 1;
  }
  return res;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k > n)
    cout << mod_pow(m, n, 1000000007);
  else if (k == n)
    cout << mod_pow(m, (n - 1) / 2, 1000000007);
  else if (k > 1 and k % 2 == 0)
    cout << m;
  else if (k > 1 and k % 2 == 1)
    cout << m * m;
  else if (k == 1)
    cout << mod_pow(m, n, 1000000007);
  return 0;
}
