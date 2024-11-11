#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline string getStr() {
  char ch[1001];
  scanf("%s", ch);
  return ch;
}
inline char getCh() {
  char ch;
  scanf(" %c", &ch);
  return ch;
}
template <class P, class Q>
inline P smin(P &a, Q b) {
  if (b < a) a = b;
  return a;
}
template <class P, class Q>
inline P smax(P &a, Q b) {
  if (a < b) a = b;
  return a;
}
const long long MOD = 1e9 + 7;
const long long MAX_N = 4e6 + 10;
const long long MAX_LG = 21;
const long long base = 29;
const long long MAX_DIF = 5005;
long long res = 0;
long long fen[MAX_N][4];
inline void add(long long x, long long val, long long tp) {
  for (long long p = x; p < MAX_N; p += p & -p) fen[p][tp] += val;
}
inline long long get(long long x, long long tp) {
  long long res = 0;
  for (long long p = x; p; p -= p & -p) res += fen[p][tp];
  return res;
}
long long cnt;
int32_t main() {
  long long n = in(), m = in(), q = in();
  while (q--) {
    long long tp = in(), x1 = in(), y1 = in(), x2 = in(), y2 = in();
    if (!tp) {
      long long v = in();
      add(x1, 1LL * (y2 - y1 + 1) * v, 0);
      add(x2 + 1, -1LL * (y2 - y1 + 1) * v, 0);
      add(x1, 1LL * v * (x1 - 1) * (y2 - y1 + 1), 1);
      add(x2 + 1, -1LL * v * (y2 - y1 + 1) * x2, 1);
      add(y1, 1LL * (x2 - x1 + 1) * v, 2);
      add(y2 + 1, -1LL * (x2 - x1 + 1) * v, 2);
      add(y1, 1LL * (x2 - x1 + 1) * v * (y1 - 1), 3);
      add(y2 + 1, -1LL * (x2 - x1 + 1) * v * y2, 3);
      cnt += 1LL * v * (x2 - x1 + 1) * (y2 - y1 + 1);
    } else {
      long long row = 1LL * get(x2, 0) * x2 - get(x2, 1) -
                      (1LL * get(x1 - 1, 0) * (x1 - 1) - get(x1 - 1, 1));
      long long column = 1LL * get(y2, 2) * y2 - get(y2, 1) -
                         (1LL * get(y1 - 1, 2) * (y1 - 1) - get(y1 - 1, 3));
      cout << row + column - cnt << "\n";
    }
  }
}
