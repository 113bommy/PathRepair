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
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int cnt = 0;
    for (int i = (int)(0); i <= (int)(n - 1); i++) {
      int x;
      scanf("%d", &x);
      if (x % 2 == 1) cnt++;
    }
    if (cnt > 0)
      printf("First\n");
    else
      printf("Second\n");
  }
  return 0;
}
