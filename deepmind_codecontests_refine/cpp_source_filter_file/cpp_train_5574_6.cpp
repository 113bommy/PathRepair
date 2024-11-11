#include <bits/stdc++.h>
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T cube(T x) {
  return x * x * x;
}
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int Max = 0, Min = n;
  bool canDo = true;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    Max = max(Max, x);
    Min = min(Min, y);
  }
  if (Max >= Min)
    cout << 0;
  else
    cout << (Min - Max);
}
