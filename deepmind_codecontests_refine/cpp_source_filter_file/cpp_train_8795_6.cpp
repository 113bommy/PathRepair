#include <bits/stdc++.h>
using namespace std;
int getInt() {
  int x;
  scanf("%d", &x);
  return x;
}
long long getLongLong() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
double getDouble() {
  double x;
  scanf("%lf", &x);
  return x;
}
char getChar() {
  char x;
  scanf("%c", &x);
  return x;
}
template <typename t>
t abs(t a) {
  if (a >= 0) return a;
  return -a;
}
bool my(int a, int b) { return a > b; }
int main() {
  int n = getInt();
  int a[n];
  for (int i = 0; i < n; i++) a[i] = getInt();
  sort(a + 1, a + n, my);
  int ans = 0;
  int i = 1;
  if (a[1] < a[0]) {
    ans = 0;
  } else {
    ans = (a[1] - a[0]) / 2 + 1;
    int car = ans;
    while (true) {
      bool f = 1;
      for (i = 1; i < n; i++) {
        if (a[i] > (a[0] + ans)) {
          car -= (a[i] - (ans + a[0]));
        } else
          break;
        if (car <= 0) {
          f = 0;
          break;
        }
      }
      if (f) break;
      ans++;
      car = ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
