#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline void normal(long long int &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long int modMul(long long int a, long long int b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long int modAdd(long long int a, long long int b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long int modSub(long long int a, long long int b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long int modPow(long long int b, long long int p) {
  long long int r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long int modInverse(long long int a) {
  return modPow(a, 1000000007 - 2);
}
inline long long int modDiv(long long int a, long long int b) {
  return modMul(a, modInverse(b));
}
inline bool isInside(pair<int, int> p, long long int n, long long int m) {
  return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m);
}
inline bool isInside(pair<int, int> p, long long int n) {
  return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < n);
}
inline bool isSquare(long long int x) {
  long long int s = sqrt(x);
  return (s * s == x);
}
inline bool isFib(long long int x) {
  return isSquare(5 * x * x + 4) || isSquare(5 * x * x - 4);
}
inline bool isPowerOfTwo(long long int x) {
  return ((1LL << (long long int)log2(x)) == x);
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const pair<first, second> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
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
void faltu() { cerr << endl; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << endl;
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
const long long int INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;
const int mx = (int)1e5 + 9;
long long int n, m, a, b, t, i, j, d, cs = 0, counT = 0, k, ans = 0, l = 0,
                                      sum1 = 0, sum = 0, Max, Min, num;
int main() {
  ios_base::sync_with_stdio(false);
  ;
  t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    map<long long int, long long int> kahini;
    vector<long long int> chk;
    for (int i = 0; i < (m); i++) {
      cin >> a >> b >> k;
      kahini[k]++;
    }
    for (int i = 1; i <= (n); i++) {
      if (kahini[i] == 0) {
        chk.push_back(i);
      }
    }
    for (int i = 1; i <= (n - 1); i++) {
      if (chk[0] == i) continue;
      cout << chk[0] << ' ' << i << '\n';
    }
  }
}
