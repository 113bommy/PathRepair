#include <bits/stdc++.h>
using namespace std;
const int INF = 2034567891;
const long long int INF64 = 1234567890123456789ll;
const long long int MN = 100010;
const long long int N = 1000001;
const double eps = 1e-14;
inline bool isPowerOfTwo(int x) { return (x != 0 && (x & (x - 1)) == 0); }
inline int bits_count(int v) {
  v = v - ((v >> 1) & 0x55555555);
  v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
  return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
inline int bits_count(long long int v) {
  int t = v >> 32;
  int p = (v & ((1LL << 32) - 1));
  return bits_count(t) + bits_count(p);
}
unsigned int reverse_bits(register unsigned int x) {
  x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
  x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
  x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
  x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
  return ((x >> 16) | (x << 16));
}
inline int sign(int x) { return x > 0; }
inline string readln() {
  string _s;
  getline(cin, _s);
  return _s;
}
long long int gcd(long long int a, long long int b) {
  return (b == 0 ? a : gcd(b, a % b));
}
long long int lcm(long long int a, long long int b) {
  return (a * (b / gcd(a, b)));
}
long long int max(long long int a, long long int b, long long int c) {
  return max(a, max(b, c));
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}
inline int read() {
  int ret = 0, temp = 1;
  int c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = (ret << 3) + (ret << 1) + c - '0';
    c = getchar();
  }
  return ret;
}
long long int power(long long int x, long long int y) {
  long long int ans = 1;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % 10;
    x = (x * x) % 10;
    y /= 2;
  }
  return ans;
}
long long int row[100005], col[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  long long int n, m;
  cin >> n >> m;
  long long int nr = 0, nc = 0;
  long long int ans = n * n;
  for (int i = 0; i < m; i++) {
    long long int a, b;
    cin >> a >> b;
    long long int fl = 0;
    if (row[a] == 1)
      fl = 1;
    else
      ans -= (n - nc);
    if (col[b] == 1)
      fl = 1;
    else
      ans -= (n - nr);
    if (fl == 0) ans++;
    if (row[a] == 0) {
      row[a] = 1;
      nr++;
    }
    if (col[b] == 0) {
      col[b] = 1;
      nc++;
    }
    cout << ans << " ";
  }
}
