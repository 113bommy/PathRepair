#include <bits/stdc++.h>
using namespace std;
long long a[5], b[5];
long long ans[5][2];
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long same;
long long inf = 999999999999999;
long long powd(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans *= a;
    b /= 2;
    a = a * a;
  }
  return ans;
}
long long f(long long x, long long y) {
  long long xx = x;
  long long yy = y;
  long long gcdd = gcd(x, y);
  x /= gcdd;
  y /= gcdd;
  int n12 = 0, n13 = 0;
  while (x % 2 == 0) {
    n12++;
    x /= 2;
  }
  while (x % 3 == 0) {
    n13++;
    x /= 3;
  }
  if (x != 1) return inf;
  int n22 = 0, n23 = 0;
  while (y % 2 == 0) {
    n22++;
    y /= 2;
  }
  while (y % 3 == 0) {
    n23++;
    y /= 3;
  }
  if (y != 1) return inf;
  long long n2 = n12 - n22;
  long long n3 = n13 - n23;
  long long ans = abs(n3) + abs(n2 + n3);
  same = xx;
  if (n3 >= 0) same /= (powd(3, n3)), same *= (powd(2, n3));
  if ((n2 + n3) >= 0) same /= (powd(2, n2 + n3));
  return ans;
}
void ff(long long t1, long long t2, long long c[2]) {
  int n12 = 0, n13 = 0;
  while (t1 % 2 == 0) {
    n12++;
    t1 /= 2;
  }
  while (t1 % 3 == 0) {
    n13++;
    t1 /= 3;
  }
  int n22 = 0, n23 = 0;
  while (t2 % 2 == 0) {
    n22++;
    t2 /= 2;
  }
  while (t2 % 3 == 0) {
    n23++;
    t2 /= 3;
  }
  int n2 = n12 - n22;
  while (n13 > 0 && c[1] % 3 == 0) {
    c[1] /= 3;
    c[1] *= 2;
    n2++;
    n13--;
  }
  while (n13 > 0 && c[0] % 3 == 0) {
    c[0] /= 3;
    c[0] *= 2;
    n2++;
    n13--;
  }
  while (n2 > 0 && c[0] % 2 == 0) {
    c[0] /= 2;
    n2--;
  }
  while (n2 > 0 && c[1] % 2 == 0) {
    c[1] /= 2;
    n2--;
  }
}
int main() {
  {
    for (int i = 0; i < 2; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < 2; i++) scanf("%lld", &b[i]);
    long long ans1 = f(a[0] * a[1], b[0] * b[1]);
    if ((ans1) == inf) {
      printf("-1\n");
      return 0;
    }
    long long tp1 = gcd(a[0] * a[1], same);
    long long tp2 = gcd(b[0] * b[1], same);
    long long t1 = a[0] * a[1] / tp1;
    long long t2 = same / tp1;
    long long t3 = b[0] * b[1] / tp2;
    long long t4 = same / tp2;
    ans[0][0] = a[0];
    ans[0][1] = a[1];
    ans[1][0] = b[0];
    ans[1][1] = b[1];
    ff(t1, t2, ans[0]);
    ff(t3, t4, ans[1]);
    {
      printf("%lld\n", ans1);
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%lld ", ans[i][j]);
        printf("\n");
      }
    }
  }
}
