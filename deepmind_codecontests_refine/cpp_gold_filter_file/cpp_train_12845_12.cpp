#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool gmin(T &a, T b) {
  if (a > b) return a = b, true;
  return false;
}
template <class T>
inline bool gmax(T &a, T b) {
  if (a < b) return a = b, true;
  return false;
}
template <class T>
T exgcd(T a, T b, T &first, T &second) {
  if (!b)
    return first = (T)1, second = (T)0, a;
  else {
    T d = exgcd(b, a % b, second, first);
    return second -= a / b * first, d;
  }
}
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = 1e10;
const double EPS = 1e-9;
const double PI = 3.14159265358979323846264338327950288;
inline int dcmp(const double &a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k >= (n - 1) * n / 2)
    printf("no solution\n");
  else {
    for (int i = 1; i <= n; i++) printf("0 %d\n", i);
  }
  return 0;
}
