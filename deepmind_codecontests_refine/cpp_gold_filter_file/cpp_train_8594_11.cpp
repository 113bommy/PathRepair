#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
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
string s;
int cntU[MAXN], cntD[MAXN];
long long sumU[MAXN], sumD[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> s;
  long long sU = 0, sD = 0;
  int posU = -1, posD = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      posU = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'D') {
      posD = i;
      break;
    }
  }
  if (!~posU) {
    for (int i = 0; i < n; i++) cout << i + 1 << " ";
    return 0;
  }
  if (!~posD) {
    for (int i = n; i >= 1; i--) cout << i << " ";
    return 0;
  }
  int cur1 = 0, cur2 = 0;
  for (int i = 0; i < n; i++) {
    cntU[i + 1] = cntU[i];
    cntD[i + 1] = cntD[i];
    if (s[i] == 'D')
      cntD[i + 1]++, sD += i, sumD[++cur1] = sD;
    else
      cntU[i + 1]++, sU += i, sumU[++cur2] = sU;
  }
  for (int i = 0; i < n; i++) {
    int lU = cntU[i];
    int rD = cntD[n] - cntD[i + 1];
    long long res = 0;
    if (s[i] == 'U') {
      if (lU < rD) {
        res = 2ll * (sumD[cntD[i] + lU + 1] - sumD[cntD[i]]);
        res -= 2ll * (sumU[lU]);
        res -= i;
      } else {
        res = 2ll * (sumD[cntD[i] + rD] - sumD[cntD[i]]);
        res -= 2ll * (sumU[lU] - sumU[lU - rD]);
        res -= i;
        res += n - 1;
      }
    } else {
      if (lU <= rD) {
        res = 2ll * (sumD[cntD[i + 1] + lU] - sumD[cntD[i + 1]]);
        res -= 2ll * (sumU[lU]);
        res += i;
      } else {
        res = 2ll * (sumD[cntD[i + 1] + rD] - sumD[cntD[i + 1]]);
        res -= 2ll * (sumU[lU] - sumU[lU - rD - 1]);
        res += i;
        res += n - 1;
      }
    }
    cout << res + 1 << " ";
  }
}
