#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
inline int read(int &n) {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  return n = x * f;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 1e5 + 7;
int T, n, m;
int a[N];
int main() {
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  bool f = 0;
  for (int i = 1; i < n + 1; i++) {
    int cur = s[i - 1] - '0';
    if (a[cur] > cur) {
      s[i - 1] = a[cur] + '0';
      f = 1;
    } else if (a[i] < cur && f) {
      break;
    }
  }
  cout << s << endl;
  return 0;
}
