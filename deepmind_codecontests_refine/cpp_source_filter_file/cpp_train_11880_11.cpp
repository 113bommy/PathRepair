#include <bits/stdc++.h>
using namespace std;
class BigInteger {
 public:
  BigInteger() { _data.push_back(0); }
  BigInteger(long long x) {
    while (x) {
      _data.push_back(x % _base);
      x /= _base;
    }
    if (_data.empty()) _data.push_back(0);
  }
  BigInteger(unsigned long long x) {
    while (x) {
      _data.push_back(x % _base);
      x /= _base;
    }
    if (_data.empty()) _data.push_back(0);
  }
  BigInteger(int x) : BigInteger((long long)x) {}
  BigInteger(unsigned int x) : BigInteger((unsigned long long)x) {}
  BigInteger(short x) : BigInteger((long long)x) {}
  BigInteger(unsigned short x) : BigInteger((unsigned long long)x) {}
  BigInteger(char x) : BigInteger((long long)x) {}
  BigInteger(unsigned char x) : BigInteger((unsigned long long)x) {}
  BigInteger(std::string &s) {
    for (int i = (int)s.size(); i > 0; i -= 9)
      if (i < 9)
        _data.push_back(atoi(s.substr(0, i).data()));
      else
        _data.push_back(atoi(s.substr(i - 9, 9).data()));
    while (_data.size() > 1 && _data.back() == 0) _data.pop_back();
  }
  BigInteger(const char *s) {
    std::string d = s;
    for (int i = (int)d.size(); i > 0; i -= 9)
      if (i < 9)
        _data.push_back(atoi(d.substr(0, i).data()));
      else
        _data.push_back(atoi(d.substr(i - 9, 9).data()));
    while (_data.size() > 1 && _data.back() == 0) _data.pop_back();
  }
  BigInteger(const BigInteger &b) {
    _data.resize(b._data.size());
    std::copy(b._data.begin(), b._data.end(), _data.begin());
  }
  void ToString(char *s) const {
    sprintf(s, "%d", _data.empty() ? 0 : _data.back());
    for (int i = (int)_data.size() - 2; i >= 0; i--)
      sprintf(s, "%s%09d", s, _data[i]);
  }
  std::string ToString() const {
    char *buff = (char *)malloc(20);
    sprintf(buff, "%d", _data.empty() ? 0 : _data.back());
    std::string res = buff;
    for (int i = (int)_data.size() - 2; i >= 0; i--) {
      sprintf(buff, "%09d", _data[i]);
      res += buff;
    }
    free(buff);
    return res;
  }
  friend const BigInteger operator+(BigInteger &i);
  friend const BigInteger &operator++(BigInteger &i);
  friend const BigInteger &operator--(BigInteger &i);
  friend const BigInteger operator++(BigInteger &i, int);
  friend const BigInteger operator--(BigInteger &i, int);
  friend const BigInteger operator+(const BigInteger &c, const BigInteger &b);
  friend const BigInteger operator-(const BigInteger &c, const BigInteger &b);
  friend const BigInteger operator*(const BigInteger &a, const BigInteger &b);
  friend const BigInteger operator/(const BigInteger &a, const BigInteger &b);
  friend const BigInteger operator%(const BigInteger &a, const BigInteger &b);
  friend BigInteger &operator+=(BigInteger &a, const BigInteger &b);
  friend BigInteger &operator-=(BigInteger &a, const BigInteger &b);
  friend BigInteger &operator*=(BigInteger &a, const BigInteger &b);
  friend BigInteger &operator/=(BigInteger &a, const BigInteger &b);
  friend BigInteger &operator%=(BigInteger &a, const BigInteger &b);
  friend bool operator==(const BigInteger &a, const BigInteger &b);
  friend bool operator<=(const BigInteger &a, const BigInteger &b);
  friend bool operator>=(const BigInteger &a, const BigInteger &b);
  friend bool operator<(const BigInteger &a, const BigInteger &b);
  friend bool operator>(const BigInteger &a, const BigInteger &b);
  friend bool operator!=(const BigInteger &a, const BigInteger &b);
  friend std::istream &operator>>(std::istream &is, BigInteger &i) {
    std::string s;
    is >> s;
    i = BigInteger(s);
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const BigInteger &i) {
    os << i.ToString();
    return os;
  }

