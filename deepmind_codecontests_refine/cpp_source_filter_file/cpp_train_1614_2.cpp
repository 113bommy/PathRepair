#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / abs1(a) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 0) return 0;
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitmaxl(unsigned int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
inline int bitmaxl(long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
  if (mod == -1) mod = 1000000007;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}
long long a, b, c, l;
long long ans = 0;
long long calc(long long maxb, long long maxc, long long rl) {
  long long rans = 0;
  if (maxc >= rl) {
    rans += 1ll * (rl - min(maxb, rl) + 1 + rl + 1) * (min(maxb, rl) + 1) / 2;
  } else {
    long long stb = rl - maxc;
    rans += (min(maxb, stb) + 1) * (maxc + 1);
    if (stb < maxb) {
      long long be = rl - min(maxb, rl), en = maxc - 1;
      rans += (be + 1 + en + 1) * (en - be + 1) / 2;
    }
  }
  return rans;
}
void justdoit() {
  long long ra = a, rb = b, rc = c, rl = l;
  if (ra < max(rb, rc) + 1) {
    rl -= max(rb, rc) + 1 - ra;
    ra += max(rb, rc) + 1 - ra;
  }
  if (rl < 0) return;
  for (int j = 0; j < rl; j++) {
    if (ra >= rb + rc + l) break;
    long long maxb = ra - rb - 1, maxc = ra - rc - 1, minsum = ra - rb - rc + 1;
    ans += calc(maxb, maxc, rl);
    if (minsum > 0) ans -= calc(maxb, maxc, minsum - 1);
    ra++;
    rl--;
  }
}
void justdoit1() {
  long long ra = a, rb = b, rc = c, rl = l;
  long long sum = ra + rb + rc + rl;
  ra += max(0ll, b - a);
  rb += max(0ll, a - b);
  ra += max(0ll, rc - ra + 1);
  rb += max(0ll, rc - rb + 1);
  rl = sum - ra - rb - rc;
  if (rl < 0) return;
  for (int i = 0; i * 2 <= rl; i++) {
    long long left = rl - i * 2;
    left = min(left, ra + i - rc - 1);
    ans += left + 1;
  }
}
void justdoit2() {
  long long ra = a, rb = b, rc = c, rl = l;
  long long sum = ra + rb + rc + rl;
  for (int i = max1(a, b, c); i * 3 <= sum; i++) ans++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> c >> l;
  justdoit();
  swap(a, b);
  justdoit();
  swap(a, c);
  justdoit();
  justdoit1();
  swap(a, c);
  justdoit1();
  swap(b, c);
  justdoit1();
  justdoit2();
  cout << ans << endl;
  return 0;
}
