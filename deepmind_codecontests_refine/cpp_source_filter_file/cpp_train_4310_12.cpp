#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 505;
const int MOD = int(1e9) + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
template <class T>
inline T Min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T Max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T Min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T Max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline T cub(T a) {
  return a * a * a;
}
template <class T>
inline T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
int main() {
  int a, b;
  while (scanf("%d%d", &a, &b) != EOF) {
    int i, tot = (a * (a - 1)) / 2;
    if (tot <= b) {
      printf("no solution\n");
    } else {
      for (i = 0; i < a; i++) {
        printf("%d %d\n", i, 0);
      }
    }
  }
  return 0;
}
