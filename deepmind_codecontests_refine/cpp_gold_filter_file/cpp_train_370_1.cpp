#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
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
const int nip = 330;
int n, l[MAXN], r[MAXN], isR[MAXN], isL[MAXN], gg[MAXN];
int d[nip + 5][nip * nip + 5], g[nip + 5][nip * nip + 5];
int main() {
  cin >> n;
  int num;
  cin >> num;
  for (int i = 0; i < n; i++) gg[i] = -1;
  for (int i = 0; i < num; i++) {
    scanf("%d%d", &l[i], &r[i]);
    l[i]--;
    r[i]--;
    isR[r[i]] = 1;
    isL[l[i]] = 1;
    gg[r[i]] = l[i];
  }
  for (int i = nip - 1; i < n; i += nip) {
    for (int j = i; j >= 0; j--) {
      if (!isL[j]) d[i / nip][j] = -1;
      if (isR[j]) d[i / nip][gg[j]] = max(d[i / nip][gg[j]], j);
    }
  }
  stack<int> st;
  for (int i = nip - 1; i < n; i += nip) {
    while (!st.empty()) st.pop();
    for (int j = i; j >= 0; j--) {
      g[i / nip][j] = j;
      while (!st.empty() && st.top() <= d[i / nip][j]) {
        g[i / nip][j] = max(g[i / nip][j], g[i / nip][st.top()]);
        st.pop();
      }
      st.push(j);
    }
  }
  int q;
  cin >> q;
  for (int tc = 0; tc < q; tc++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    if (y - x + 1 <= nip) {
      int ans = x;
      for (int i = x + 1; i <= y; i++) {
        if (gg[i] >= x && gg[i] <= ans) {
          ans = i;
        }
      }
      printf("%d\n", ans + 1);
    } else {
      int hi = y / nip;
      hi--;
      int ans = g[hi][x];
      for (int i = (hi + 1) * nip; i <= y; i++) {
        if (gg[i] >= x && gg[i] <= ans) {
          ans = i;
        }
      }
      printf("%d\n", ans + 1);
    }
  }
  return 0;
}
