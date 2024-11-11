#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
bool seive[1010000];
vector<long long> prime;
void seiveGen(long long limit) {
  limit += 100;
  long long sqrtn = sqrt(limit);
  for (long long i = 3; i <= sqrtn; i += 2) {
    if (!seive[i >> 1]) {
      for (long long j = i * i; j < limit; j += i + i) {
        seive[j >> 1] = 1;
      }
    }
  }
  prime.push_back(2);
  for (long long i = 3; i < limit; i += 2) {
    if (!seive[i >> 1]) prime.push_back(i);
  }
}
inline long long power(long long bs, long long k) {
  long long x = 1LL, y = bs;
  if (k == 0) return 1LL;
  while (k > 0) {
    if (k % 2) x *= y;
    y *= y;
    k /= 2;
  }
  return x;
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const pair<first, second> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
string to_str(T t) {
  stringstream ss;
  ss << t;
  return ss.str();
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const map<first, second> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
clock_t tStart = clock();
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
string s;
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.unsetf(ios::floatfield);
  cout.precision(10);
  cout.setf(ios::fixed, ios::floatfield);
  ;
  cin >> n >> s;
  long long i, j, sum = 0LL;
  for (i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      j = i + 1;
      while (j < n && s[j] == s[i + 1]) {
        j++;
      }
      sum += ((j - i - 1));
      i = j - 2;
    }
  }
  for (i = 0; i < n - 1; ++i) {
    if (s[i] == s[i + 1]) {
      j = i + 2;
      while (j < n && s[j] == s[i]) {
        j++;
      }
      if (j < n) sum += (j - i - 1);
      i = j - 1;
    }
  }
  cout << (n * (n + 1) / 2) - sum - n;
  return 0;
}
