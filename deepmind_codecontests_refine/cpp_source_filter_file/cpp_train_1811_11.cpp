#include <bits/stdc++.h>
using namespace std;
template <class F, class T>
T convert(F a, int p = -1) {
  stringstream ss;
  if (p >= 0) ss << fixed << setprecision(p);
  ss << a;
  T r;
  ss >> r;
  return r;
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
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T cube(T x) {
  return x * x * x;
}
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
  return s == 0 ? 0 : cntbit(s >> 1) + (s & 1);
}
const int bfsz = 1 << 16;
char bf[bfsz + 5];
int rsz = 0;
int ptr = 0;
char gc() {
  if (rsz <= 0) {
    ptr = 0;
    rsz = (int)fread(bf, 1, bfsz, stdin);
    if (rsz <= 0) return EOF;
  }
  --rsz;
  return bf[ptr++];
}
void ga(char &c) {
  c = EOF;
  while (!isalpha(c)) c = gc();
}
int gs(char s[]) {
  int l = 0;
  char c = gc();
  while (isspace(c)) c = gc();
  while (c != EOF && !isspace(c)) {
    s[l++] = c;
    c = gc();
  }
  s[l] = '\0';
  return l;
}
template <class T>
bool gi(T &v) {
  v = 0;
  char c = gc();
  while (c != EOF && c != '-' && !isdigit(c)) c = gc();
  if (c == EOF) return false;
  bool neg = c == '-';
  if (neg) c = gc();
  while (isdigit(c)) {
    v = v * 10 + c - '0';
    c = gc();
  }
  if (neg) v = -v;
  return true;
}
const double PI = acos(-1.0);
const double eps = 1e-9;
const int inf = (int)1e9 + 5;
const long long linf = (long long)1e17 + 5;
const long long mod = 10003;
int num[1000005], n, k, a[5005], f[1000005];
int main() {
  cin >> n >> k;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  memset(num, 0, sizeof(num));
  memset(f, 0, sizeof(f));
  if (n <= k + 1) {
    cout << 1;
    return 0;
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (i + 1); j <= (n); ++j) num[a[j] - a[i]]++;
  for (int i = n - k + 1;; i++) {
    int d = 0;
    for (int j = i; j < 1000005; j += i) d += num[j];
    if (d > (k) * (k + 1) / 2) continue;
    d = 0;
    for (int j = (1); j <= (n); ++j) {
      if (f[a[j] % i]) d++;
      if (d > k) break;
      f[a[j] % i] = 1;
    }
    if (d <= k) {
      cout << i;
      return 0;
    }
    for (int j = (1); j <= (n); ++j) f[a[j] % i] = 0;
  }
  return 0;
}
