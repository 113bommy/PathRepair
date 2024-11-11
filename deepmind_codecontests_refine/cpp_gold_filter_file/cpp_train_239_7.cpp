#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long linf = 1ll << 60;
const double dinf = 1e10;
template <typename T>
inline void scf(T &x) {
  bool f = 0;
  x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) {
  scf(x);
  return scf(y);
}
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) {
  scf(x);
  scf(y);
  return scf(z);
}
inline bool solve(long long a, long long b) {
  if (a > b) swap(a, b);
  if (!a) return 0;
  bool f = solve(a, b % a);
  if (!f) return 1;
  long long x = b / a;
  if (a & 1) return (x & 1) ^ 1;
  x %= (a + 1);
  return (x & 1) ^ 1;
}
int main() {
  int T;
  scf(T);
  while (T--) {
    long long a, b;
    scf(a, b);
    puts(solve(a, b) ? "First" : "Second");
  }
  return 0;
}
