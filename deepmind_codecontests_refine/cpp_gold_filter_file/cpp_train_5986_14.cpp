#include <bits/stdc++.h>
using namespace std;
struct str {
  int x, y;
} dot[210000];
int i, j, k, l, m, n;
double ans, pow_[100];
int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
double cross(str A, str B) {
  double ans = (double)A.x * (double)B.y - (double)A.y * (double)B.x;
  return ans;
}
long long abs_(int a) { return a > 0 ? a : (-a); }
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d %d", &dot[i].x, &dot[i].y), dot[i + n] = dot[i];
  double sall = 0, papa = 0;
  for (i = 1; i <= n; i++) sall += cross(dot[i], dot[i + 1]);
  for (i = 1; i <= n; i++)
    papa += gcd(abs_(dot[i].x - dot[i + 1].x), abs_(dot[i].y - dot[i + 1].y));
  sall /= 2.0;
  sall = sall - papa / 2.0 + 1.0;
  pow_[0] = 1;
  for (i = 1; i <= 100; i++) pow_[i] = pow_[i - 1] * 0.5;
  for (i = 1; i <= n; i++) {
    double js = cross(dot[i], dot[i + 1]);
    double sj = (double)gcd(abs_(dot[i].x - dot[i + 1].x),
                            abs_(dot[i].y - dot[i + 1].y));
    for (j = 2; j <= min(n - 2, 35); j++) {
      js += cross(dot[i + j - 1], dot[i + j]);
      sj += (double)gcd(abs_(dot[i + j - 1].x - dot[i + j].x),
                        abs_(dot[i + j - 1].y - dot[i + j].y));
      double s = cross(dot[i + j], dot[i]) + js;
      s = fabs(s) / 2.0;
      double s_ = sj + (double)gcd(abs_(dot[i + j].x - dot[i].x),
                                   abs_(dot[i + j].y - dot[i].y));
      double nei = s - s_ / 2.0 + 1;
      nei += (double)gcd(abs_(dot[i + j].x - dot[i].x),
                         abs_(dot[i + j].y - dot[i].y));
      nei -= 1;
      if (n <= 60)
        ans += nei * (pow(2, n - j - 1) - 1) /
               (pow(2, n) - 1 - n - n * (n - 1) / 2);
      else
        ans += nei * pow_[j + 1];
    }
  }
  printf("%.10lf", sall - ans);
  return 0;
}
