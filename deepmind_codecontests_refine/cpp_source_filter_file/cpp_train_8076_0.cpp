#include <bits/stdc++.h>
using namespace std;
int main() {
  double k;
  scanf("%lf", &k);
  double kk = k * k;
  double step = sqrt(3.0);
  double s = 0;
  for (double i = 0.5; i <= k; i += 4.0) {
    double x[4];
    double h;
    if (i * i > kk)
      h = 0;
    else
      h = sqrt(kk - i * i);
    h += step * 0.5;
    h = h / step;
    x[0] = floor(h);
    if ((i + 0.5) * (i + 0.5) > kk)
      h = 0;
    else
      h = sqrt(kk - (i + 0.5) * (i + 0.5));
    h = h / step;
    h = floor(h);
    x[1] = h;
    if ((i + 1.5) * (i + 1.5) > kk)
      h = 0;
    else
      h = sqrt(kk - (i + 1.5) * (i + 1.5));
    h = h / step;
    h = floor(h);
    x[2] = h;
    if ((i + 2.0) * (i + 2.0) > kk)
      h = 0;
    else
      h = sqrt(kk - (i + 2.0) * (i + 2.0));
    h += step * 0.5;
    h = h / step;
    h = floor(h);
    x[3] = h;
    sort(x, x + 4);
    s += x[0];
  }
  double s2 = 0;
  for (double i = 2.0; i <= k; i += 4.0) {
    double x[4];
    double h;
    if (i * i > kk)
      h = 0;
    else
      h = sqrt(kk - i * i);
    h += step;
    h = h / step;
    x[0] = floor(h);
    if ((i + 0.5) * (i + 0.5) > kk)
      h = 0;
    else
      h = sqrt(kk - (i + 0.5) * (i + 0.5));
    h += step * 0.5;
    h = h / step;
    h = floor(h);
    x[1] = h;
    if ((i + 1.5) * (i + 1.5) > kk)
      h = 0;
    else
      h = sqrt(kk - (i + 1.5) * (i + 1.5));
    h += step * 0.5;
    h = h / step;
    h = floor(h);
    x[2] = h;
    if ((i + 2.0) * (i + 2.0) > kk)
      h = 0;
    else
      h = sqrt(kk - (i + 2.0) * (i + 2.0));
    h += step;
    h = h / step;
    h = floor(h);
    x[3] = h;
    sort(x, x + 4);
    if (x[0] > 0) s2 += 2 * x[0] - 1;
  }
  double s3 = 0;
  for (double i = 0.5; i <= 0.5; i += 2.0) {
    double x[4];
    double h;
    if (i * i > kk)
      h = 0;
    else
      h = sqrt(kk - i * i);
    h += step * 0.5;
    h = h / step;
    x[0] = floor(h);
    if ((i + 0.5) * (i + 0.5) > kk)
      h = 0;
    else
      h = sqrt(kk - (i + 0.5) * (i + 0.5));
    h += step;
    h = h / step;
    h = floor(h);
    x[1] = h;
    sort(x, x + 2);
    if (x[0] > 0) s3 += 2 * x[0] - 1;
  }
  printf("%0.0lf", s2 * 2 + s * 4 + s3);
}
