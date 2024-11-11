#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long pow(long long a, int b) {
  long long r = 1;
  while (b) {
    if (b % 2) b *= a;
    a *= a;
    b /= 2;
  }
  return r;
}
int main() {
  int a, b;
  cin >> a >> b;
  long long ans = -999999999;
  int m1, m2, m3;
  int tmp = min(b, a + 1);
  if (b == 0) {
    long long t = pow(a, 2);
    cout << t << endl;
    for (int i = 1; i <= a; i++) printf("o");
    cout << endl;
    return 0;
  }
  for (int i = 1; i <= tmp; i++) {
    int x = b / i;
    int y = b % i;
    long long f;
    if (i == 1)
      f = -pow(b, 2) + pow(a, 2);
    else
      f = -pow(x + 1, 2) * (long long)y - pow(x, 2) * (long long)(i - y) +
          pow(a - (i - 2), 2) + (long long)(i - 2);
    if (ans < f) {
      ans = f;
      m1 = i;
      m2 = x;
      m3 = y;
    }
  }
  printf("%I64d\n", ans);
  for (int i = 1; i <= m1; i++) {
    for (int j = 1; j <= m2 + ((m3) > 0 ? 1 : 0); j++) printf("x");
    if (i < m1 && m1 > 1) {
      if (i == 1)
        for (int j = 1; j <= a - (m1 - 2); j++) printf("o");
      else
        printf("o");
    } else if (m1 == 1)
      for (int j = 1; j <= a; j++) printf("o");
    m3--;
  }
  cout << endl;
  return 0;
}
