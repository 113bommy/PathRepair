#include <bits/stdc++.h>
using namespace std;
long long big = 1000000007;
long long mod = 998244353;
double pi = 3.14159265;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
string getbin(unsigned long long x) {
  if (x == 0) return "0";
  string ret = "";
  while (x != 0) {
    ret = (char)('0' + x % 2) + ret;
    x /= 2;
  }
  return ret;
}
unsigned long long getdec(string b) {
  unsigned long long ret = 0;
  for (int i = 0; i < b.size(); i += 1) {
    ret *= 2;
    ret += b[i] - '0';
  }
  return ret;
}
int getp(unsigned long long x) {
  int ret = 0;
  while (x > 1) {
    x /= 2;
    ret += 1;
  }
  return ret;
}
unsigned long long modfact(long long x, long long modulo) {
  if (x == 0)
    return 1;
  else
    return (x * modfact(x - 1, modulo)) % modulo;
}
unsigned long long binexp(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  unsigned long long y = binexp(x, n / 2);
  if (n & 1) {
    return x * y * y;
  } else {
    return y * y;
  }
}
unsigned long long modexp(long long x, long long m, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  unsigned long long y = modexp(x, m, n / 2);
  if (n & 1) {
    return ((x * y % m) * y) % m;
  } else {
    return y * y % m;
  }
}
void boolans(bool b) {
  if (b)
    cout << "YES \n";
  else
    cout << "NO \n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '-' + s;
    int x = -1;
    for (int i = 1; i < n + 1; i += 1) {
      if (s[i] == '0') {
        x = i;
        break;
      }
    }
    int l1, r1, l2, r2;
    if (x < 0) {
      l1 = 1, r1 = n / 2, l2 = (n + 1) / 2 + 1, r2 = n;
    } else {
      if (x <= n / 2) {
        l1 = x, l2 = x + 1;
        r1 = n, r2 = n;
      } else {
        l1 = 1, l2 = 1;
        r1 = x, r2 = x - 1;
      }
    }
    cout << l1 << " " << r1 << " " << l2 << " " << r2 << '\n';
  }
  return 0;
}
