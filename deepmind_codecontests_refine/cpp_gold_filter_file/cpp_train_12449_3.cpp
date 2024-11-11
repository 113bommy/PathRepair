#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcount(s);
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
long long q, l, r;
long long f[16][1 << 16];
string str = "0123456789abcdef";
long long n, m;
int a[15], num;
long long g[20][20][2][2][2];
void init() {
  memset(f, 0, sizeof(f));
  for (int mask = 0; mask < (1 << 16); ++mask) {
    int temp = mask;
    int A = 15;
    int Max = 0;
    for (int run = 0; run < (4); ++run) {
      int u = temp & A;
      Max = max(Max, u);
      temp >>= 4;
    }
    for (int i = 0; i < (16); ++i) {
      if (mask == 0)
        f[i][mask] = 0;
      else
        f[i][mask] = f[i][mask - 1];
    }
    for (int i = 0; i < (16); ++i)
      if ((i <= Max && getbit(mask, Max)) || (getbit(mask, i) && i > Max)) {
        f[i][mask]++;
      }
  }
}
int TT(char ch) {
  for (int i = 0; i < (16); ++i)
    if (str[i] == ch) return i;
  return -1;
}
long long remind(string s) {
  long long res = 0;
  for (int i = 0; i < (((long long)(s).size())); ++i) {
    res = res * 16 + TT(s[i]);
  }
  return res;
}
long long go(int id, int so, int cochua, int behon, int can) {
  if (id == 0) {
    return (cochua & (behon >= can));
  }
  long long &res = g[id][so][cochua][behon][can];
  if (res != -1) return res;
  res = 0;
  int lo = 0, hi = so;
  if (!behon) {
    hi = min(hi, a[id]);
  }
  for (int i = lo; i <= hi; i++) {
    res += go(id - 1, so, cochua | (i == so), behon | (i < a[id]), can);
  }
  return res;
}
long long cal(long long x) {
  if (x <= 0) return 0;
  long long A = (1ll << 16) - 1;
  long long B = (1ll << 4) - 1;
  m = (A & x);
  n = (x >> 16);
  num = 0;
  while (n) {
    a[++num] = (n & B);
    n >>= 4;
  }
  memset(g, -1, sizeof(g));
  long long res = 0;
  for (int i = 0; i < (16); ++i) {
    int cochua = 0;
    if (i == 0) cochua = 1;
    long long T = go(num, i, cochua, 0, 0);
    res += T * f[i][m];
    T = go(num, i, cochua, 0, 1);
    res += T * (f[i][A] - f[i][m]);
  }
  return res;
}
void solve() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  cin >> q;
  for (int run = 0; run < (q); ++run) {
    string s;
    cin >> s;
    l = remind(s);
    cin >> s;
    r = remind(s);
    cout << cal(r) - cal(l - 1) << endl;
  }
}
int main() {
  solve();
  return 0;
}
