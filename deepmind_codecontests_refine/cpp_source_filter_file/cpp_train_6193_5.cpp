#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 1e4 + 5;
const int oo = 1e9;
const double foo = 1e30;
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
  return __builtin_popcounll(s);
}
template <class T>
T sqr(T x) {
  return x * x;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
int n;
long double val[MAXN], f[MAXN];
vector<int> has[MAXN], ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int s, r;
    scanf("%d%d", &s, &r);
    if (r > val[s]) {
      val[s] = r;
      has[s].clear();
    }
    if (r == val[s]) has[s].push_back(i);
  }
  for (int i = 1; i <= 10000; i++) {
    if (!has[i].empty()) f[i] = val[i] / i;
  }
  for (int i = 1; i <= 10000; i++) {
    if (has[i].empty()) continue;
    long double l = 10000000000000.0;
    long double r = 0;
    int cant = 0;
    for (int j = 1; j < i; j++) {
      if (!has[j].empty() && val[j] > val[i]) {
        long double tmp =
            ((long double)i - (long double)j) / (val[j] - val[i]) * f[i] * f[j];
        r = min(r, tmp);
      }
    }
    for (int j = i + 1; j <= 10000; j++) {
      if (cant) break;
      if (!has[j].empty()) {
        if (val[i] > val[j]) {
          long double tmp = ((long double)j - (long double)i) /
                            (val[i] - val[j]) * f[i] * f[j];
          l = max(l, tmp);
        } else
          cant = 1;
      }
    }
    if ((l == 10000000000000.0 || r == 0 || l <= r) && !cant) {
      for (int j = 0; j < ((int)(has[i]).size()); j++) {
        ans.push_back(has[i][j]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ((int)(ans).size()); i++) {
    printf("%d ", ans[i] + 1);
  }
}
