#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T MAX(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T MIN(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T GCD(T a, T b) {
  return b == 0 ? a : GCD(b, a % b);
}
inline int rint() {
  int x;
  scanf("%d", &x);
  return x;
}
const double pi = acos(-1.0);
const double eps = 1e-10;
const int inf = 0x3fffffff;
int main(int argc, char *argv[]) {
  int a;
  cin >> a;
  if (a == 3) {
    cout << 1 << endl;
    return 0;
  }
  cout << (a % 3) + 1 << endl;
  return 0;
}
