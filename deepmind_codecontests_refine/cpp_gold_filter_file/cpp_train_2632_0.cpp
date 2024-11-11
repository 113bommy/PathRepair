#include <bits/stdc++.h>
using namespace std;
int n;
long long mi, ma;
void test(long long a, long long b, long long c) {
  long long cur = (a + 1) * (b + 2) * (c + 2);
  if (cur > ma) ma = cur;
  if (cur < mi || mi == -1) mi = cur;
}
void check(long long a, long long b, long long c) {
  test(a, b, c);
  test(b, a, c);
  test(c, a, b);
}
int main() {
  scanf("%d", &n);
  ma = mi = -1;
  for (int a = 1; a * a <= n; a++)
    if (n % a == 0) {
      int nn = n / a;
      for (int b = a; b * b <= nn; b++)
        if (nn % b == 0) {
          int c = nn / b;
          check(a, b, c);
        }
    }
  cout << mi - n << " " << ma - n << endl;
  return 0;
}
