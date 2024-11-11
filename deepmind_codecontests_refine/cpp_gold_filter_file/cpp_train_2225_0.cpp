#include <bits/stdc++.h>
using namespace std;
class BigInt {
 public:
  int sign;
  string s;
  BigInt() : s("") {}
  BigInt(string x) { *this = x; }
  BigInt(int x) { *this = to_string(x); }
  BigInt negative() {
    BigInt x = *this;
    x.sign *= -1;
    return x;
  }
  BigInt normalize(int newSign) {
    for (int a = s.size() - 1; a > 0 && s[a] == '0'; a--)
      s.erase(s.begin() + a);
    sign = (s.size() == 1 && s[0] == '0' ? 1 : newSign);
    return *this;
  }
  void operator=(string x) {
    int newSign = (x[0] == '-' ? -1 : 1);
    s = (newSign == -1 ? x.substr(1) : x);
    reverse(s.begin(), s.end());
    this->normalize(newSign);
  }
  bool operator==(const BigInt& x) const {
    return (s == x.s && sign == x.sign);
  }
  bool operator<(const BigInt& x) const {
    if (sign != x.sign) return sign < x.sign;
    if (s.size() != x.s.size())
      return (sign == 1 ? s.size() < x.s.size() : s.size() > x.s.size());
    for (int a = s.size() - 1; a >= 0; a--)
      if (s[a] != x.s[a]) return (sign == 1 ? s[a] < x.s[a] : s[a] > x.s[a]);
    return false;
  }
  bool operator<=(const BigInt& x) const { return (*this < x || *this == x); }
  bool operator>(const BigInt& x) const {
    return (!(*this < x) && !(*this == x));
  }
  bool operator>=(const BigInt& x) const { return (*this > x || *this == x); }
  BigInt operator+(BigInt x) {
    BigInt curr = *this;
    if (curr.sign != x.sign) return curr - x.negative();
    BigInt res;
    for (int a = 0, carry = 0; a < s.size() || a < x.s.size() || carry; a++) {
      carry += (a < curr.s.size() ? curr.s[a] - '0' : 0) +
               (a < x.s.size() ? x.s[a] - '0' : 0);
      res.s += (carry % 10 + '0');
      carry /= 10;
    }
    return res.normalize(sign);
  }
  BigInt operator-(BigInt x) {
    BigInt curr = *this;
    if (curr.sign != x.sign) return curr + x.negative();
    int realSign = curr.sign;
    curr.sign = x.sign = 1;
    if (curr < x) return ((x - curr).negative()).normalize(-realSign);
    BigInt res;
    for (int a = 0, borrow = 0; a < s.size(); a++) {
      borrow = (curr.s[a] - borrow - (a < x.s.size() ? x.s[a] : '0'));
      res.s += (borrow >= 0 ? borrow + '0' : borrow + '0' + 10);
      borrow = (borrow >= 0 ? 0 : 1);
    }
    return res.normalize(realSign);
  }
  BigInt operator*(BigInt x) {
    BigInt res("0");
    for (int a = 0, b = s[a] - '0'; a < s.size(); a++, b = s[a] - '0') {
      while (b--) res = (res + x);
      x.s.insert(x.s.begin(), '0');
    }
    return res.normalize(sign * x.sign);
  }
  BigInt operator/(BigInt x) {
    if (x.s.size() == 1 && x.s[0] == '0') x.s[0] /= (x.s[0] - '0');
    BigInt temp("0"), res;
    for (int a = 0; a < s.size(); a++) res.s += "0";
    int newSign = sign * x.sign;
    x.sign = 1;
    for (int a = s.size() - 1; a >= 0; a--) {
      temp.s.insert(temp.s.begin(), '0');
      temp = temp + s.substr(a, 1);
      while (!(temp < x)) {
        temp = temp - x;
        res.s[a]++;
      }
    }
    return res.normalize(newSign);
  }
  BigInt operator%(BigInt x) {
    if (x.s.size() == 1 && x.s[0] == '0') x.s[0] /= (x.s[0] - '0');
    BigInt res("0");
    x.sign = 1;
    for (int a = s.size() - 1; a >= 0; a--) {
      res.s.insert(res.s.begin(), '0');
      res = res + s.substr(a, 1);
      while (!(res < x)) res = res - x;
    }
    return res.normalize(sign);
  }
  string toString() const {
    string ret = s;
    reverse(ret.begin(), ret.end());
    return (sign == -1 ? "-" : "") + ret;
  }
  BigInt toBase10(int base) {
    BigInt exp(1), res("0"), BASE(base);
    for (int a = 0; a < s.size(); a++) {
      int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10)
                                           : (s[a] - '0'));
      res = res + (exp * BigInt(curr));
      exp = exp * BASE;
    }
    return res.normalize(sign);
  }
  BigInt toBase10(int base, BigInt mod) {
    BigInt exp(1), res("0"), BASE(base);
    for (int a = 0; a < s.size(); a++) {
      int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10)
                                           : (s[a] - '0'));
      res = (res + ((exp * BigInt(curr) % mod)) % mod);
      exp = ((exp * BASE) % mod);
    }
    return res.normalize(sign);
  }
  string convertToBase(int base) {
    BigInt ZERO(0), BASE(base), x = *this;
    string modes = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (x == ZERO) return "0";
    string res = "";
    while (x > ZERO) {
      BigInt mod = x % BASE;
      x = x - mod;
      if (x > ZERO) x = x / BASE;
      res = modes[stoi(mod.toString())] + res;
    }
    return res;
  }
  BigInt toBase(int base) { return BigInt(this->convertToBase(base)); }
  friend ostream& operator<<(ostream& os, const BigInt& x) {
    os << x.toString();
    return os;
  }
};
const double EPS = (1e-5);
int dcmp(double a, double b) { return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1; }
struct line {
  double a, b, c;
};
long long binpowmod(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int findXOR(int n) {
  switch (n % 4) {
    case 0:
      return n;
    case 1:
      return 1;
    case 2:
      return n + 1;
    case 3:
      return 0;
  }
}
int rangeXOR(int l, int r) { return (findXOR(l - 1) ^ findXOR(r)); }
int getbit(int mask, int bit) { return (mask & (1 << bit)); }
void setbit(int& mask, int bit, int val) {
  if (val)
    mask |= (1 << bit);
  else
    mask &= ~(1 << bit);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 1e5 + 10;
const int M = 500 + 10;
const int MOD = 998244353;
const long long INF = 1e15 + 100;
void solve() {
  int n;
  cin >> n;
  vector<int> cnt(1e5 + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    vector<int> divisors;
    int mx = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        if (i != 1) {
          mx = max(mx, cnt[i] + 1);
          divisors.push_back(i);
        }
        if (x / i != i) {
          mx = max(mx, cnt[x / i] + 1);
          divisors.push_back(x / i);
        }
      }
    }
    for (int i = 0; i < (int)divisors.size(); ++i) cnt[divisors[i]] = mx;
  }
  int ans = *max_element(cnt.begin(), cnt.end());
  cout << max(1, ans) << '\n';
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  while (tc--) {
    solve();
  }
}