 private:
  static const int _base = 1000 * 1000 * 1000;
  std::vector<int> _data;
  int _cmp(const BigInteger &a, const BigInteger &b) const {
    if (a._data.size() > b._data.size()) return 1;
    if (a._data.size() < b._data.size()) return -1;
    for (int i = (int)a._data.size() - 1; i >= 0; i--) {
      if (a._data[i] > b._data[i]) return 1;
      if (a._data[i] < b._data[i]) return -1;
    }
    return 0;
  }
  BigInteger _div_short(const BigInteger &c, int b, int &mod) const {
    mod = 0;
    BigInteger a = c;
    for (int i = (int)a._data.size() - 1; i >= 0; i--) {
      long long cur = a._data[i] + mod * 1ll * BigInteger::_base;
      a._data[i] = int(cur / b);
      mod = int(cur % b);
    }
    while (a._data.size() > 1 && a._data.back() == 0) a._data.pop_back();
    return a;
  }
  bool _is_zero() const { return _data.size() == 1 && _data[0] == 0; }
};
const BigInteger operator+(const BigInteger &i) { return BigInteger(i); }
const BigInteger &operator++(BigInteger &i) {
  int j = 0;
  i._data[0]++;
  while (i._data[j] >= BigInteger::_base) {
    if (j == (int)i._data.size() - 1)
      i._data.push_back(1);
    else
      i._data[j + 1]++;
    i._data[j] -= BigInteger::_base;
    j++;
  }
  return i;
}
const BigInteger operator++(BigInteger &i, int) {
  BigInteger old = BigInteger(i);
  int j = 0;
  i._data[0]++;
  while (i._data[j] >= BigInteger::_base) {
    if (j == (int)i._data.size() - 1)
      i._data.push_back(1);
    else
      i._data[j + 1]++;
    i._data[j] -= BigInteger::_base;
    j++;
  }
  return old;
}
const BigInteger &operator--(BigInteger &i) {
  if (!i._is_zero()) i = i - 1;
  return i;
}
const BigInteger operator--(BigInteger &i, int) {
  BigInteger old = BigInteger(i);
  if (!i._is_zero()) i = i - 1;
  return old;
}
const BigInteger operator+(const BigInteger &c, const BigInteger &b) {
  BigInteger a = c;
  int carry = 0;
  for (size_t i = 0; i < std::max(a._data.size(), b._data.size()) || carry;
       i++) {
    if (i == a._data.size()) a._data.push_back(0);
    a._data[i] += carry + (i < b._data.size() ? b._data[i] : 0);
    carry = a._data[i] >= BigInteger::_base;
    if (carry) a._data[i] -= BigInteger::_base;
  }
  return a;
}
const BigInteger operator-(const BigInteger &c, const BigInteger &b) {
  if (c < b)
    throw std::invalid_argument("a - b, a must b greater or equal zero");
  BigInteger a = c;
  int carry = 0;
  for (size_t i = 0; i < b._data.size() || carry; i++) {
    a._data[i] -= carry + (i < b._data.size() ? b._data[i] : 0);
    carry = a._data[i] < 0;
    if (carry) a._data[i] += BigInteger::_base;
  }
  while (a._data.size() > 1 && a._data.back() == 0) a._data.pop_back();
  return a;
}
const BigInteger operator*(const BigInteger &a, const BigInteger &b) {
  BigInteger c;
  c._data.resize(a._data.size() + b._data.size());
  for (size_t i = 0; i < a._data.size(); i++)
    for (int j = 0, carry = 0; j < (int)b._data.size() || carry; j++) {
      long long cur =
          c._data[i + j] +
          a._data[i] * 1ll * (j < (int)b._data.size() ? b._data[j] : 0) + carry;
      c._data[i + j] = int(cur % BigInteger::_base);
      carry = int(cur / BigInteger::_base);
    }
  while (c._data.size() > 1 && c._data.back() == 0) c._data.pop_back();
  return c;
}
const BigInteger operator/(const BigInteger &a, const BigInteger &b) {
  if (b._is_zero()) throw std::invalid_argument("division by zero");
  BigInteger l = 0, r = a + 1, m;
  int t;
  while (r - l > 1) {
    m = a._div_short(r + l, 2, t);
    if (b * m <= a)
      l = m;
    else
      r = m;
  }
  return l;
}
const BigInteger operator%(const BigInteger &a, const BigInteger &b) {
  if (b._is_zero()) throw std::invalid_argument("division by zero");
  BigInteger l = 0, r = a + 1, m;
  int t;
  while (r - l > 1) {
    m = a._div_short(r + l, 2, t);
    if (b * m <= a)
      l = m;
    else
      r = m;
  }
  return a - b * l;
}
BigInteger &operator+=(BigInteger &a, const BigInteger &b) {
  int carry = 0;
  for (size_t i = 0; i < std::max(a._data.size(), b._data.size()) || carry;
       i++) {
    if (i == a._data.size()) a._data.push_back(0);
    a._data[i] += carry + (i < b._data.size() ? b._data[i] : 0);
    carry = a._data[i] >= BigInteger::_base;
    if (carry) a._data[i] -= BigInteger::_base;
  }
  return a;
}
BigInteger &operator-=(BigInteger &a, const BigInteger &b) {
  int carry = 0;
  for (size_t i = 0; i < b._data.size() || carry; i++) {
    a._data[i] -= carry + (i < b._data.size() ? b._data[i] : 0);
    carry = a._data[i] < 0;
    if (carry) a._data[i] += BigInteger::_base;
  }
  while (a._data.size() > 1 && a._data.back() == 0) a._data.pop_back();
  return a;
}
BigInteger &operator*=(BigInteger &a, const BigInteger &b) {
  a = a * b;
  return a;
}
BigInteger &operator/=(BigInteger &a, const BigInteger &b) {
  a = a / b;
  return a;
}
BigInteger &operator%=(BigInteger &a, const BigInteger &b) {
  a = a % b;
  return a;
}
bool operator==(const BigInteger &a, const BigInteger &b) {
  return a._cmp(a, b) == 0;
}
bool operator<=(const BigInteger &a, const BigInteger &b) {
  return a._cmp(a, b) <= 0;
}
bool operator>=(const BigInteger &a, const BigInteger &b) {
  return a._cmp(a, b) >= 0;
}
bool operator<(const BigInteger &a, const BigInteger &b) {
  return a._cmp(a, b) < 0;
}
bool operator>(const BigInteger &a, const BigInteger &b) {
  return a._cmp(a, b) > 0;
}
bool operator!=(const BigInteger &a, const BigInteger &b) {
  return a._cmp(a, b) != 0;
}
BigInteger binpow(BigInteger a, BigInteger n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return binpow(a, n - 1) * a;
  else {
    BigInteger b = binpow(a, n / 2);
    return b * b;
  }
}
BigInteger gcd(BigInteger a, BigInteger b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
BigInteger sum(BigInteger a) {
  BigInteger o;
  while (a != -1) {
    o += a;
    a--;
  }
  return o;
}
BigInteger pows(BigInteger x, BigInteger y) {
  BigInteger q = 1;
  for (BigInteger i = 0; i < y; i++) q *= x;
  return q;
}
BigInteger abss(BigInteger x) {
  if (x < 0) x -= x;
  return x;
}
int main() {
  int n;
  cin >> n;
  int *mas = new int[n];
  vector<int> a;
  for (int i = 0; i < n; i++) cin >> mas[i];
  int x = n - 2;
  int j = 1;
  bool y = true;
  a.push_back(n);
  for (int i = 0; i < n; i++) {
    a.push_back(mas[x]);
    x = mas[x] - 2;
    if (a[a.size() - 1] == 1) {
      break;
    }
  }
  for (int i = a.size() - 1; i > -1; i--) cout << a[i];
  return 0;
}
