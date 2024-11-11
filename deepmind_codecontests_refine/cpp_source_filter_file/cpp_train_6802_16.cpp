#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
inline int getInt() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long getLL() {
  long long x;
  scanf("%lld", &x);
  return x;
};
inline int NUM(char c) { return (int)c - 48; }
inline char CHR(int n) { return (char)(n + 48); }
template <class T>
inline T MAX(T a, T b) {
  if (a > b) return a;
  return b;
}
template <class T>
inline T MIN(T a, T b) {
  if (a < b) return a;
  return b;
}
template <class T>
inline T ABS(T a) {
  if (a < 0) return -a;
  return a;
}
inline void OPEN(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
  int second, a, b, c;
  cin >> second >> a >> b >> c;
  if ((a + b + c) == 0)
    cout << "0 0 0" << endl;
  else {
    printf("%.5lf %.5lf %.5lf\n", 1.0 * a / (a + b + c) * second,
           1.0 * b / (a + b + c) * second, 1.0 * c / (a + b + c) * second);
  }
  return 0;
}
