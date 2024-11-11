#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) { return n | (1LL << i); }
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx4[] = {0, 0, +1, -1};
int dy4[] = {+1, -1, 0, 0};
int dx8[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy8[] = {0, +1, 0, -1, +1, -1, +1, -1};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline bool isIntege(double num) { return (num == (int)num); }
inline bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
}
inline double coDist(double x1, double y1, double x2, double y2) {
  return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}
inline double TriangleAreaWithSide(double a, double b, double c) {
  double s = (a + b + c) / 2;
  double area = sqrt(s * (s - a) * (s - b) * (s - c));
  return area;
}
inline double area3(double x1, double y1, double x2, double y2, double x3,
                    double y3) {
  double A = abs((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1));
  A /= 2.0;
  return A;
}
inline long double degreetoradian(long double x) {
  long double val = PI * x;
  val /= (180.0);
  return val;
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
template <typename T>
inline T gcd(T a, T b) {
  T c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
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
inline bool equalTo(double a, double b) {
  if (fabs(a - b) <= eps)
    return true;
  else
    return false;
}
inline bool notEqual(double a, double b) {
  if (fabs(a - b) > eps)
    return true;
  else
    return false;
}
inline bool lessThan(double a, double b) {
  if (a + eps < b)
    return true;
  else
    return false;
}
inline bool lessThanEqual(double a, double b) {
  if (a < b + eps)
    return true;
  else
    return false;
}
inline bool greaterThan(double a, double b) {
  if (a > b + eps)
    return true;
  else
    return false;
}
inline bool greaterThanEqual(double a, double b) {
  if (a + eps > b)
    return true;
  else
    return false;
}
inline string to_s(int t) {
  stringstream ss;
  ss << t;
  return ss.str();
}
struct edge {
  int p, q, w;
};
bool cmp(edge &a, edge &b) { return a.w < b.w; }
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
int bit[50];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.emplace_back(x);
  }
  long long p = 2, q = 1;
  for (int k = 0; k < 30; k++) {
    vector<int> a;
    for (int j = 0; j < n; j++) {
      a.emplace_back(v[j] % p);
    }
    sort((a).begin(), (a).end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int lo = i + 1, hi = n - 1, x = -1;
      int y = q - a[i];
      int z = p - 1 - a[i];
      while (lo <= hi) {
        int mid = (hi + lo) >> 1;
        if (a[mid] >= y && a[mid] <= z) {
          x = mid;
          hi = mid - 1;
        } else if (a[mid] < y)
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      int tem = -1;
      lo = i + 1, hi = n - 1;
      while (lo <= hi) {
        int mid = (hi + lo) >> 1;
        if (a[mid] >= y && a[mid] <= z) {
          tem = mid;
          lo = mid + 1;
        } else if (a[mid] < y)
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      if (x != -1 && tem != -1) ans += (tem - x + 1);
      x = -1, lo = i + 1, hi = n - 1;
      y = p + q - a[i];
      z = p * 2 - 2 - a[i];
      while (lo <= hi) {
        int mid = (hi + lo) >> 1;
        if (a[mid] >= y && a[mid] <= z) {
          x = mid;
          hi = mid - 1;
        } else if (a[mid] < y)
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      tem = -1, lo = i + 1, hi = n - 1;
      while (lo <= hi) {
        int mid = (hi + lo) >> 1;
        if (a[mid] >= y && a[mid] <= z) {
          tem = mid;
          lo = mid + 1;
        } else if (a[mid] < y)
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      if (x != -1 && tem != -1) ans += (tem - x + 1);
    }
    bit[k] = ans % 2;
    p *= 2;
    q *= 2;
  }
  p = 1;
  long long ans = 0;
  for (int i = 0; i < 30; i++) {
    if (bit[i] == 1) ans += p;
    p *= 2;
  }
  cout << ans << '\n';
}
