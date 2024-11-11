#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return (d > 0) ? 1 : -1;
}
int n, m, T;
bool win(long long a, long long b) {
  if (a * b == 0) return false;
  if (a > b) swap(a, b);
  if (!win(a, b % a)) return 1;
  return ((b / a) % (a + b)) % 2 == 0;
}
int main() {
  cin >> T;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    if (win(a, b))
      printf("First\n");
    else
      printf("Second\n");
  }
  return 0;
}
