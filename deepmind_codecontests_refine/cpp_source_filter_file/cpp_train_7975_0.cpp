#include <bits/stdc++.h>
using namespace std;
template <typename T>
T POW(T base, T power) {
  T ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base);
    base = (base * base);
    power >>= 1;
  }
  return ret;
}
template <typename T>
inline T GCD(T a, T b) {
  if (a < 0) return GCD(-a, b);
  if (b < 0) return GCD(a, -b);
  return (b == 0) ? a : GCD(b, a % b);
}
template <typename T>
T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return a * (b / GCD(a, b));
}
template <typename T>
T EUCLIDE(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <typename T>
double DIS(T x1, T y1, T x2, T y2) {
  return sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
template <typename T>
T ANGLE(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
template <typename T>
long long isLeft(T a, T b, T c) {
  return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}
void BINARY(int n) {
  bitset<31> a = n;
  cout << a << endl;
}
void P_ARR(int *ar, int a, int b) {
  if (a > b) swap(a, b);
  if (a <= b) cout << ar[a];
  for (int i = a + 1; i <= b; i++) cout << " " << ar[i];
  cout << endl;
}
template <class T>
inline void make_unique_vec(vector<T> &vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
const double PI = 2 * acos(0);
double DEG(double x) { return (180.0 * x) / (PI * 1.0); }
double RAD(double x) { return (x * (PI * 1.0)) / (180.0); }
template <class T>
inline void make_unique_arr(T *ar, int &n) {
  sort(ar + 1, ar + n + 1);
  n = unique(ar + 1, ar + n + 1) - ar - 1;
}
int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int st[200007];
int ed[200007];
struct data {
  int t, cst, d;
  int id;
  bool operator<(const data &p) const {
    return (d > p.d || (d == p.d && t < p.t) ||
            (d == p.d && t == p.t && cst > p.cst));
  }
} ar[200007];
long long dp[107][2007];
int path[107][2007];
int n;
long long call(int pos, int gori) {
  if (pos > n) {
    return 0;
  }
  long long &ret = dp[pos][gori];
  if (ret != -1) return ret;
  ret = 0;
  ret = call(pos + 1, gori);
  path[pos][gori] = 0;
  if (gori + ar[pos].t < ar[pos].d) {
    long long v = call(pos + 1, gori + ar[pos].t) + ar[pos].cst;
    if (v > ret) {
      ret = v;
      path[pos][gori] = 1;
    }
  }
  return ret;
}
vector<int> res;
void show(int pos, int gori) {
  if (pos > n) return;
  if (path[pos][gori] == 0)
    show(pos + 1, gori);
  else {
    res.push_back(ar[pos].id);
    show(pos + 1, gori + ar[pos].t);
  }
}
int main() {
  scanf("%d", &(n));
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &(ar[i].t), &(ar[i].d), &(ar[i].cst));
    ar[i].id = i;
  }
  memset(dp, -1, sizeof dp);
  sort(ar + 1, ar + 1 + n);
  long long ret = call(1, 0);
  printf("%lld\n", ret);
  show(1, 0);
  printf("%d\n", res.size());
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}
