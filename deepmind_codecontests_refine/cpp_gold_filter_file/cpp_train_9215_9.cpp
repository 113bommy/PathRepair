#include <bits/stdc++.h>
#pragma comment(linker, "/stack:640000000")
using namespace std;
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = acos(-1.0);
template <class T>
inline T _abs(T n) {
  return ((n) < 0 ? -(n) : (n));
}
template <class T>
inline T _max(T a, T b) {
  return (!((a) < (b)) ? (a) : (b));
}
template <class T>
inline T _min(T a, T b) {
  return (((a) < (b)) ? (a) : (b));
}
template <class T>
inline T _swap(T& a, T& b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
template <class T>
inline T gcd(T a, T b) {
  return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template <class T>
inline T lcm(T a, T b) {
  return ((a) / gcd((a), (b)) * (b));
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int bitOn(int N, int pos) { return N = N | (1 << pos); }
int bitOff(int N, int pos) { return N = N & ~(1 << pos); }
bool bitCheck(int N, int pos) { return (bool)(N & (1 << pos)); }
int main() {
  int n;
  while (~scanf("%d", &n)) {
    getchar();
    string st;
    getline(cin, st);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int x = 0, y = 0;
      for (int j = i; j < n; j++) {
        if (st[j] == 'U') y++;
        if (st[j] == 'D') y--;
        if (st[j] == 'R') x++;
        if (st[j] == 'L') x--;
        if (x == 0 && y == 0) cnt++;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
