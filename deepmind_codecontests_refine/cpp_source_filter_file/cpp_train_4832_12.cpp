#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BIGMOD(T n, T m, T mod) {
  long long int ans = 1;
  long long int k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (ans > mod) ans %= mod;
    }
    k *= k;
    if (k > mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class T>
string toString(T n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
template <class T>
string toBinary(T n) {
  string ret = "";
  while (n) {
    if (n % 2 == 1)
      ret += '1';
    else
      ret += '0';
    n >>= 1;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
void combination(int n, vector<vector<int> > &ret) {
  ret.resize(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    ret[i][0] = ret[i][i] = 1;
    for (int j = 1; j < i; j++) {
      ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
    }
  }
}
int toInt(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
long long int toLInt(string s) {
  long long int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
vector<string> parse(string temp) {
  vector<string> ans;
  ans.clear();
  string s;
  istringstream iss(temp);
  while (iss >> s) ans.push_back(s);
  return ans;
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
inline T power(T b, T p) {
  if (p < 0) return -1;
  if (b <= 0) return -2;
  if (!p) return 1;
  return b * power(b, p - 1);
}
template <class T>
inline int asd(T &ret) {
  char r;
  bool start = false, neg = false;
  ret = 0;
  bool isaNumber = false;
  while (true) {
    r = getchar();
    if (r == EOF) {
      return 0;
    }
    if ((r - '0' < 0 || r - '0' > 9) && r != '-' && !start) {
      continue;
    }
    if ((r - '0' < 0 || r - '0' > 9) && r != '-' && start) {
      break;
    }
    if (start) ret *= 10;
    start = true;
    if (r == '-')
      neg = true;
    else
      ret += r - '0';
  }
  if (neg) ret *= -1;
  return 1;
}
template <class T>
inline int asd(T &ret1, T &ret2) {
  asd(ret1);
  asd(ret2);
  return 2;
}
template <class T>
inline int asd(T &ret1, T &ret2, T &ret3) {
  asd(ret1, ret2);
  asd(ret3);
  return 3;
}
template <class T>
inline int asd(T &ret1, T &ret2, T &ret3, T &ret4) {
  asd(ret1, ret2);
  asd(ret3, ret4);
  return 4;
}
template <class T>
inline void asdasd(T x, char endWith) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  char buf[21], *p = buf;
  do {
    *p++ = '0' + x % 10;
    x /= 10;
  } while (x);
  do {
    putchar(*--p);
  } while (p > buf);
  putchar(endWith);
}
template <class T>
inline void asdasd(T x1, T x2, char separateBy, char endWith) {
  asdasd(x1, separateBy);
  asdasd(x2, endWith);
}
template <class T>
inline void asdasd(T x1, T x2, T x3, char separateBy, char endWith) {
  asdasd(x1, x2, separateBy, separateBy);
  asdasd(x3, endWith);
}
template <class T>
inline void asdasd(T x1, T x2, T x3, T x4, char separateBy, char endWith) {
  asdasd(x1, x2, x3, separateBy, separateBy);
  asdasd(x4, endWith);
}
template <typename value_type>
istream &operator>>(istream &in, vector<value_type> &a) {
  if (!a.size()) {
    size_t n;
    asd(n);
    a.resize(n);
  }
  for (typename vector<value_type>::iterator iter = a.begin(); iter != a.end();
       ++iter)
    asd(*iter);
  return in;
}
template <typename value_type>
ostream &operator<<(ostream &out, const vector<value_type> &a) {
  int sz = a.size();
  for (int i = (int)(0); i <= (int)(sz - 1); i++) asdasd(a[i], i != sz);
  return out;
}
template <typename value_type>
ostream &operator<<(ostream &out, const vector<vector<value_type> > &a) {
  int sza = a.size();
  int szb = a[0].size();
  for (int i = (int)(0); i <= (int)(sza - 1); i++) {
    for (int j = (int)(0); j <= (int)(szb - 1); j++) asdasd(a[i][j], j != sza);
    puts("");
  }
  return out;
}
template <typename value_type>
ostream &operator<<(ostream &out, const set<value_type> &a) {
  for (__typeof(a.begin()) e = a.begin(); e != a.end(); ++e)
    asdasd(*e, e != a.end());
  return out;
}
template <typename key_type, typename value_type>
ostream &operator<<(ostream &in, map<key_type, value_type> &a) {
  for (__typeof(a.begin()) e = a.begin(); e != a.end(); ++e) {
    cout << (*e).first << " -> " << (*e).second << endl;
  }
  return in;
}
template <typename key_type, typename value_type>
istream &operator>>(istream &in, pair<key_type, value_type> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename key_type, typename value_type>
ostream &operator<<(ostream &out, const pair<key_type, value_type> &p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}
vector<int> inverseArray(int n, int m) {
  vector<int> modI(n + 1, 0);
  modI[1] = 1;
  for (int i = 2; i <= n; i++) {
    modI[i] = (-(m / i) * modI[m % i]) % m + m;
  }
  return modI;
}
pair<long long int, pair<long long int, long long int> > extendedEuclid(
    long long int a, long long int b) {
  long long int x = 1, y = 0;
  long long int xLast = 0, yLast = 1;
  long long int q, r, m, n;
  while (a != 0) {
    q = b / a;
    r = b % a;
    m = xLast - q * x;
    n = yLast - q * y;
    xLast = x, yLast = y;
    x = m, y = n;
    b = a, a = r;
  }
  return make_pair(b, make_pair(xLast, yLast));
}
long long int modInverse(long long int a, long long int m) {
  return (extendedEuclid(a, m).second.first + m) % m;
}
int cSum[2000002];
int mn = 10000000, mx;
int main() {
  int n, k, a;
  asd(n, k);
  for (int i = 0; i < n; i++) {
    asd(a);
    cSum[a]++;
    mn = min(mn, a);
    mx = max(mx, a);
  }
  int res = 1;
  for (int i = 1; i < 2000002; i++) cSum[i] += cSum[i - 1];
  if (mn <= k + 1)
    asdasd(mn, '\n');
  else {
    for (int d = mn; d >= k + 1; d--) {
      int p = mx / (d);
      int sum = 0;
      for (int _p = 1; _p <= p; _p++) {
        int l = d * _p;
        int r = l + k;
        sum += (cSum[r] - cSum[l - 1]);
      }
      if (sum == n) {
        res = d;
        break;
      }
    }
  }
  cout << res << endl;
}
