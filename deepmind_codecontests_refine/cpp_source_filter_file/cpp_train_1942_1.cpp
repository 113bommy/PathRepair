#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
long long ksm(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = (r * a) % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}
void exgcd(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inv(long long a, long long p) {
  long long d, x, y;
  exgcd(a, p, d, x, y);
  return d == 1 ? (x + p) % p : -1;
}
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int maxn = 1e5 + 100;
long long p, k;
vector<long long> v;
int main() {
  cin >> p >> k;
  if (k > p) {
    cout << "2\n";
    cout << "0 1\n";
    return 0;
  }
  long long tmp, res, id = 0;
  while (1) {
    tmp = p / k + (id == 1 && (p % k != 0));
    res = p - tmp * k;
    v.push_back(abs(res));
    p = tmp;
    id ^= 1;
    if (p < k && id == 0) {
      v.push_back(tmp);
      break;
    }
  }
  cout << v.size() << endl;
  for (auto it : v) cout << it << " ";
  return 0;
}
