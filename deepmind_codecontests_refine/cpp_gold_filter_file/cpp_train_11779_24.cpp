#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238463;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
int graps[3];
int needs[3];
int n;
bool doAndrew() {
  graps[0] -= needs[0];
  n -= needs[0];
  if (graps[0] < 0) return 0;
  return 1;
}
bool doDimitryMichael() {
  if (graps[0] + graps[1] < needs[1]) {
    return 0;
  }
  n -= needs[1];
  return (n >= needs[2]);
}
void cf1114() {
  for (int i = 0; i < (3); i++) cin >> needs[i];
  for (int i = 0; i < (3); i++) {
    cin >> graps[i];
    n += graps[i];
  }
  if (doAndrew() && doDimitryMichael()) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
}
int main() { cf1114(); }
