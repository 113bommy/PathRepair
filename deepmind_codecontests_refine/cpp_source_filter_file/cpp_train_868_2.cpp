#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const long double PI = acos(-1.0);
const double eps = 1e-12;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int MAXPRIMES = 3163;
const int MAXSIZESTR = 110;
const int BASE = 31;
const long long MOD = 1000000073;
const long long MAXN = 100010;
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T abs(T x) {
  return x < 0 ? -x : x;
}
template <class T>
string toStr(T n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
inline long long toLL(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
inline bool isUpperCase(char c) { return c >= 'A' && c <= 'Z'; }
inline bool isLowerCase(char c) { return c >= 'a' && c <= 'z'; }
inline char toLowerCase(char c) { return (isUpperCase(c)) ? (c + 32) : c; }
inline char toUpperCase(char c) { return (isLowerCase(c)) ? (c - 32) : c; }
inline bool isLetter(char c) {
  return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}
inline bool isDigit(char c) { return c >= '0' && c <= '9'; }
inline long long ppow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    b >>= 1;
  }
  return ret;
}
inline long long ppow(long long a, long long b, long long md) {
  long long ret = 1;
  a %= md;
  while (b) {
    if (b & 1) ret = (ret * a) % md;
    a = a * a;
    a %= md;
    b >>= 1;
  }
  return ret % md;
}
int crossOper(double x0, double y0, double x1, double y1, double x2,
              double y2) {
  double t = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
  if (fabs(t) <= eps) return 0;
  return (t < 0) ? -1 : 1;
}
bool isIntersect(double x1, double y1, double x2, double y2, double x3,
                 double y3, double x4, double y4) {
  return crossOper(x1, y1, x2, y2, x3, y3) * crossOper(x1, y1, x2, y2, x4, y4) <
             0 &&
         crossOper(x3, y3, x4, y4, x1, y1) * crossOper(x3, y3, x4, y4, x2, y2) <
             0;
}
double distance(double x1, double y1, double x2, double y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
long long vect(long long x1, long long x2, long long y1, long long y2) {
  return x1 * y2 - x2 * y1;
}
long long scal(long long x1, long long x2, long long y1, long long y2) {
  return x1 * x2 + y1 * y2;
}
int LineAndDot(double x1, double y1, double x2, double y2, double x3,
               double y3) {
  double res = vect(x3 - x1, x2 - x1, y3 - y1, y2 - y1);
  if (res == 0) return 0;
  if (res < 0) return 1;
  if (res > 0) return -1;
}
double sqrTriangle(double x1, double y1, double x2, double y2, double x3,
                   double y3) {
  double m3m1X = x3 - x1;
  double m3m1Y = y3 - y1;
  double m3m2X = x3 - x2;
  double m3m2Y = y3 - y2;
  double res = abs(0.5 * vect(m3m1X, m3m1Y, m3m2X, m3m2Y));
  return res;
}
vector<int> genPrimes() {
  bool visit[MAXPRIMES + 10] = {false};
  vector<int> primes;
  for (int i = 2; i <= MAXPRIMES; i++)
    if (!visit[i]) {
      primes.push_back(i);
      for (int j = i * 2; j <= MAXPRIMES; j += i) visit[j] = 1;
    }
  return primes;
}
vector<pair<int, int> > factorization(int n) {
  int d = 2;
  vector<pair<int, int> > p;
  while (1) {
    if (n % d == 0) {
      if ((int)p.size() > 0 && p[(int)p.size() - 1].first == d)
        p[(int)p.size() - 1].second++;
      else
        p.push_back(make_pair(d, 1));
      n /= d;
    } else
      d++;
    if (d > sqrt(n + 0.)) break;
    if (n == 1) break;
  }
  if (n != 1)
    if ((int)p.size() > 0 && p[(int)p.size() - 1].first == n)
      p[(int)p.size() - 1].second++;
    else
      p.push_back(make_pair(n, 1));
  return p;
}
inline string fromDec(long long num, int base) {
  string s = "";
  string d = "!0123456789ABCDEF";
  do {
    s = d[(num % base) + 1] + s;
    num /= base;
  } while (num != 0);
  return s;
}
inline long long toDec(string num, int base) {
  string d = "!0123456789ABCDEF";
  long long m = 0;
  int start = 0;
  int pos = 0;
  while (num[start] == '0') start++;
  for (int i = start; i < (int)num.size(); i++) {
    for (int j = 0; j < (int)d.size(); j++)
      if (d[j] == num[i]) {
        pos = j;
        break;
      }
    m = m * base + pos - 1;
  }
  return m;
}
void generateHash(string s, unsigned long long _hash[],
                  unsigned long long _power[]) {
  for (size_t i = 0; i < (int)s.size(); i++) {
    _hash[i] = (s[i] - 'a' + 1) * _power[i];
    if (i) _hash[i] += _hash[i - 1];
    _hash[i] %= MOD;
  }
}
void generatePower(string s, unsigned long long _power[]) {
  _power[0] = 1;
  for (size_t i = 1; i < (int)s.size(); i++)
    _power[i] = (_power[i - 1] * BASE) % MOD;
}
inline unsigned long long CountHash(int i, int len, int szS,
                                    unsigned long long _hash[],
                                    unsigned long long _power[]) {
  unsigned long long cur_hash = _hash[i + len - 1];
  if (i) cur_hash -= _hash[i - 1];
  if (cur_hash < 0) cur_hash += MOD;
  cur_hash *= _power[szS - i - 1];
  cur_hash %= MOD;
  return cur_hash;
}
int n, m;
char s[10010];
int a[5000000];
int monthDay[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dday[10010];
int main() {
  int cnt = 0;
  scanf("%d%d\n", &n, &m);
  int year, month, day, hour, minute, second;
  dday[1] = monthDay[0] * 24 * 60 * 60;
  for (int i = 2; i < 13; i++)
    dday[i] += dday[i - 1] + monthDay[i] * 24 * 60 * 60;
  int kk = 0;
  while (gets(s)) {
    assert(sscanf(s, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute,
                  &second) == 6);
    long long res = 0;
    res += dday[month - 1] + (day - 1) * 24 * 60 * 60 + hour * 60 * 60 +
           minute * 60 + second;
    a[kk++] = res;
    if (kk - m >= 0 && res - a[kk - m] < n) {
      printf("2012-%02d-%02d %02d:%02d:%02d", month, day, hour, minute, second);
      return 0;
    }
  }
  printf("-1");
  return 0;
}
