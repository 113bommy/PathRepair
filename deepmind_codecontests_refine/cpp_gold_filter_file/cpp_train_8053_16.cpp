#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <class T>
inline T max1(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T min1(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T gcd1(T a, T b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd1(b, a % b);
}
template <class T>
inline T lb(T num) {
  return num & (-num);
}
inline int bitnum(unsigned long long nValue) {
  nValue = ((0xaaaaaaaaaaaaaaaaull & nValue) >> 1) +
           (0x5555555555555555ull & nValue);
  nValue = ((0xccccccccccccccccull & nValue) >> 2) +
           (0x3333333333333333ull & nValue);
  nValue = ((0xf0f0f0f0f0f0f0f0ull & nValue) >> 4) +
           (0x0f0f0f0f0f0f0f0full & nValue);
  nValue = ((0xff00ff00ff00ff00ull & nValue) >> 8) +
           (0x00ff00ff00ff00ffull & nValue);
  nValue = ((0xffff0000ffff0000ull & nValue) >> 16) +
           (0x0000ffff0000ffffull & nValue);
  nValue = ((0xffffffff00000000ull & nValue) >> 32) +
           (0x00000000ffffffffull & nValue);
  return nValue;
}
inline int jud(double a, double b) {
  if (abs1(a - b) < eps) return 0;
  if (a < b) return -1;
  return 1;
}
long long pow(long long n, long long m, long long mod = 0) {
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
const int maxn = 310100;
int n;
double a, b, c, d;
double orig[maxn][2];
double maxdis;
double num[maxn * 2];
map<double, int> mp;
struct data {
  int a, b, no;
  inline bool operator<(const data &a) const { return b > a.b; }
} sd[maxn];
template <class t>
struct tree_array {
  t num[maxn], n;
  void upd(int no, t add) {
    while (no <= n) {
      num[no] = max1(num[no], add);
      no += lb(no);
    }
  }
  t que(int no) {
    t ans = 0;
    while (no) {
      ans = max1(num[no], ans);
      no -= lb(no);
    }
    return ans;
  }
};
inline double cal(double x1, double x2, double k) {
  return x1 - (x1 - x2) / (1 + 1 / k);
}
tree_array<int> ta;
int main() {
  scanf("%d", &n);
  char ch;
  scanf("%lf%c%lf%lf%c%lf", &a, &ch, &b, &c, &ch, &d);
  a = a / b;
  c = c / d;
  for (long long i = 0; i < n; i++) {
    scanf("%lf%lf", orig[i], orig[i] + 1);
    if (orig[i][0] + orig[i][1] > maxdis) maxdis = orig[i][0] + orig[i][1];
  }
  orig[n][0] = 0;
  orig[n++][1] = 0;
  for (int i = 0; i < n; i++) {
    double a1 = orig[i][0], b1 = orig[i][1];
    orig[i][0] = cal(maxdis - b1, a1, a);
    orig[i][1] = cal(maxdis - b1, a1, c);
    num[i * 2] = orig[i][0];
    num[i * 2 + 1] = orig[i][1];
  }
  sort(num, num + n * 2);
  int l = 1;
  mp[num[0]] = 1;
  for (int i = 1; i < 2 * n; i++) {
    if (!jud(num[i], num[i - 1])) continue;
    mp[num[i]] = ++l;
  }
  for (int i = 0; i < n; i++) {
    orig[i][0] = mp[double(orig[i][0])];
    orig[i][1] = mp[double(orig[i][1])];
    sd[i].a = (int)orig[i][0];
    sd[i].b = (int)orig[i][1];
    sd[i].no = i;
  }
  sort(sd, sd + n);
  ta.n = n * 3;
  for (int i = 0, f = 0; i < n; i += f, f = 0) {
    for (; i + f + 1 < n && sd[i + f].b == sd[i + f + 1].b; f++)
      ;
    f++;
    int stat1[maxn];
    for (int j = 0; j < f; j++) {
      stat1[j] = ta.que(sd[i + j].a - 1) + 1;
      if (sd[i + j].no == n - 1) {
        cout << stat1[j] - 1 << endl;
        return 0;
      }
    }
    for (int j = 0; j < f; j++) ta.upd(sd[i + j].a, stat1[j]);
  }
  return 0;
}
