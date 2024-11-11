#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = (int)1e6 + 7, mod = 1000000007, M = 2e9;
long long n, a, b, x = -1, y = -1, p[N], c = 1, l;
void f() {
  for (long long i = 0; i * a <= n; i++) {
    if ((n - i * a) % b == 0) {
      x = i;
      y = n - i * a;
      y /= b;
      return;
    }
  }
}
int main() {
  cin >> n >> a >> b;
  if (a < b) swap(a, b);
  f();
  if (x == -1)
    cout << x;
  else {
    for (int i = 0; i < x; i++) {
      l = c;
      for (int j = 1; j < a; j++) {
        cout << ++c << ' ';
      }
      cout << l << ' ';
      c++;
    }
    for (int i = 0; i < y; i++) {
      l = c;
      for (int j = 1; j < b; j++) {
        cout << ++c << ' ';
      }
      cout << l << ' ';
      c++;
    }
  }
  return 0;
}
