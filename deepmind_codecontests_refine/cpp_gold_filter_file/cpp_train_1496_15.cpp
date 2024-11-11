#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:36777216")
template <class T>
inline void RD(T &);
template <class T>
inline void OT(const T &);
template <class T>
inline T &_RD(T &x) {
  RD(x);
  return x;
}
inline int RD() {
  int x;
  return _RD(x);
}
inline void RF(double &x) { scanf("%lf", &x); }
inline double _RF(double &x) {
  scanf("%lf", &x);
  return x;
}
inline double RF() {
  double x;
  return _RF(x);
}
inline void RC(char &c) { scanf(" %c", &c); }
inline char _RC(char &c) {
  scanf(" %c", &c);
  return c;
}
inline char RC() {
  char c;
  return _RC(c);
}
inline void RS(char *s) { scanf("%s", s); }
template <class T0, class T1>
inline void RD(T0 &x0, T1 &x1) {
  RD(x0), RD(x1);
}
template <class T0, class T1, class T2>
inline void RD(T0 &x0, T1 &x1, T2 &x2) {
  RD(x0), RD(x1), RD(x2);
}
template <class T0, class T1, class T2, class T3>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3) {
  RD(x0), RD(x1), RD(x2), RD(x3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);
}
template <class T0, class T1>
inline void OT(T0 &x0, T1 &x1) {
  OT(x0), OT(x1);
}
template <class T0, class T1, class T2>
inline void OT(T0 &x0, T1 &x1, T2 &x2) {
  OT(x0), OT(x1), OT(x2);
}
template <class T0, class T1, class T2, class T3>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3) {
  OT(x0), OT(x1), OT(x2), OT(x3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);
}
template <class T>
inline void RST(T &A) {
  memset(A, 0, sizeof(A));
}
template <class T0, class T1>
inline void RST(T0 &A0, T1 &A1) {
  RST(A0), RST(A1);
}
template <class T0, class T1, class T2>
inline void RST(T0 &A0, T1 &A1, T2 &A2) {
  RST(A0), RST(A1), RST(A2);
}
template <class T0, class T1, class T2, class T3>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3) {
  RST(A0), RST(A1), RST(A2), RST(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4) {
  RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5) {
  RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6) {
  RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);
}
template <class T>
inline void CLR(priority_queue<T, vector<T>, less<T> > &Q) {
  while (!Q.empty()) Q.pop();
}
template <class T>
inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q) {
  while (!Q.empty()) Q.pop();
}
template <class T>
inline void CLR(T &A) {
  A.clear();
}
template <class T0, class T1>
inline void CLR(T0 &A0, T1 &A1) {
  CLR(A0), CLR(A1);
}
template <class T0, class T1, class T2>
inline void CLR(T0 &A0, T1 &A1, T2 &A2) {
  CLR(A0), CLR(A1), CLR(A2);
}
template <class T0, class T1, class T2, class T3>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);
}
template <class T>
inline void CLR(T &A, int n) {
  for (int i = 0; i < int(n); ++i) CLR(A[i]);
}
template <class T>
inline void FLC(T &A, int x) {
  memset(A, x, sizeof(A));
}
template <class T0, class T1>
inline void FLC(T0 &A0, T1 &A1, int x) {
  FLC(A0, x), FLC(A1, x);
}
template <class T0, class T1, class T2>
inline void FLC(T0 &A0, T1 &A1, T2 &A2) {
  FLC(A0), FLC(A1), FLC(A2);
}
template <class T0, class T1, class T2, class T3>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5), FLC(A6);
}
template <class T>
inline void SRT(T &A) {
  sort(A.begin(), A.end());
}
template <class T, class C>
inline void SRT(T &A, C B) {
  sort(A.begin(), A.end(), B);
}
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long INF_64 = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const double OO = 1e15;
const double PI = acos(-1.0);
template <class T>
inline void checkMin(T &a, const T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkMax(T &a, const T b) {
  if (b > a) a = b;
}
template <class T, class C>
inline void checkMin(T &a, const T b, C c) {
  if (c(b, a)) a = b;
}
template <class T, class C>
inline void checkMax(T &a, const T b, C c) {
  if (c(a, b)) a = b;
}
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T min(T a, T b, T c, T d) {
  return min(min(a, b), min(c, d));
}
template <class T>
inline T max(T a, T b, T c, T d) {
  return max(min(a, b), max(c, d));
}
template <class T, class C>
inline T min_cp(T a, T b, C cp) {
  return min(a, b, cp);
}
template <class T, class C>
inline T min_cp(T a, T b, T c, C cp) {
  return min_cp(min_cp(a, b, cp), c, cp);
}
template <class T, class C>
inline T min_cp(T a, T b, T c, T d, C cp) {
  return min_cp(min_cp(a, b, cp), min_cp(c, d, cp), cp);
}
template <class T, class C>
inline T max_cp(T a, T b, C cp) {
  return max(a, b, cp);
}
template <class T, class C>
inline T max_cp(T a, T b, T c, C cp) {
  return max_cp(max_cp(a, b, cp), c, cp);
}
template <class T, class C>
inline T max_cp(T a, T b, T c, T d, C cp) {
  return max_cp(max_cp(a, b, cp), max_cp(c, d, cp), cp);
}
template <class T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline T cub(T a) {
  return a * a * a;
}
int Ceil(int x, int y) { return (x - 1) / y + 1; }
inline bool _1(int x, int i) { return x & 1 << i; }
inline bool _1(long long x, int i) { return x & 1LL << i; }
inline long long _1(int i) { return 1LL << i; }
inline long long _U(int i) { return _1(i) - 1; };
template <class T>
inline T low_bit(T x) {
  return x & -x;
}
template <class T>
inline T high_bit(T x) {
  T p = low_bit(x);
  while (p != x) x -= p, p = low_bit(x);
  return p;
}
template <class T>
inline T cover_bit(T x) {
  T p = 1;
  while (p < x) p <<= 1;
  return p;
}
inline int count_bits(int x) {
  x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
  x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
  x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
  x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
  x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
  return x;
}
inline int count_bits(long long x) {
  x = (x & 0x5555555555555555LL) + ((x & 0xaaaaaaaaaaaaaaaaLL) >> 1);
  x = (x & 0x3333333333333333LL) + ((x & 0xccccccccccccccccLL) >> 2);
  x = (x & 0x0f0f0f0f0f0f0f0fLL) + ((x & 0xf0f0f0f0f0f0f0f0LL) >> 4);
  x = (x & 0x00ff00ff00ff00ffLL) + ((x & 0xff00ff00ff00ff00LL) >> 8);
  x = (x & 0x0000ffff0000ffffLL) + ((x & 0xffff0000ffff0000LL) >> 16);
  x = (x & 0x00000000ffffffffLL) + ((x & 0xffffffff00000000LL) >> 32);
  return x;
}
int reverse_bits(int x) {
  x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
  x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
  x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
  x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
  x = ((x >> 16) & 0x0000ffff) | ((x << 16) & 0xffff0000);
  return x;
}
long long reverse_bits(long long x) {
  x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
  x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
  x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
  x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
  x = ((x >> 16) & 0x0000ffff0000ffffLL) | ((x << 16) & 0xffff0000ffff0000LL);
  x = ((x >> 32) & 0x00000000ffffffffLL) | ((x << 32) & 0xffffffff00000000LL);
  return x;
}
using namespace std;
class bignum {
  friend istream &operator>>(istream &, bignum &);
  friend ostream &operator<<(ostream &, const bignum &);
  friend bignum operator+(const bignum &, const bignum &);
  friend bignum operator-(const bignum &, const bignum &);
  friend bignum operator*(const bignum &, const bignum &);
  friend bignum operator/(const bignum &, const bignum &);
  friend bignum operator%(const bignum &, const bignum &);
  friend bignum operator+(const bignum &, const int &);
  friend bignum operator-(const bignum &, const int &);
  friend bignum operator*(const bignum &, const int &);
  friend bignum operator/(const bignum &, const int &);
  friend bignum operator%(const bignum &, const int &);
  friend bool operator==(const bignum &, const bignum &);
  friend bool operator!=(const bignum &, const bignum &);
  friend bool operator<(const bignum &, const bignum &);
  friend bool operator>(const bignum &, const bignum &);
  friend bool operator<=(const bignum &, const bignum &);
  friend bool operator>=(const bignum &, const bignum &);
  friend bool operator==(const bignum &, const int &);
  friend bool operator!=(const bignum &, const int &);
  friend bool operator<(const bignum &, const int &);
  friend bool operator>(const bignum &, const int &);
  friend bool operator<=(const bignum &, const int &);
  friend bool operator>=(const bignum &, const int &);
  friend int do_comp(const bignum &, const int &);
  friend int do_comp(const bignum &, const bignum &);
  friend void divide(const bignum &, const bignum &, bignum &, bignum &);
  friend bignum pow(bignum, int);

 public:
  inline bignum(){};
  inline bignum(int s) {
    while (s != 0) {
      data.push_back(s % 100000000);
      s /= 100000000;
    }
    if (data.empty()) data.push_back(0);
  }
  inline bignum(long long s) {
    while (s != 0) {
      data.push_back(int(s % 100000000));
      s /= 100000000;
    }
    if (data.empty()) data.push_back(0);
  }
  inline bignum(string s) {
    int t, i;
    data.clear();
    for (i = int(s.size()) - 8; i > 0; i -= 8) {
      istringstream(s.substr(i, 8)) >> t;
      data.push_back(t);
    }
    istringstream(s.substr(0, i + 8)) >> t;
    data.push_back(t);
  }
  void operator=(const int);
  void operator=(const string);
  void operator=(const bignum);
  bignum &operator+=(const bignum &);
  bignum &operator-=(const bignum &);
  bignum &operator*=(const bignum &);
  bignum &operator/=(const bignum &);
  bignum &operator%=(const bignum &);
  bignum &operator+=(const int &);
  bignum &operator-=(const int &);
  bignum &operator*=(const int &);
  bignum &operator/=(const int &);
  bignum &operator%=(const int &);
  bignum &operator%=(const long long &);
  bool undefined();
  int do_try(const int &);
  int do_try(const bignum &);
  void do_trim();
  list<int> data;
  void add(const int a) {
    list<int>::iterator it = data.end();
    it--;
    if ((*it) < 10)
      (*it) = a;
    else if ((*it) < 100)
      (*it) = (*it) % 10 + 10 * a;
    else if ((*it) < 1000)
      (*it) = (*it) % 100 + 100 * a;
    else if ((*it) < 10000)
      (*it) = (*it) % 1000 + 1000 * a;
    else if ((*it) < 100000)
      (*it) = (*it) % 10000 + 10000 * a;
    else if ((*it) < 1000000)
      (*it) = (*it) % 100000 + 100000 * a;
    else if ((*it) < 10000000)
      (*it) = (*it) % 1000000 + 1000000 * a;
    else if ((*it) < 100000000)
      (*it) = (*it) % 10000000 + 10000000 * a;
  }
  void clear() { data.clear(); }
  long long t() {
    if (data.size() == 1)
      return *data.begin();
    else {
      list<int>::iterator it = data.begin(), jt = data.begin();
      ++it;
      return (long long)(*it) * 100000000 + (*jt);
    }
  }
  int size() {
    list<int>::iterator it;
    int res = 0;
    for (it = data.begin(); it != data.end(); it++) res += 8;
    it--;
    if (*it >= 10000) {
      if ((*it) >= 1000000) {
        if (*it >= 10000000)
          ;
        else
          res--;
      } else {
        if ((*it) >= 100000)
          res -= 2;
        else
          res -= 3;
      }
    } else if ((*it) >= 100) {
      if (*it >= 1000)
        res -= 4;
      else
        res -= 5;
    } else {
      if ((*it) >= 10)
        res -= 6;
      else
        res -= 7;
    }
    return res;
  }
  void do_reserve(int a) {
    if (a <= 0) return;
    list<int>::iterator it;
    for (it = data.begin(); it != data.end() && a > 0; it++) a -= 8;
    if (it == data.end() && a >= 0) return;
    a += 8, it--;
    int f = 1;
    for (int i = 0; i < a; i++) f *= 10;
    (*it) %= f;
    data.erase(++it, data.end());
    do_trim();
  }
  void output() {
    list<int>::reverse_iterator i = data.rbegin();
    printf("%d", *i);
    for (i++; i != data.rend(); i++) printf("%08d", *i);
  }
};
inline void bignum::operator=(const bignum a) {
  data.clear();
  for (list<int>::const_iterator i = a.data.begin(); i != a.data.end(); i++) {
    data.push_back(*i);
  }
}
inline void bignum::operator=(const string a) { (*this) = bignum(a); }
inline void bignum::operator=(const int a) { (*this) = bignum(a); }
inline istream &operator>>(istream &input, bignum &a) {
  string s;
  int t, i;
  input >> s;
  a.data.clear();
  for (i = int(s.size()) - 8; i > 0; i -= 8) {
    istringstream(s.substr(i, 8)) >> t;
    a.data.push_back(t);
  }
  istringstream(s.substr(0, i + 8)) >> t;
  a.data.push_back(t);
  return input;
}
inline ostream &operator<<(ostream &output, const bignum &a) {
  list<int>::const_reverse_iterator i = a.data.rbegin();
  output << *i;
  for (i++; i != a.data.rend(); i++) {
    if (*i >= 10000) {
      if (*i >= 1000000) {
        if (*i >= 10000000)
          cout << *i;
        else
          cout << 0 << *i;
      } else {
        if (*i >= 100000)
          cout << "00" << *i;
        else
          cout << "000" << *i;
      }
    } else {
      if (*i >= 100) {
        if (*i >= 1000)
          cout << "0000" << *i;
        else
          cout << "00000" << *i;
      } else {
        if (*i >= 10)
          cout << "000000" << *i;
        else
          cout << "0000000" << *i;
      }
    }
  }
  return output;
}
inline bool bignum::undefined() { return data.empty(); }
inline int do_comp(const bignum &a, const bignum &b) {
  if (a.data.size() < b.data.size()) return -1;
  if (a.data.size() > b.data.size()) return 1;
  list<int>::const_reverse_iterator i;
  list<int>::const_reverse_iterator j;
  for (i = a.data.rbegin(), j = b.data.rbegin(); j != b.data.rend(); i++, j++) {
    if (*i < *j) return -1;
    if (*i > *j) return 1;
  }
  return 0;
}
inline int do_comp(const bignum &a, const int &b) {
  return do_comp(a, bignum(b));
}
inline bool operator==(const bignum &a, const bignum &b) {
  return do_comp(a, b) == 0;
}
inline bool operator!=(const bignum &a, const bignum &b) {
  return do_comp(a, b) != 0;
}
inline bool operator<(const bignum &a, const bignum &b) {
  return do_comp(a, b) == -1;
}
inline bool operator>(const bignum &a, const bignum &b) {
  return do_comp(a, b) == 1;
}
inline bool operator<=(const bignum &a, const bignum &b) {
  return do_comp(a, b) != 1;
}
inline bool operator>=(const bignum &a, const bignum &b) {
  return do_comp(a, b) != -1;
}
inline bool operator==(const bignum &a, const int &b) {
  return do_comp(a, b) == 0;
}
inline bool operator!=(const bignum &a, const int &b) {
  return do_comp(a, b) != 0;
}
inline bool operator<(const bignum &a, const int &b) {
  return do_comp(a, b) == -1;
}
inline bool operator>(const bignum &a, const int &b) {
  return do_comp(a, b) == 1;
}
inline bool operator<=(const bignum &a, const int &b) {
  return do_comp(a, b) != 1;
}
inline bool operator>=(const bignum &a, const int &b) {
  return do_comp(a, b) != -1;
}
inline void bignum::do_trim() {
  while (data.size() > 1 && data.back() == 0) data.pop_back();
}
inline bignum &bignum::operator+=(const bignum &a) {
  list<int>::iterator i;
  list<int>::const_iterator j;
  int t = 0;
  for (i = data.begin(), j = a.data.begin();
       i != data.end() && j != a.data.end(); i++, j++) {
    *i += *j + t;
    t = *i / 100000000;
    *i %= 100000000;
  }
  while (i != data.end()) {
    *i += t;
    t = *i / 100000000;
    *i %= 100000000;
    i++;
  }
  while (j != a.data.end()) {
    data.push_back(t + *j);
    t = data.back() / 100000000;
    data.back() %= 100000000;
    j++;
  }
  if (t != 0) data.push_back(t);
  return *this;
}
inline bignum &bignum::operator-=(const bignum &a) {
  list<int>::iterator i;
  list<int>::const_iterator j;
  int t = 0;
  for (i = data.begin(), j = a.data.begin(); j != a.data.end(); i++, j++) {
    *i -= t + *j;
    if (*i >= 0)
      t = 0;
    else
      *i += 100000000, t = 1;
  }
  while (i != data.end()) {
    *i -= t;
    if (*i >= 0)
      t = 0;
    else
      *i += 100000000, t = 1;
    i++;
  }
  (*this).do_trim();
  return *this;
}
inline bignum &bignum::operator+=(const int &a) { return (*this) += bignum(a); }
inline bignum &bignum::operator-=(const int &a) { return (*this) -= bignum(a); }
inline bignum operator+(const bignum &a, const bignum &b) {
  list<int>::const_iterator i, j;
  bignum c;
  int t = 0;
  for (i = a.data.begin(), j = b.data.begin();
       i != a.data.end() && j != b.data.end(); i++, j++) {
    c.data.push_back(t + *i + *j);
    t = c.data.back() / 100000000;
    c.data.back() %= 100000000;
  }
  while (i != a.data.end()) {
    c.data.push_back(t + *i);
    t = c.data.back() / 100000000;
    c.data.back() %= 100000000;
    i++;
  }
  while (j != b.data.end()) {
    c.data.push_back(t + *j);
    t = c.data.back() / 100000000;
    c.data.back() %= 100000000;
    j++;
  }
  if (t != 0) c.data.push_back(t);
  return c;
}
inline bignum operator-(const bignum &a, const bignum &b) {
  list<int>::const_iterator i, j;
  bignum c;
  int t = 0;
  for (i = a.data.begin(), j = b.data.begin(); j != b.data.end(); i++, j++) {
    t = *i - t;
    if (t >= *j)
      c.data.push_back(t - *j), t = 0;
    else
      c.data.push_back(t + 100000000 - *j), t = 1;
  }
  while (i != a.data.end()) {
    t = *i - t;
    if (t >= 0)
      c.data.push_back(t), t = 0;
    else
      c.data.push_back(t + 100000000), t = 1;
    i++;
  }
  c.do_trim();
  return c;
}
inline bignum operator*(const bignum &a, const bignum &b) {
  list<int>::const_iterator i, j;
  list<int>::iterator k, kk;
  bignum c;
  long long t = 0;
  for (int i = 0; i < a.data.size() + b.data.size(); i++) c.data.push_back(0);
  for (i = a.data.begin(), k = c.data.begin(); i != a.data.end(); i++, k++) {
    for (j = b.data.begin(), kk = k; j != b.data.end(); j++, kk++) {
      t += (long long)(*i) * (*j) + (*kk);
      *kk = int(t % 100000000);
      t /= 100000000;
    }
    *kk += t;
    t = 0;
  }
  c.do_trim();
  return c;
}
inline int bignum::do_try(const bignum &a) {
  int l = 1, r = 99999999, m, t;
  while (l + 2 < r) {
    m = (l + r) / 2;
    t = do_comp(*this, a * bignum(m));
    if (t == 0) return m;
    if (t < 0)
      r = m - 1;
    else
      l = m;
  }
  while (do_comp(*this, a * bignum(r)) < 0) r--;
  return r;
}
inline void divide(const bignum &a, const bignum &b, bignum &d, bignum &r) {
  list<int>::const_reverse_iterator i = a.data.rbegin();
  int t;
  d = bignum(0);
  r = bignum(0);
  do {
    while (r < b && i != a.data.rend()) {
      d.data.push_front(0);
      r.data.push_front(*i);
      r.do_trim();
      i++;
    }
    if (r >= b) {
      t = r.do_try(b);
      d.data.front() = t;
      r -= (b * bignum(t));
    }
  } while (i != a.data.rend());
  d.do_trim();
}
inline bignum operator/(const bignum &a, const bignum &b) {
  bignum d, r;
  divide(a, b, d, r);
  return d;
}
inline bignum operator%(const bignum &a, const bignum &b) {
  bignum d, r;
  divide(a, b, d, r);
  return r;
}
inline bignum operator+(const bignum &a, const int &b) { return a + bignum(b); }
inline bignum operator-(const bignum &a, const int &b) { return a - bignum(b); }
inline bignum operator*(const bignum &a, const int &b) { return a * bignum(b); }
inline bignum operator/(const bignum &a, const int &b) { return a / bignum(b); }
inline bignum &bignum::operator*=(const bignum &a) {
  (*this) = (*this) * a;
  return *this;
}
inline bignum &bignum::operator/=(const bignum &a) {
  (*this) = (*this) / a;
  return *this;
}
inline bignum &bignum::operator%=(const bignum &a) {
  (*this) = (*this) % a;
  return *this;
}
inline bignum &bignum::operator*=(const int &a) { return (*this) *= bignum(a); }
inline bignum &bignum::operator/=(const int &a) { return (*this) /= bignum(a); }
inline bignum &bignum::operator%=(const long long &b) {
  return (*this) %= bignum(b);
}
inline bignum pow(bignum a, int b) {
  bignum c(1);
  while (b != 0) {
    if (b & 1) c *= a;
    a = a * a;
    b >>= 1;
  }
  return c;
}
inline int rand32() {
  return (bool(rand() & 1) << 30) | (rand() << 15) + rand();
}
inline int random32(int l, int r) { return rand32() % (r - l + 1) + l; }
inline int random(int l, int r) { return rand() % (r - l + 1) + l; }
int dice() { return rand() % 6; }
bool coin() { return rand() % 2; }
template <class T>
inline void RD(T &x) {
  char c;
  for (c = getchar(); c < '0'; c = getchar())
    ;
  x = c - '0';
  for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
}
template <class T>
inline void OT(const T &x) {
  printf("%d\n", x);
}
const int N = 200;
int mp[N][N];
int n, m;
vector<int> edge[N];
int ans[N];
void init(int x) {
  ans[x] = -1;
  for (int i = 0; i < edge[x].size(); ++i) {
    if (ans[edge[x][i]] != -1) init(edge[x][i]);
  }
}
int gao(int x) {
  int res = ans[x];
  for (int i = 0; i < edge[x].size(); ++i) {
    int go = edge[x][i];
    if (ans[go] != -1 && (mp[x][go] ^ ans[x] ^ ans[go]) != 1) return n + 1;
    if (ans[go] != -1) continue;
    ans[go] = mp[x][go] ^ ans[x] ^ 1;
    int ret = gao(go);
    res = min(n + 1, res + ret);
  }
  return res;
}
void solve() {
  memset(mp, -1, sizeof(mp));
  for (int i = 1; i <= n; ++i) edge[i].clear();
  int mm = m;
  while (mm--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (mp[a][b] != -1 && mp[a][b] != c) {
      printf("Impossible\n");
      return;
    }
    mp[a][b] = mp[b][a] = c;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  memset(ans, -1, sizeof(ans));
  int ANS = 0;
  for (int i = 1; i <= n; ++i) {
    if (ans[i] != -1) continue;
    init(i);
    ans[i] = 0;
    int res1 = gao(i);
    init(i);
    ans[i] = 1;
    int res2 = gao(i);
    if (res1 > res2)
      ANS += res2;
    else {
      ANS += res1;
      init(i);
      ans[i] = 0;
      gao(i);
    }
  }
  if (ANS > n)
    printf("Impossible\n");
  else {
    printf("%d\n", ANS);
    bool f = false;
    for (int i = 1; i <= n; ++i) {
      if (ans[i] != 1) continue;
      if (!f)
        f = true;
      else
        printf(" ");
      printf("%d", i);
    }
    printf("\n");
  }
}
int main() {
  while (cin >> n >> m) solve();
}
