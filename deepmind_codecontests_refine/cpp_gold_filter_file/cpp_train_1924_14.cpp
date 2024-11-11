#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / __gcd(a, b));
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
template <class T>
string itoa(T a) {
  if (!a) return "0";
  string ret;
  for (T i = a; i > 0; i = i / 10) ret.push_back((i % 10) + 48);
  reverse(ret.begin(), ret.end());
  return ret;
}
double log(double N, double B) { return (log10l(N)) / (log10l(B)); }
vector<string> token(string a, string b) {
  const char *q = a.c_str();
  while (count(b.begin(), b.end(), *q)) q++;
  vector<string> oot;
  while (*q) {
    const char *e = q;
    while (*e && !count(b.begin(), b.end(), *e)) e++;
    oot.push_back(string(q, e));
    q = e;
    while (count(b.begin(), b.end(), *q)) q++;
  }
  return oot;
}
string toBin(int n) {
  string s;
  for (int i = 32 - 1; i >= 0; i--) s += ((bool)(n & (1 << (i))) + '0');
  return s;
}
bool eq(long double a, long double b) { return fabs(a - b) < 1e-9; }
int a[100];
int n;
int k;
int cc = 0;
int inv() {
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) c++;
    }
  }
  return c;
}
int sav[100];
void call(int dep) {
  if (dep == k) {
    int ret = inv();
    sav[ret]++;
    cc++;
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      reverse(a + i, a + j + 1);
      call(dep + 1);
      reverse(a + i, a + j + 1);
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < (int)n; i++) cin >> a[i];
  call(0);
  double ans = 0;
  for (int i = 0; i < (int)50; i++) {
    ans += i * (sav[i] / (double)cc);
  }
  printf("%.12lf\n", ans);
  return 0;
}
