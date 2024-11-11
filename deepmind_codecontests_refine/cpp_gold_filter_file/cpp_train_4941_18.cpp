#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline string toString(T a) {
  ostringstream os("");
  os << a;
  return os.str();
}
template <typename T>
inline long long toLong(T a) {
  long long res;
  istringstream os(a);
  os >> res;
  return res;
}
template <typename T>
inline int toInt(T a) {
  int res;
  istringstream os(a);
  os >> res;
  return res;
}
template <typename T>
inline double toDouble(T a) {
  double res;
  istringstream os(a);
  os >> res;
  return res;
}
template <typename T>
inline T SQ(T a) {
  return a * a;
}
template <typename T>
inline T GCD(T a, T b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}
template <typename T>
inline T LCM(T a, T b) {
  long long res = a * b;
  res /= GCD(a, b);
  return res;
}
template <typename T>
inline unsigned long long BIGMOD(T a, T b, T m) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return SQ(BIGMOD(a, b / 2, m)) % m;
  else
    return (a % m * BIGMOD(a, b - 1, m)) % m;
}
template <typename T>
inline vector<string> PARSE(T str) {
  vector<string> res;
  string s;
  istringstream os(str);
  while (os >> s) res.push_back(s);
  return res;
}
template <typename T>
inline unsigned long long DIST(T A, T B) {
  unsigned long long res =
      (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
  return res;
}
template <typename T>
inline long long CROSS(T A, T B, T C) {
  return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}
template <typename T>
inline double cosAngle(T a, T b, T c) {
  double res = a * a + b * b - c * c;
  res = res / (2 * a * b);
  res = acos(res);
  return res;
}
template <typename T>
inline T POWER(T base, int po) {
  T res = 1;
  if (base == 0) return 0;
  for (int i = (0); i < (po); i++) res *= base;
  return res;
}
template <typename T>
inline bool IS_ON(T mask, T pos) {
  return mask & (1 << pos);
}
template <typename T>
inline int OFF(T mask, T pos) {
  return mask ^ (1 << pos);
}
template <typename T>
inline int ON(T mask, T pos) {
  return mask | (1 << pos);
}
template <typename T>
inline bool INSIDE_GRID(int R, int C, int ro, int clm) {
  if (R >= 0 && C >= 0 && R < ro && C < clm) return 1;
  return 0;
}
template <typename T>
inline void PRINT_GRID(T GRID, int ro, int clm) {
  cout << "GRID"
       << ": " << GRID << endl;
  for (int i = (0); i < (ro); i++) {
    for (int j = (0); j < (clm); j++) cout << GRID[i][j] << " ";
    puts("");
  }
}
int find(long long n) {
  int res = 0;
  for (long long i = 2; i <= 100000; i++) {
    if ((i * 2LL + ((i * (i - 1LL)) / 2LL) * 3) <= n)
      res = i;
    else
      break;
  }
  return res;
}
int main() {
  long long n, baki;
  cin >> n;
  int res = 0;
  for (long long i = 1; i < 10000000; i++) {
    baki = n - ((i * 2LL) + ((i * (i - 1LL)) / 2LL) * 3LL);
    if (baki < 0) break;
    if (baki % 3 == 0) res++;
  }
  cout << res << endl;
  return 0;
}
